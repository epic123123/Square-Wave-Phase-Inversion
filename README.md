# Square-Wave-phase-Inversion
Code for Raspberry Pi 4B: create a square-wave with a pulse interval of 20ms. User enters two phase lengths and the program switches between two square-wave phases of those lengths.

This can be used as a template for future projects using oscillators. The phase inversion can be used to cancel the echo.

Compilation:
```g++ pulse.cpp -o pulse -lwiringPi```
Assuming your rpi has wiringPi installed.

Example: 
```
Enter period 1: 5
Enter period 2: 4.1
```
see signal.jpg
