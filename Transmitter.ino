// Transmitter Code: Sending Accelerometer Data
// Libraries: TMRh20/RF24 (https://github.com/tmrh20/RF24/)
//            Wire (for I2C communication)

#include <Wire.h>
#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>

RF24 radio(9, 8); // CE, CSN
const byte address[10] = "ADDRESS01";
const int MPU6050_ADDR = 0x68;

struct AccelerometerData {
  int16_t accX;
  int16_t accY;
  int16_t accZ;
};

void setup() {
  Serial.begin(9600);
  Wire.begin();
  
  // Initialize MPU6050
  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(0x6B); // PWR_MGMT_1 register
  Wire.write(0);    // Wake up MPU6050
  Wire.endTransmission(true);
  
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  AccelerometerData accData = readMPU6050();

  radio.write(&accData, sizeof(accData));
  delay(1000);
}
t[





AccelerometerData readMPU6050() {
  AccelerometerData accData;

  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(0x3B); // Starting register to read accelerometer data
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_ADDR, 6, true);

  accData.accX = Wire.read() << 8 | Wire.read();
  accData.accY = Wire.read() << 8 | Wire.read();
  accData.accZ = Wire.read() << 8 | Wire.read();

  return accData;
}
