#include <i2cmaster.h>


int data, data2, a=0, c=5, x=0, z=10000, z1=1000, y, y1;


void setup()
{ 
  i2c_init();                     //I2C init
  Serial.begin(38400);
  Serial.println(" Test Baca Sensor...");        //send data to Serial
  Serial.println("CLEARDATA");            // Reset da comunicação serial
  Serial.println("LABEL,Time,CO Value (ppm),CO2 Value (ppm)");
}

void loop()
{ 
  i2c_start(0xE0); // Alamat I2C modul gas Sensor A
  i2c_write(0x41);
  i2c_stop(); 
  delay(10); 
  i2c_start(0xE1);
  data = (int) i2c_readAck();
  data = data*255 + i2c_readNak();
  i2c_stop(); 

  delay(21); 

  i2c_start(0xE2); // Alamat I2C modul gas Sensor B
  i2c_write(0x41);
  i2c_stop(); 
  delay(10); 
  i2c_start(0xE3);
  data2 = (int) i2c_readAck();
  data2 = data2*255 + i2c_readNak();
  i2c_stop(); 
  

  
  Serial.print("Gas Sensor A (Data) : ");
  Serial.println(data2, DEC);              //send data gas sensor A to Serial
  Serial.print("Gas Sensor B (Data2) : ");
  Serial.println(data, DEC);             //send data2 gas sensor A to Serial
  Serial.println( (String) "DATA,TIME," + (data2) + "," + (data));
  delay(100);
}

