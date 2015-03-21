unsigned int down[]={7482,8850,-4450,550,-1700,550,-550,500,-600,550,-550,600,-550,500,-600,550,-550,550,-550,500,-650,500,-1700,500,-1700,550,-1700,500,-1700,500,-1700,550,-1700,500,-1700,500,-600,550,-550,600,-550,500,-1700,550,-550,500,-650,500,-1700,500,-600,500,-1700,550,-1700,550,-1650,550,-550,550,-1700,500,-1700,500,-650,500,-1700,500};

#include <IRremote.h>

IRsend irsend;
int SUBIR=5;
int BAJAR=6;

void setup(){
  Serial.begin(9600);
  pinMode(SUBIR,INPUT);
  pinMode(BAJAR,INPUT);
}

void loop(){
  int subir=digitalRead(SUBIR);
  int bajar=digitalRead(BAJAR);
  
  if(subir == HIGH)
  {
    irsend.sendNEC(0x807F22DD,32);
    Serial.println("Send NEC");
    delay(100);
  }else if(bajar == HIGH){
    //irsend.sendRaw(down,16,2);
    irsend.sendNEC(0x807F12ED,32);
    Serial.println("Send JVC");
    delay(100);
  }
}
