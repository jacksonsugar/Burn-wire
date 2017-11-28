# Burn-wire_1.0
Dependencies and code for a compact self-contained burn wire based on the Arduino Nano & DS3231 Real Time Clock

Steps for deployment

1) Download and install Arduino IDE from the official website:  https://www.arduino.cc/en/Main/Software
2) Clone this repository to your device by following the green link above [Download ZIP]
3) Open Adruino IDE and configure bootloader for the Arduino Nano 

      Tools -> Board: -> Arduino Nano

      Tools -> Processor -> ATmega328P

4) Import .zip libraries from repository into Arduino IDE 

      Sketch -> Include Library -> Add .ZIP Library..
            
            Low-Power-master.zip
            
            RTClib-master.zip

5) Set laptop/desktop clock to UTC

6) Connect burn wire to your device and upload DS-3231_set_time.ino to the controller

7) Verify unix time is correct by opening the serial monitor in Arduino IDE 

      Tools -> Serial Monitor

8) Open Burn_wire_1.0.ino and set times for the burn cycle and strobe delay found in the first few lines of code

9) Upload Burn_wire_1.0.ino to the burn wire and unplug from programming device

10) Once ready to deploy, install shorting plug and cut off USB cable (making sure to seal off any exposed wire)

11) Deploy!

NOTE: There is a known bug in the macOS distribution of Arduino IDE blocking the USB serial conneciton to the Arduino
Follow this Sparkfun link to fix (https://learn.sparkfun.com/tutorials/how-to-install-ftdi-drivers/mac)
