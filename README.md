# Underbed_LEDstrip
An arduino nano project desiged to save your toes durring your midnight pee trips

Hello, My name is Allen and I’m a software developer and avid proponent of taking middle of the night jaunts. On this parlous quest, I encounter sunken bedroom steps, A vicious beast, the occasional sandal booby trap. To help clear these dangers, I have put together this under-glow bed device which illuminates the bedroom with soft red light for approximately one round trip journeys worth of travel. If you also brave the dangers and would like a light to guide your way, I’m here to help

#What It Does

The Underbed lights are designed to illuminate for a set amount of time when two conditions are met.
1. The light level at the unit is below a predetermined threshold.
2. Motion is triggered at the units PIR sensor.

This starts a sequence that consists of the unit softly fading on over a set time, remaining illuminated for the duration, checking if motion is still triggered and then softly fading off if no motion is present.

#How its made

The project was built on an Arduino Nano clone board using a PIR sensor to trigger input, a photoresistor to detect ambient light level, and a 12V red LED strip for illumination. The project was built using the ArduinoIDE. My iteration was deployed on a breadboard, but you can solder the components to a prototype board if you would like. 

#Supplies

10kΩ Resistor
5539 5MM 90K Photoresistor
12v red LED light strip
12v barrel jack PSU
Arduino Nano (or equivalent knock off)
IRFZ44 N-Channel MOSFET
AM312 Mini PIR sensor
Assorted Lengths of wire

#How to biuld the project

You will need the Arduino IDE installed on your system, alternatively you can use Platform IO in VS code. If you want to use PlatformIO, use this link -> https://docs.platformio.org/en/latest/integration/ide/vscode.html

Start by using the attached image in this project to build your main board. The board only uses one PIR sensor, but you can build it out with two sensors by complementing the second sensor values in the code.

Plug it into the Arduino IDE or PlatformIO and build the project. Then you’re ready to install the device under your bed or anywhere you feel is appropriate. Feel free to change the light level check value if your installation sight has a different ambient light level.

Thanks for taking a look at my project
