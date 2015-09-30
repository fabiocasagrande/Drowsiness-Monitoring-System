Drowsiness-Monitoring-System
============================

Drowsiness Monitoring System using Arduino microcontrollers,an Android Tablet,and a 4D Systems LCD Display

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
