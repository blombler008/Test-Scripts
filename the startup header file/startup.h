#include <Wire.h>
void start() {
	Wire.begin();
	Serial.begin(9600);
}