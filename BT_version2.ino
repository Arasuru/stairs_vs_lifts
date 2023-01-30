#include "BluetoothSerial.h"

#define RXp2 16
#define TXp2 17

int output = 0;
BluetoothSerial ESP_BT;

void setup() {
  Serial.begin(115200); //Start Serial monitor in 115200
  Serial2.begin(9600, SERIAL_8N1, RXp2, TXp2);
  ESP_BT.begin("stairs_vs_lifts"); //Name of your Bluetooth Signal
  Serial.println("Bluetooth Device is Ready to Pair");
}

void loop(){
  if(ESP_BT.available() > 0){
      //Serial.println("ESP_DATA:");
      //Serial.println(ESP_BT.read());
      ESP_BT.read();
      Serial2.println(1);
      delay(200);
      output = Serial2.read();
      ESP_BT.println(output - 48);
      //Serial.println("---------------------");
      Serial.println(output);
      Serial2.flush();
  }
   // if (Serial2.available()){ //Check if we receive anything from Bluetooth{
      //Serial2.read() - 48;
      
   // }
}
