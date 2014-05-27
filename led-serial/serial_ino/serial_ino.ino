int ledPin=13;
int serialPin=8;
int val=0;
char readed;

void setup(){
  pinMode(ledPin,OUTPUT);
  pinMode(serialPin,OUTPUT);
  Serial.begin(96000);
}
void loop(){
  if(Serial.available() > 0)
  {
    readed=Serial.read();
    val=readed-'0';
  }
  if(val>0)
  {
   digitalWrite(ledPin,HIGH);
   delay(1000);
   digitalWrite(ledPin,LOW);
   delay(1000); 
  }
  /*if(Serial.available() > 0)
  {
    digitalWrite(serialPin,LOW);
    readed=Serial.read();
    int val=readed-'0';
    if( val > '0' && val<= '9')
    {
      for(int i=0; i<val; i++)
      {
       digitalWrite(ledPin,HIGH);
       delay(500);
       digitalWrite(ledPin,LOW);
       delay(500); 
      }
    }
  }else{
    digitalWrite(serialPin,HIGH);
  }*/
}
