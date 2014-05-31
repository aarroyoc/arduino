/* Tragaperras */

int salidas[]={12, 11, 10, 9, 8, 7, 6};
int correcto=4;
int fallo=5;
int boton=3;
int contador=0;

int pedido=5;
int stopDisplay=0;

void displayNumber(int number)
{
  for(int i=0;i<7;i++)
    digitalWrite(salidas[i],LOW);
  if(number==2 || number==3 || number==4 || number==5 || number==6 || number==8 || number==9)
    digitalWrite(salidas[0],HIGH);
  if(number==0 || number==4 || number==5 || number==6 || number==8 || number==9)
    digitalWrite(salidas[1],HIGH);
  if(number==0 || number==2 || number==3 || number==5 || number==6 || number==7 || number==8 || number==9)
    digitalWrite(salidas[2],HIGH);
  if(number==0 || number==1 || number==2 || number==3 || number==4 || number==7 || number==8 || number==9)
    digitalWrite(salidas[3],HIGH);
  if(number==0 || number==2 || number==6 || number==8)
    digitalWrite(salidas[4],HIGH);
  if(number==0 || number==2 || number==3 || number==5 || number==6 || number==8)
    digitalWrite(salidas[5],HIGH);
  if(number!=2)
    digitalWrite(salidas[6],HIGH);
}

void setup()
{
 for(int i=0;i<7;i++)
  pinMode(salidas[i],OUTPUT);
 pinMode(correcto,OUTPUT);
 pinMode(fallo,OUTPUT);
 pinMode(boton,INPUT);
 randomSeed(analogRead(0));
 pedido=random(0,10);
 displayNumber(pedido);
 delay(1000);
}
void loop()
{
  if(stopDisplay==0)
  {
    displayNumber(contador);
    int currentTime=millis();
    int nowTime=millis();
    do{
      int input=digitalRead(boton);
      if(input>0)
      {
        if(pedido==contador)
          digitalWrite(correcto,HIGH);
        else
          digitalWrite(fallo, HIGH);
        
        stopDisplay=1;
      }
      nowTime=millis();
    }while((nowTime-currentTime)<250);
    contador++;
    if(contador==10)
      contador=0;

  }
}
