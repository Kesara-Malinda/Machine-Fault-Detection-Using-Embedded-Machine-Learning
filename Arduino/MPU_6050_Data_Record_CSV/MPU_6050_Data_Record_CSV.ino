

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;
#define BTN_PIN             8
#define LED_R_PIN           5
#define CONVERT_G_TO_MS2    9.80665f
#define SAMPLING_FREQ_HZ    100
#define SAMPLING_PERIOD_MS  1000/SAMPLING_FREQ_HZ
#define NUM_SAMPLES         100
#define NUM_DATA_SETS        15


static unsigned long last_interval_ms = 0;

void setup(void) {
  
  pinMode(BTN_PIN, INPUT_PULLUP);
  pinMode(LED_R_PIN, OUTPUT);

  Serial.begin(9600); 

if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
 // Serial.println("Started");

  mpu.setAccelerometerRange(MPU6050_RANGE_16_G);
  mpu.setGyroRange(MPU6050_RANGE_250_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_94_HZ);
 
}

void loop() {
    float acc_x,acc_y,acc_z;
    unsigned long timestamp;
    unsigned long start_timestamp;

    while (digitalRead(BTN_PIN)==1) ;
    delay(1500);
      for(int j =0;j<= NUM_DATA_SETS;j++) 

      {

                    digitalWrite(LED_R_PIN,HIGH);

                    Serial.println("timestamp,acc_x,acc_y,acc_z"); //timestamp,acc_x,acc_y,acc_z

                  start_timestamp = millis();
              for(int i =0;i<NUM_SAMPLES;i++){
                  timestamp = millis();

                    sensors_event_t a, g, temp;
                    mpu.getEvent(&a, &g, &temp);
                    acc_x = a.acceleration.x;
                    acc_y = a.acceleration.y;
                    acc_z = a.acceleration.z;

                    acc_x*= CONVERT_G_TO_MS2;
                    acc_y*= CONVERT_G_TO_MS2;
                    acc_z*= CONVERT_G_TO_MS2;

                    Serial.print(timestamp-start_timestamp);
                    Serial.print(",");
                    Serial.print(acc_x);
                    Serial.print(",");
                    Serial.print(acc_y);
                    Serial.print(",");
                    Serial.print(acc_z );
                    Serial.println();

                  while(millis()<timestamp + SAMPLING_FREQ_HZ);
                    
              }

              Serial.println();
              digitalWrite(LED_R_PIN,LOW);

              while(digitalRead(BTN_PIN)==0);
              delay(1000);

      }

}