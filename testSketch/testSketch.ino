#include "blinkLed.h"
#include <startup.h>
static byte PCF857X = 0x20;  	    // Adresse des PCF8574 hier: PCF8574P mit allen 3 Adress-Pins nach Masse
void setup(){
    start();
    allLeds(true,PCF857X);
    delay(1000);
    allLeds(false,PCF857X);
}
//int test = Randomenumber;
void loop () {
    
    //printUpway(test,500);
    //test++;
    LedOn(LEDBlau,PCF857X);
    delay(500);
    LedOff(LEDBlau,PCF857X);
    delay(500);
}

