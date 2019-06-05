#include "U8glib.h"
int valor;

U8GLIB_SH1106_128X64 u8g(13, 11, 10, 9, 8);  // D0=13, D1=11, CS=10, DC=9, Reset=8


void draw(void) {
  u8g.setFont(u8g_font_unifont);  // select font
  u8g.drawStr(0, 12, "Monoxido de "); // Print title
  u8g.drawStr(0, 25, "Carbono ");  // Print title
  u8g.drawStr(0, 60, "(CO): ");  // put string of display at position X, Y
  u8g.setPrintPos(44, 30);  // set position
  u8g.drawStr(90, 60, "PPM"); // print units
  u8g.setPrintPos(50, 60); / set result position
  u8g.print(valor);
}


void setup(void) {
}
void loop(void) {
valor = analogRead(A0);
  
  u8g.firstPage();  
  do {
    draw();
  } while( u8g.nextPage() );
  
   delay(500);  // Delay of 0.5 sec before accessing MQ-7 
}
