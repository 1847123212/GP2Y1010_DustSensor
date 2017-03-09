/*
  GP2Y1010_DustSensor.cpp - SHARP GP2Y1010AU0F Dust sensor library for ESP-WROOM-02 ( esp8266 ) or Arduino
  version 0.2
  
  License MIT
*/

#include "GP2Y1010_DustSensor.h"
#include "Arduino.h"

// public

GP2Y1010_DustSensor::GP2Y1010_DustSensor(){
}

GP2Y1010_DustSensor::GP2Y1010_DustSensor(int ledPin, int measurePin){
	begin(ledPin,measurePin);

}

GP2Y1010_DustSensor::~GP2Y1010_DustSensor(){
}

void GP2Y1010_DustSensor::begin(int ledPin, int measurePin){
	led_pin = ledPin;
	measure_pin = measurePin;
	pinMode(led_pin, OUTPUT);
}

float GP2Y1010_DustSensor::getDustDensity() {

	digitalWrite(led_pin, LOW);
	delayMicroseconds(SAMPLINGTIME);

	float mesured = analogRead(measure_pin);	//read analog pin / Dust value
	delayMicroseconds(DELTATIME);

	digitalWrite(led_pin, HIGH);
	delayMicroseconds(SLEEPTIME);

	// culc dust density
	float dust = (0.17 * (mesured * (5.0 / 1024.0)) - 0.1) * 1000.;
	
	dustDensityHistory.push_front(dust);
	while( dustDensityHistory.size() > dustDensityHistoryMaxSize ) {
		dustDensityHistory.pop_back();
	}
	
	return dustDensityHistory.front();
}

float GP2Y1010_DustSensor::getDustDensityAvg() {
	getDustDensity();
	float	avg = 0.;
	for(auto itr = dustDensityHistory.begin(); itr != dustDensityHistory.end(); ++itr) {
		avg += *itr;
	}
	return avg / dustDensityHistory.size();
}

void GP2Y1010_DustSensor::setDustDensityHistoryMaxSize(int max) {
	dustDensityHistoryMaxSize = max;
}
