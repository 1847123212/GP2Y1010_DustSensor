/*
  GP2Y1010_DustSensor.h - SHARP GP2Y1010AU0F Dust sensor library for ESP-WROOM-02 ( esp8266 ) or Arduino
  version 0.2
  
  License MIT
*/

#ifndef GP2Y1010_DustSensor_h_
#define GP2Y1010_DustSensor_h_

#include "Arduino.h"
#include <list>

class GP2Y1010_DustSensor
{
public:
	GP2Y1010_DustSensor();
	GP2Y1010_DustSensor(int ledPin, int measurePin);

	~GP2Y1010_DustSensor();

	void begin(int ledPin, int measurePin);
	
	float getDustDensity();
	float getDustDensityAvg();

	void setDustDensityHistoryMaxSize(int max);

protected:

private:

	int dustDensityHistoryMaxSize = 5;

	int led_pin = 2 , measure_pin = A0;
	std::list<float> dustDensityHistory;

	static const int SAMPLINGTIME = 280;
	static const int DELTATIME = 40;
	static const int SLEEPTIME = 9680;

};

#endif
