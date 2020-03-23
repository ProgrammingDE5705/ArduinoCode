#include <FastLED.h>
#include <Wire.h>  

byte rec = 0;
//byte cer = rec;

#define DATA_PIN 6
#define NUM_LEDS 100 //100 pixeles en total por toda la tira de 5m, 300 les en total, 60 leds por metro, 20 pixeles por metro, 

#define DATA_PIN_S 7
#define NUM_LEDS_S 10

CRGB leds[NUM_LEDS];
CRGB leds_S[NUM_LEDS_S];

void setup() {
  Wire.begin(0xF5);    //Asignamos la direccion 0xF5 al arduino en el bus I2C
  Wire.onReceive(receiveEvent); //Metodo a llamar cuando lleguen datos por el bus

  Serial.begin(9600);
  
  LEDS.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);;
  LEDS.setBrightness(200);

  LEDS.addLeds<WS2811, DATA_PIN_S, RGB>(leds_S, NUM_LEDS_S).setCorrection(TypicalLEDStrip);;
  LEDS.setBrightness(84);

}

void loop() {
  switch (rec) {
    case (byte)0 : // Robot Disable
       Rainbow();
      break;
    case (byte)1 :
      Sequence();
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
    case (byte)9 : // Badass Mode
      Cylon(); 
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
