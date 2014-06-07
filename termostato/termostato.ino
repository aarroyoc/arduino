#include <LiquidCrystal.h>

float tempC;
int tempPin = A5; // Definimos la entrada en pin A0

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

byte celsius[8] = { B11000, B11000, B00111, B01000, B01000, B01000, B01000, B00111 };

void setup()
{
    // Abre puerto serial y lo configura a 9600 bps
    Serial.begin(9600);
    lcd.createChar(0,celsius);
    lcd.begin(16,2);
    lcd.print("Termostato LM35");
}
void loop()
{
    // Lee el valor desde el sensor
    tempC = analogRead(tempPin); 

    // Convierte el valor a temperatura
    tempC = (5.0 * tempC * 100.0)/1024.0; 

    // Envia el dato al puerto serial
    Serial.print(tempC);
    Serial.print(" grados Celsius\n");
    
    lcd.setCursor(0,1);
    lcd.print(tempC);
    lcd.print(" ");
    lcd.write(byte(0));

    // Espera cinco segundo para repetir el loop
    delay(5000);
}
