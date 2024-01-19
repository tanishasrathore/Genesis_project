#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

void setup() {
  Serial.begin(9600);

  Wire.begin();
  mpu.initialize();

  // Check if the sensor connection is successful
  if (!mpu.testConnection()) {
    Serial.println("MPU6050 connection failed!");
    while (1);
  }
}

void loop() {
  // Read raw sensor data
  int16_t ax, ay, az, gx, gy, gz;
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  // Print raw sensor data
  Serial.print("Accelerometer: ");
  Serial.print("x = "); Serial.print(ax); Serial.print(" | ");
  Serial.print("y = "); Serial.print(ay); Serial.print(" | ");
  Serial.print("z = "); Serial.print(az); Serial.print(" | ");

  Serial.print("Gyroscope: ");
  Serial.print("x = "); Serial.print(gx); Serial.print(" | ");
  Serial.print("y = "); Serial.print(gy); Serial.print(" | ");
  Serial.print("z = "); Serial.print(gz);

  Serial.println();

  delay(500); // Adjust the delay based on your requirements
}
