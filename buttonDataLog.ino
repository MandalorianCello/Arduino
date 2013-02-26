/*
*Incriments a counter when a button attached to pin 3 is pressed.
*Counter is stored in a .txt file on SD card and displayed
*on the serial monitor.
*/

#include <SD.h>
void setup()
{
  Serial.begin(9600);
  while(!Serial) {;}
  pinMode(3, INPUT); //pin to button
  pinMode(10,OUTPUT); //required for SD sheild
  pinMode(7,OUTPUT); //pin to LED
  Serial.print("Starting SD card... ");
  if(!SD.begin()) //Test to see if SD card exists
  {
    Serial.println("ERROR");
    return;
  }
  Serial.println("Done");
}

int count = 0; //stores counts

void loop()
{
  digitalWrite(7,LOW);
  if(digitalRead(3)==LOW)
  {
    count++;
    SD.begin();
    File f = SD.open("Test.txt",FILE_WRITE);
    f.println(count);
    f.close();
    digitalWrite(7,HIGH);
    Serial.println(count);
    delay(1000);
  }
}
