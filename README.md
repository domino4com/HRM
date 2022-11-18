<img src="assets/IWA.svg" width=200 align="right">

# IWA - Input Weather A
This is a Weather Sensor measuring Atmospheric **Temperature** and Relative **Humidity**
| Specifications | ||
| --: | :--: |:--: |
| Communication | I²C |I²C |
| I²C Address | 0x44 | 0x38 |
| ChipSet | Sensirion SHT30-DIS| Aosong ASAIR AHT21|
| Datasheet | [.pdf](https://sensirion.com/media/documents/213E6A3B/61641DC3/Sensirion_Humidity_Sensors_SHT3x_Datasheet_digital.pdf) |[.pdf](http://www.aosong.com/userfiles/files/media/Data%20Sheet%20AHT21.pdf)|
| Suggested Arduino Library | [GitHub](https://github.com/wemos/WEMOS_SHT3x_Arduino_Library) |[GitHub](https://github.com/enjoyneering/AHTxx)
| Temperature Accuracy | ±0.2 °C |±0.01 °C|
| Temperature Range | -40 to 125 °C |-40 to 120 °C|
| Humidity Accuracy | ± 2 %RH |± 2 %RH|
| Humidity Range | 0 to 100 %RH |0 to 100 %RH|

## Supported I²C Modes
- [x] 100 kbit/s Standard Mode (SM) 
- [x] 400 kbit/s	Fast Mode	FM
- [x] 1 Mbit/s	Fast Mode Plus	FM+ **(SHT30-DIS only)**
- [ ] 3.4Mbit/s	High Speed Mode	HS
- [ ] 5 Mbit/s	Ultra Fast Mode	UFM

# License: 
<img src="assets/CC-BY-NC-SA.svg" width=200 align="right">
Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International Public License

[View License Deed](https://creativecommons.org/licenses/by-nc-sa/4.0/) | [View Legal Code](https://creativecommons.org/licenses/by-nc-sa/4.0/legalcode)
