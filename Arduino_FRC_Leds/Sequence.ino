int dilai = 155;

void Sequence(){
  for(int i = -1; i < NUM_LEDS_S; i++) { 
    //FastLED.setPixelColor(i, 0, 255, 0);
    shoot[i] = CRGB(0, 255, 0);
    FastLED.show();
    delay(dilai);
  } 
  
  for(int i = 0; i < NUM_LEDS_S; i++) { 
    shoot[i] = CRGB(0, 0, 0);
  } 
  FastLED.show();
}
