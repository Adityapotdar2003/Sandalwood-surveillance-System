#include <Wire.h>
#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>

RF24 radio(9, 8); // CE, CSN pins
const byte address[6] = "1Node";  // Transmitter address
const int MPU6050_ADDR = 0x68;    // MPU6050 I2C address

struct NodeData {
  int16_t accX;
  int16_t accY;
  int16_t accZ;
  int batteryLevel;
  int nodeId;
};

void setup() {
  Serial.begin(9600);
  Wire.begin();
  
  // Initialize MPU6050
  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // Wake up MPU6050
  Wire.endTransmission(true);
  
  // Initialize NRF24L01
  radio.begin();
  radio.openWritingPipe(address);  // Open pipe for writing
  radio.setPALevel(RF24_PA_LOW);   // Set power level to low
  radio.stopListening();           // Stop listening, we are transmitting
}

void loop() {
  NodeData data;
  data = readMPU6050();
  data.batteryLevel = analogRead(A0); // Example of battery level reading
  data.nodeId = 1;  // Unique ID for this node

  // Send data
  bool report = radio.write(&data, sizeof(data));
  if (report) {
    Serial.println("Node 1: Data sent successfully!");
  } else {
    Serial.println("Node 1: Data failed to send.");
  }
  
  delay(1000);
}

NodeData readMPU6050() {
  NodeData data;

  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(0x3B);  
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_ADDR, 6, true);

  data.accX = Wire.read() << 8 | Wire.read();
  data.accY = Wire.read() << 8 | Wire.read();
  data.accZ = Wire.read() << 8 | Wire.read();

  return data;
}
