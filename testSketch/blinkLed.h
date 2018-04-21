static byte bLed = 0xFF;  // oll off 

#include <Wire.h>
static byte AN  = 0x00;		    // 0 on
static byte AUS = 0xFF; 		// 1 off
	        //	   |||||||^  --- Pin0 LEDRotBig
	        //	   ||||||^   --- Pin1 LEDRot1
        	//	   |||||^    --- Pin2 LEDRot2
	        //	   ||||^     --- Pin3 LEDBlau 
	        //	   |||^      --- Pin4 LEDGruenBig 
	        //	   ||^       --- Pin5 LEDGruen2 
	        //	   |^        --- Pin6 LEDGruen1
	        //	   ^         --- Pin7 LEDOrange
static const int LEDBlau = 3;
static const int LEDOrange = 7;
static const int LEDGruenBig = 4;
static const int LEDRotBig = 0;
static const int LEDRot1 = 1;
static const int LEDRot2 = 2;
static const int LEDGruen1 = 6;
static const int LEDGruen2 = 5;

//alle an / AUS
    void allLeds(bool trigger, byte PCFAdress){
        if(trigger == false){
            Wire.beginTransmission(PCFAdress); 
            Wire.write(0xFF); 
            Serial.print("All Leds Turned OFF @ ");
            Serial.println(PCFAdress);
            Wire.endTransmission();
        }else if(trigger){
            Wire.beginTransmission(PCFAdress); 
            Wire.write(0x00); 
            Serial.print("All Leds Turned ON @ ");
            Serial.println(PCFAdress);
            Wire.endTransmission();
        }
    }
//LED ON
    static void LedOn(int pos, byte PCFAdress){
        bLed = bLed & ~(1 << pos);
        Wire.beginTransmission(PCFAdress); 
        Wire.write(bLed); 
        Serial.print("Turn led ");
        Serial.print(pos);
        Serial.print(" on @ ");
        Serial.println(PCFAdress);
        Wire.endTransmission();
    }
//LED OFF
    static void LedOff(int pos, byte PCFAdress){
        bLed = bLed | (1 << pos);
        Wire.beginTransmission(PCFAdress); 
        Wire.write(bLed); 
        Serial.print("Turn led ");
        Serial.print(pos);
        Serial.print(" off @ ");
        Serial.println(PCFAdress);
        Wire.endTransmission();
    }
void printUpway(long text, int timeDelay){
    Serial.println(text);
    delay(timeDelay);
}