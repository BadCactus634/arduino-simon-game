# 🇬🇧 Arduino Simon Game

![download](https://github.com/BadCactus634/arduino-simon-game/assets/68558172/6eca333d-fccf-4525-a801-eb02e43261e2)

Let's recreate the good-old Simon game with Arduino!

If you look at the code (which you can find in the above file list) you will see an array that stores the correct (random) sequence which has been picked up at start.
Additional numbers will be added based on the level number you are at: the first level has only 4 numbers (you can call them "extraction" if you wish), second one has 6 and third has 8 numbers.
Every number refer to the pin number of one of the colored LEDs.
There's also a buzzer that plays a specific tone for every color, a tone error when the player push the wrong button in the input sequence, and a victory tone in case of... well, victory! This tone is played when you reach and finish the third level.

The file comments are in italian but a version with english text is on the way. 


# 🇮🇹 Ricreiamo il vecchio gioco Simon con Arduino!

C'è un array che tiene in memoria la sequenza corretta, alla quale vengono aggiunte due nuove estrazioni ogni volta che si sale di livello.
Ci sono 3 livelli con estrazioni crescenti: il primo ne ha 4, il secondo 6 e il terzo 8.
Un buzzer riproduce un tono specifico per ogni LED, un tono di errore in caso si sbagli a inserire la sequenza con i pulsanti e un tono di vittoria in caso di superamento di tutti e 3 i livelli.

Potete trovare il codice sopra nei file, è anche commentato.

[WIP - PHOTOs]
