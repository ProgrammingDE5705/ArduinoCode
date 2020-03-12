#include <FastLED.h>
#include <Wire.h>  

byte rec = 0;
//byte cer = rec;

#define DATA_PIN 6
#define NUM_LEDS 100

CRGB leds[NUM_LEDS];

void setup() {
  Wire.begin(0xF5);    //Asignamos la direccion 0xF5 al arduino en el bus I2C
  Wire.onReceive(receiveEvent); //Metodo a llamar cuando lleguen datos por el bus

  Serial.begin(9600);
  
  LEDS.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);;
  LEDS.setBrightness(84);

}

void loop() {
  switch (rec) {
    case (byte)0 :
       Rainbow();
      break;
    case (byte)1 :

      break;
    case (byte)2 :

      break;
    case (byte)3 :

      break;
    case (byte)4 :

      break;
    case (byte)5 :

      break;
    case (byte)6 :

      break;
    case (byte)7 :

      break;
    case (byte)8 :

      break;
    case (byte)9 :
      Cylon(); //Badass Mode
      break;  
    default :
     Cylon();
  }
}



void receiveEvent(int howMany){
  while ( Wire.available() > 0){ // Leemos todo el buffer
    rec = Wire.read(); // almacenamos el byte
    Serial.print((byte)rec);         // Lo mostramos por pantalla
  }
  Serial.println();
}
