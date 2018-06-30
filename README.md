# Burn-wire_1.1
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

5) Set laptop/desktop clock to UTC should your application require it

6) Connect burn wire to your device and select the corresponding serial port

      Tools -> Port -> (device)

7) From Burn-wire-master upload DS-3231_set_time.ino to the burn wire

      File -> Open -> /Burn-wire-master/DS-3231_set_time/DS-3231_set_time.ino
      
      Sketch -> Upload

8) Verify unix time is correct by opening the serial monitor in Arduino IDE 

      Tools -> Serial Monitor

9) Open Burn_wire_1.0.ino and set times for the burn cycle and strobe delay found in the first few lines of code seperated by the "/". Do not edit code outside the lines provided.

10) Upload Burn_wire_1.0.ino to the burn wire and unplug from programming device
      
      --> Note: Elapsed time programmed begins once shorting plug is installed. 

11) Install shorting plug

12) Deploy!

NOTE: There is a known issue with macOS blocking the USB serial conneciton to the Arduino or arduino clone
Follow this link to download and install Virtual COM Port Drivers for macOS
(http://www.ftdichip.com/Drivers/VCP.htm)
