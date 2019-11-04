#include <Adafruit_NeoPixel.h>
#define NUMPIXELS 3
#define led  2   //D4
Adafruit_NeoPixel pixels(NUMPIXELS, led, NEO_GRB + NEO_KHZ800);

void init_neo_pixel() {
  /*ws2812 initialisatie*/
  Serial.println("WS2812 setup");
  pixels.begin(); // INITIALIZE NeoPixel strip object
  pixels.clear();
  pixels.setPixelColor(1, pixels.Color(10, 10, 15));//blauw groen
  pixels.show();
}

void setled(int led_num, int R, int G, int B){
pixels.setPixelColor(led_num, pixels.Color(R, G, B));
    pixels.show();
}
void blink_simpel(int led_num, int aantal, int interval, int R, int G, int B) {

  for (int i = 0; i < aantal; i++) {
    pixels.setPixelColor(led_num, pixels.Color(R, G, B));//blauw
    pixels.show();
    delay(interval); // tijd op op update te drukken
    pixels.setPixelColor(led_num, pixels.Color(0, 0, 0));//red
    pixels.show();
    delay(interval);
  }
}

void allemaal( int RR0, int GG0, int BB0,int RR1, int GG1, int BB1,int RR2, int GG2, int BB2) {
    pixels.setPixelColor(0, pixels.Color(RR0, GG0, BB0));
   
    pixels.setPixelColor(1, pixels.Color(RR1,GG1, BB1));
    pixels.setPixelColor(2, pixels.Color(RR2, GG2, BB2));
     pixels.show();
  }

  void res_stuur(int led_num, boolean result) {
    if(result = true) {
    pixels.setPixelColor(led_num, pixels.Color(0, 200, 0));//groen
    pixels.show();
    delay(200); 
    pixels.setPixelColor(led_num, pixels.Color(0, 0, 0));//red
    pixels.show();   
  } 
  else {
pixels.setPixelColor(led_num, pixels.Color(200, 0, 0));//groen
    pixels.show();
    delay(2000); 
    pixels.setPixelColor(led_num, pixels.Color(0, 0, 0));//red
    pixels.show(); 
  }
  }
