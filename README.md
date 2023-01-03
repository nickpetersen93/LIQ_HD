# LIQ HD - Lick Instance Quantifier Home cage Device 

## Included in this repository:
  - Arduino code for LIQ HD running off an Arduino Mega
  - Arduino code for LIQ HD running off an Adafruit Grand Central (significantly faster processor speed)
  - 3D models for all required 3D-printed components in various file formats (STL, STEP, SHAPR)
  - Step-by-step build instructions and video tutorial can be found on the [Wiki page](https://github.com/nickpetersen93/LIQ_HD/wiki/LIQ-HD---Step-by-Step-Tutorial "LIQ HD - Step-by-Step Tutorial")
  
------------------------------------------------------------------

### Required Arduino Libraries:
  - Adafruit_GFX.h
  - RTClib.h
  - SdFat.h
  - Adafruit_MPR121.h
  - Adafruit_ILI9341.h
  - Adafruit_FT6206.h
  
------------------------------------------------------------------

### Publication Link: https://www.biorxiv.org/content/10.1101/2022.12.16.520661v1


## Abstract

Investigation of rodent drinking behavior has provided insight into drivers of thirst, circadian rhythms, anhedonia, and drug and ethanol consumption. Traditional methods of recording fluid intake involve periodically weighing bottles, which is cumbersome and lacks temporal resolution. Several open-source devices have been designed to improve drink monitoring, particularly for two-bottle choice tasks. However, recent designs are limited by the use of infrared photobeam-break sensors and incompatibility with prolonged undisturbed use in ventilated home cages. Beam-break sensors lack accuracy for bout microstructure analysis and are prone to damage from rodents. To address these concerns, we designed LIQ HD (Lick Instance Quantifier Home cage Device) with the goal of utilizing capacitive sensors to increase accuracy and analyze lick microstructure, building a device compatible with ventilated vivarium home cages, increasing scale with prolonged undisturbed recordings, and creating a design that is easy to build and use with an intuitive touchscreen graphical user interface. The system tracks two-bottle choice licking behavior in up to 18 rodent home cages, or 36 single bottles, on a minute-to-minute timescale controlled by a single Arduino microcontroller. The data are logged to a single SD card, allowing for efficient downstream analysis. With sucrose, quinine, and ethanol two-bottle choice tasks, we validated that LIQ HD has superior accuracy compared to beam-break sensors. The system measures preference over time and changes in bout microstructure, with undisturbed recordings lasting up to 7 days. All designs and software are open-source to allow other researchers to build upon the system and adapt LIQ HD to their animal home cages.


<p align="center">
<img width="560" alt="Screen Shot 2022-12-15 at 4 54 24 PM" src="https://user-images.githubusercontent.com/86747820/207975271-d024acc4-405c-4381-a1c6-2fc56d0128fb.png">
</p>
