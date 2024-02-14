  import processing.serial.*;

Serial port;
boolean lRosso=false, lVerde=false,lBlu=false, lGiallo=false, flag=false;
int inizio=0, inizio2=0, corrente=0, corrente2=0;
char ricevuto, tempor;
boolean flag2=false;
PFont font, font1;
PImage img;

void setup(){
 size(800,800   );
 //printArray(Serial.list());
 port = new Serial(this, Serial.list()[0], 9600);
 font = createFont("Arial black", 30); // font delle scritte
 font1 = createFont("Arial black", 10); // font delle scritte
// port.clear();
// port.bufferUntil ( '\n' );
 inizio=millis();
 img = loadImage("download.jpg");
}

// LEGENDA SERIAL
// 1=Giallo
// 2=Rosso
// 3=Verde
// 4=Blu
// Se ricevi uno di questi, colora il pulsante.
// Se mouse premuto allora invia uno di questi e colora il pulsante.

void draw(){
  background(255);
  fill(0);
  ellipse(400, 400, 665, 665);
  
  if (port.available() > 0) {  // If data is available,
    tempor = port.readChar();
    if(tempor!='\n' && tempor!='0' && tempor>=49 && tempor<=57)
    ricevuto = tempor;
  }

  print(ricevuto);
    
  if(mousePressed)
    controllo();
  ledRosso();
  ledBlu();
  ledVerde();
  ledGiallo();
  //ricevuto='0';
  if(flag2==true){
    corrente2=millis();
    if(corrente2-inizio2>=700){
     lRosso=false;
     lBlu=false;
     lVerde=false;
     lGiallo=false;
     inizio2=millis();
     ricevuto='0';
     flag2=false;
    }
  }
  //Disegno
  fill(0);
  noStroke();
  ellipse(400, 400, 230, 230);
  rect(390, 100, 30, 600);
  rect(100, 390, 600, 30);
  fill(255);
  textFont(font);
  text("4ªTA", 365, 350);
  textFont(font1);
  text("Tommaso Lanzara", 325, 450);
  text("Stefano Rossi", 385, 470);
  image(img, 300, 370, width/4, height/14);
  }


void controllo(){
   corrente=millis();
   if(corrente-inizio>=200){
      // Spicchio giallo
      if(mouseX>width/2 && mouseY<height/2){
         port.write('1');
         println("1");
         lGiallo=!lGiallo;
      }
      // Spicchio rosso
      if(mouseX>width/2 && mouseY>height/2){
         port.write('2');
         lRosso=!lRosso;
         println("2");
      }
      // Spicchio verde
      if(mouseX<width/2 && mouseY<height/2){
         port.write('3');
         lVerde=!lVerde;
         println("3");
      }
      // Spicchio blu
     if(mouseX<width/2 && mouseY>height/2){
         port.write('4');
         lBlu=!lBlu;
         println("4");
      }
     
   inizio=millis();
   }
}


void ledRosso(){
  if(lRosso || ricevuto=='2'){
  if(flag2==false){
  inizio2=millis();
  flag2=true;
  }
  fill(230, 0, 0, 200); // Colore premuto
  }else{
     fill(255, 0, 0, 80); // Standby
  }
  // Disegno
  stroke (50);
  arc(400, 400, 600, 600, radians(0), radians(90), PIE);
}

void ledBlu(){
  if(lBlu || ricevuto=='4'){
  if(flag2==false){
  inizio2=millis();
  flag2=true;
  }
    fill(0, 0, 230, 200); // Colore premuto
  }else{
   fill(0, 0, 255, 80); // Standby
  }
  // Disegno
  stroke (50);
  arc(400, 400, 600, 600, radians(90), radians(180), PIE);
}

void ledVerde(){
  if(lVerde || ricevuto=='3'){
    if(flag2==false){
  inizio2=millis();
  flag2=true;
  }
  fill(0, 230, 0, 200); // Colore premuto
  }else{
   fill(0, 255, 0, 80); // Standby
  }
  // Disegno
  stroke (50);
  arc(400, 400, 600, 600, radians(180), radians(270), PIE);
}

void ledGiallo(){
  if(lGiallo || ricevuto=='1'){
    if(flag2==false){
  inizio2=millis();
  flag2=true;
  }
  fill(230, 230, 0, 200); // Colore premuto
  }else{
   fill(255, 255, 0, 80); // Standby
  }
  // Disegno
  stroke (50);
  arc(400, 400, 600, 600, radians(270), radians(360), PIE);
}
