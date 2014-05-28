Drowsiness-Monitoring-System
============================

Drowsiness Monitoring System using Arduino microcontrollers,an Android Tablet,and a 4D Systems LCD Display

Hi all,

My name is Fabio Casagrande and I am an Electrical and Computer Engineer graduated from New York Institute of Technology. 
This is a project I did in my Senior Design class. I want to share it in order to help other students that have similar
projects to mine.

Abstract:
The purpose of this project was to create a system that allows the user to safely drive while 
being monitored. This system would track the driver’s eyes in real time and if he or she falls 
asleep, the system would turn up the volume of the radio and slow down the car until it stops.


Main Components:
In this project I used:
Android Tablet: Tracks the driver's eyes
Bluetooth Module: Allows the connection between the android tablet and the Arduino(master).
Arduino(master): takes actions according to the data received from the bluetooth module.
Arduino(Slave): Car simulator.I made a simple electrical circuit composed by 5 LEDs and 2 7-Segment digital displays.
4D LCD Display: Displays the current states according to the data received from the Arduino(Master).



Description:
The “brain” of this system is the Android Tablet. The driver is monitored with the built-in camera of the Tablet through 
the Open Source app "OpenCV". The app tracks the eyes of the driver and, at the same time, sends signals to the Arduino 
microcontroller. The real time eye tracking is also shown on the screen of the Tablet. The Tablet communication with 
the Arduino is through Bluetooth. According to the signal received from the Tablet, the Arduino (master) has two decisions 
to take. If the signal says that the eyes are not tracked, the Arduino (Master) activates the Arduino (Slave). The main task
of the Arduino (slave), once activated, is to start a series of operations that will result in stopping of the car only if
the driver’s eyes have not been detected in a certain amount of time. The Arduino (Slave) is active only when the eyes are 
not tracked from the Android Tablet . On the other hand, if the Arduino (master) receives the signal which says that the eyes
have been detected nothing happens. If in the previous state, the eyes were not detected and now they are detected, 
the Arduino (Master) will turn off the alerts. Each states will also be displayed on the 4D Systems LCD Display.



