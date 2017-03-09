# GP2Y1010_DustSensor  
Arduino IDE library for operating SHARP GP2Y1010AU0F dust sensor in ESP-WROOM-02(esp8266) or Arduino  
version 0.2

# Credits and license  
License MIT

# How to use

* Include this library to your Arduino IDE.
* Wiring GP2Y1010AU0F sensor to your Arduino or ESP-WROOM-02.

    From left wire,  
    GP2Y1010AU0F blue wire   -> Arduino Vout(5V) via 150 ohm register, and Arduino GND via 220uF Capacitor  
    GP2Y1010AU0F green wire  -> Arduino GND  
    GP2Y1010AU0F white wire  -> Arduino Digital pin  
    GP2Y1010AU0F yellow wire -> Arduino GND  
    GP2Y1010AU0F black wire  -> Arduino Analog pin (if you use ESP-WROOM-02(esp8266), show below warning.)  
    GP2Y1010AU0F red wire    -> Arduino Vout(5V)  

    warning: ESP-WROOM-02(esp8266) analog(TOUT) pin stand under 1V , you must make 5V fall to 1V using a voltage divider.

* Read sample source code. It's very simple !

# caution

* this library is testing only ESP-WROOM-02(esp8266) boards. if you can't execute this library on your arduino (or clone) boards, please contact me.


# GP2Y1010_DustSensor library function

## Constractor

* GP2Y1010_DustSensor  
  normal constractor. if you use this constractor, you must execute begin() function after this constractor execute.

* GP2Y1010_DustSensor(int ledPin, int measurePin)  
  setting pins, and initialize sensor.  
    ledPin: set white wire digital pin no.  
    measurePin: set black wire analog pin no.  

## public function

* void begin(int ledPin, int measurePin)  
  setting pins, and initialize sensor.  
    ledPin: set white wire digital pin no.  
    measurePin: set black wire analog pin no.  
  
* float getDustDensity()  
  get dust density (the unit is ug/m3)

* float getDustDensityAvg()  
  get dust density, Last 5 times average (the unit is ug/m3)

* float getDustDensityAvg()  
  get dust density, Last below "max" times average (the unit is ug/m3)

* void setDustDensityHistoryMaxSize(int max)  
  set average history max size.  
  default value is 5.

# link
* GP2Y1010AU0F Data sheet  
  http://www.sharp-world.com/products/device-china/lineup/data/pdf/datasheet/gp2y1010au_e.pdf (English)  
  http://www.sharp.co.jp/products/device/doc/opto/gp2y1010au_j.pdf (Japanese)

* GP2Y1010AU0F Application note  
  http://www.sharp-world.com/products/device-china/lineup/data/pdf/datasheet/gp2y1010au_appl_e.pdf (English)  
  http://www.sharp.co.jp/products/device/doc/opto/gp2y1010au_appl_j.pdf (Japanese)

