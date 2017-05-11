#include <Adafruit_GFX.h>
#include <TouchScreen.h>
#include <Adafruit_TFTLCD.h>

#define YP A3  
#define XM A2  
#define YM 9   
#define XP 8   

#define TS_MINX 225
#define TS_MINY 195
#define TS_MAXX 920
#define TS_MAXY 905

#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
#define LCD_RESET A4

#define BLACK   0x0000
#define WHITE   0xFFFF

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

void setup() {
  Serial.begin(9600);
  pinMode(10, OUTPUT); //Digitaalviik 10 seadistamine väljundiks
  digitalWrite(10, HIGH); //Digitaalviigu 10 5V tugevuseks määramine
  tft.reset(); //Lähtestatakse ekraan
  uint16_t identifier = tft.readID(); //Ekraani identifikaatori lugemine
  tft.begin(identifier); //Ekraaniga ühenduse loomine
  tft.fillScreen(BLACK); //Ekraani tausta mustaks värvimine
  tft.setTextColor(WHITE);//Tekstivärvi valgeks seadmine
  tft.setCursor(60,100);//Teksti alguspunkti määramine ekraanil
  tft.setTextSize(2);//Tekstisuuruse määramine
  tft.print("Tere maailm!");//Teksti kirjutamine ekraanile
  Serial.print("ID = ");
  Serial.print(tft.readID());
}
void loop() {
  TSPoint t = ts.getPoint();//Puutepunktide kogumine. Punkti p on salvestatud pikkuse, laiuse ja kõrguse koordinaat
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
  if (t.z > ts.pressureThreshhold) { //Kontrollitakse, kas kõrguse koordinaadi muutus on toimunud piisavas suuruses,et tegemist oleks puudutusega.
    tft.setCursor(60,150);
    tft.print("Puudutus");
    Serial.print("X= ");
    Serial.println(p.x);
    Serial.print("Y= ");
    Serial.println(p.y);
    Serial.println(" ");
  }

}
