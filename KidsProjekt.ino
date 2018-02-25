// Laden des Programms um das LED zu steuern
#include "ChainableLED.h"
// Defintion der Konstanten NUM_LEDS?
#define NUM_LEDS 1


// An welchen Steckplatz ist das LED angeschlossen und
// wieviele LED sind angeschlossen?
ChainableLED leds(8, 9, NUM_LEDS);
// Wo ist der Taster angeschlossen?
const int buttonPin = 2;


int tasterGedrueckt = 0; // 0 = nein, 1 = ja
int letzterLoopTasterGedrueckt = 0;
boolean an = false;


void setup()
{
  // Bevor man das LED benutzen kann muss es initialisiert werden
  // dazu wird eine Funktion aus dem Programm welches am Anfang
  // geladen wurde aufgerufen.
  leds.init();
}

void loop() {
  // Lesen ob taster jetzt gedrückt ist 
  tasterGedrueckt = digitalRead(buttonPin); // 0 Taster nicht gedrückt; 1 Taster gedrückt
  if ( tasterGedrueckt != letzterLoopTasterGedrueckt ) { // wenn taster nicht den gleichen Zustand hat wie letzten loop
    if ( tasterGedrueckt == 1 ) {
      an = true; // true heisst wahr. Also an = wahr
    }
    if ( tasterGedrueckt == 0 ) {
      an = false; // false heisst falsch. Also an = false
    }
  }


  if ( an ) {
    //  leds.setColorRGB(0, rot, grün, blau);
    leds.setColorRGB(0, 0, 0, 255);
    delay(100);
    leds.setColorRGB(0, 255, 0, 0);
    delay(100);
    leds.setColorRGB(0, 255, 215, 0);
    delay(100);
    leds.setColorRGB(0, 0, 255, 0);
    delay(100); 
  }
  else {
    leds.setColorRGB(0, 0, 0, 0);
  }
  
  letzterLoopTasterGedrueckt = tasterGedrueckt;
}

