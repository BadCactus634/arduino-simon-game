// Dichiarazioni variabili
int buzzer=3; // Pin buzzer
int pin; // Variabile di supporto per la generazione della sequenza random
int livello=1;
int estrazioni;
int inserimento;
int estr_old;
int sequenza[8]; // L'array che terrà in memoria la sequenza generata

void setup() {
  Serial.begin(9600); // Inizializza la comunicazione seriale di debug
  randomSeed(analogRead(A0)); // Inizializza il seme per la generazione della sequenza random
  // Pin di output
  pinMode(buzzer, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  // Pin di input (pulsanti)
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
}

void loop() {
 if(livello==1 || livello==2 || livello==3){ // Esegui il gioco solo se si è in uno dei 3 livelli
  inserimento=0; // Variabile temporanea di supporto per l'inserimento che useremo dopo
  
  // Controllo numero di estrazioni basaste sul livello
  if(livello==1)
    estrazioni=4;
  else if(livello==2)
    estrazioni=6;
  else
    estrazioni=8;

  if(livello==1){ // Se siamo nel primo livello estraiamo 4 numeri
  for(estr_old=0;estr_old<estrazioni;estr_old++){
    pin=random(4, 8); // Genera un numero random compreso fra 4 e 7 (l'8 non si conta)
    Serial.println(pin);
    sequenza[estr_old]=pin; // Memorizza il numero alla posizione corrente
    digitalWrite(pin, HIGH); // Accendi il LED corrispondente
    // Riproduci un tono a seconda del LED estratto
    switch(pin){
      case 4:
        tone(buzzer, 1500);
        break;
      case 5:
        tone(buzzer, 500);
        break;
      case 6:
        tone(buzzer, 1000);
        break;
      case 7:
        tone(buzzer, 2000);
        break;   
    }
    delay(1000);
    digitalWrite(pin, LOW);
    noTone(buzzer);
    delay(500);
  }
  }else{ // Se il livello è diverso da 1 (2 o 3)
    Serial.println("Vecchia sequenza:");
    // Leggi l'array con i valori memorizzati dalla precedente estrazione
    for(int i=0;i<estr_old;i++){
    Serial.println(sequenza[i]);
    digitalWrite(sequenza[i], HIGH);
    switch(sequenza[i]){
      case 4:
        tone(buzzer, 1500);
        break;
      case 5:
        tone(buzzer, 500);
        break;
      case 6:
        tone(buzzer, 1000);
        break;
      case 7:
        tone(buzzer, 2000);
        break;   
    }
    delay(1000);
    digitalWrite(sequenza[i], LOW);
    noTone(buzzer);
    delay(500);
    }
    // Ora estrai i due numeri nuovi e stampali
    Serial.println("Nuova estrazione:");
    for(estr_old;estr_old<estrazioni;estr_old++){
    pin=random(4, 8);
    Serial.println(pin);
    sequenza[estr_old]=pin;
    digitalWrite(pin, HIGH);
    switch(pin){
      case 4:
        tone(buzzer, 1500);
        break;
      case 5:
        tone(buzzer, 500);
        break;
      case 6:
        tone(buzzer, 1000);
        break;
      case 7:
        tone(buzzer, 2000);
        break;   
    }
    delay(1000);
    digitalWrite(pin, LOW);
    noTone(buzzer);
    delay(500);
  }
  }

  Serial.println("------- INIZIO INSERIMENTO -------");

  while(inserimento<estrazioni){
    if(digitalRead(12)==HIGH && sequenza[inserimento]==6){ // Verde
      Serial.println("Pulsante verde premuto");
      // Fai suonare il buzzer e accendere il LED corrispondente
      tone(buzzer, 1000);
      digitalWrite(6, HIGH);
      inserimento++;
      delay(700);
      noTone(buzzer);
      digitalWrite(6, LOW);
    }
    else if(digitalRead(11)==HIGH && sequenza[inserimento]==5){ // Rosso
      Serial.println("Pulsante rosso premuto");
      tone(buzzer, 500);
      digitalWrite(5, HIGH);
      inserimento++;
      delay(700);
      noTone(buzzer);
      digitalWrite(5, LOW);
    }
    else if(digitalRead(10)==HIGH && sequenza[inserimento]==7){ // Blu
      Serial.println("Pulsante blu premuto");
      tone(buzzer, 2000);
      digitalWrite(7, HIGH);
      inserimento++;
      delay(700);
      noTone(buzzer);
      digitalWrite(7, LOW);
    }
    else if(digitalRead(9)==HIGH && sequenza[inserimento]==4){ // Giallo
      Serial.println("Pulsante giallo premuto");
      tone(buzzer, 1500);
      digitalWrite(4, HIGH);
      inserimento++;
      delay(700);
      noTone(buzzer);
      digitalWrite(4, LOW);
    }else if(digitalRead(12)==HIGH || digitalRead(11)==HIGH || digitalRead(10)==HIGH || digitalRead(9)==HIGH){
      // Se un tasto è premuto ma non corrisponde alla sequenza memorizzata riproduci un suono di errore
      Serial.println("PULSANTE ERRATO!");
      tone(buzzer, 300);
      delay(200);
      noTone(buzzer);
      delay(200);
      tone(buzzer, 300);
      delay(200);
      noTone(buzzer);
      inserimento=20;
    }
    
    delay(10);
  }
  }
  
  if(inserimento==estrazioni){
    if(livello<3){
      // Sali di livello
      livello++;
      Serial.println("------- RAGGIUNTO NUOVO LIVELLO -------");
    }else if(livello==3){
      Serial.println("------- HAI VINTO! -------");
      // Lucine magiche
      for(int i=0;i<6;i++){
        for(int j=4;j<8;j++){
          digitalWrite(j, HIGH);
          tone(buzzer, 2700);
          delay(70);
          digitalWrite(j, LOW);
          noTone(buzzer);
        }
      }
      // Aumenta il livello oltre al 3 in modo da non rieseguire il gioco
      livello++;
    }
  }else if(inserimento==20){
    Serial.println("Ricomincia dall'inizio");
    // Resetta il livello a 1
    livello=1;
  }
  delay(2000);

}
