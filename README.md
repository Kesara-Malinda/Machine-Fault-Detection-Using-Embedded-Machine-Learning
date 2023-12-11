# Machine-Fault-Detection-Using-Embedded-Machine-Learning
2nd Year Final Project | Ongoing

To create ML algorithm for vibration data classification, raw data must be collected. In this case, to create ML model that is to be run on STM32 Microcontroller is created using the EdgeImpulse service. The classification is done by comparing vibration pattern/waveforms of each state.

The states mentioned here are:- 

    for example, consider a cooling fan of a computer system. 
    the possible states can be  
    
                  1. Waveform at Normal Operation
                  2. Waveform at Idle 
                  3. Waveform at Fault condition - Fan Blade obstruction
                                                  Shaft Misalignment 
                                                  Wear of bearings

Upon completion of the project the device can identify whether there is a fault or not and even it will be able to classify the proper fault scenario.

To recreate vibration waveforms by EdgeImpulse Raw accelerometer data for 3 Axis is collected by simulating each condition.

Data collection is done by the MPU6050 3 - Axis Accelerometer sensor interfaced with Microcontroller. Then send the data over to computer via USB. In the computer, a python program will be listening to USB serial data processed and save the data into the CSV file.                        
This repository contains -

            * Firmware for microcontroller
            
            * Python script for creating CSV
            
            * Collected CSV Data file
            
You Can find more details on the project Below 


![image](https://github.com/Kesara-Malinda/Machine-Fault-Detection-Using-Embedded-Machine-Learning/assets/152917393/74c41f63-0d82-4da9-bc0c-ceb1c687ec3b)


![image](https://github.com/Kesara-Malinda/Machine-Fault-Detection-Using-Embedded-Machine-Learning/assets/152917393/3a2ccf4f-c84f-4aae-a658-feb94234efea)


