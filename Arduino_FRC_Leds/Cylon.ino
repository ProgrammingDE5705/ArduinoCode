void fadeall() { 
  for(int i = 0; i < NUM_LEDS; i++) { 
    leds[i].nscale8(250); 
  } 
}

void Cylon(){
  static uint8_t hue = 0;
  
  for(int i = 0; i < NUM_LEDS; i++) {
    // Set the i'th led to red 
    leds[i] = CRGB(0, 255, 0);
    
    FastLED.show(); 
    
    fadeall();
    
    delay(10);
  }
 
  for(int i = (NUM_LEDS)-1; i >= 0; i--) {
    
    leds[i] = CRGB(0, 255, 0); //ROJO en teoria
    
    FastLED.show();
 
    fadeall();

    delay(10);
  }
}
