# MeterForce

MeterForce is designed to unlock your SmartMeter by trying all possible PINs from 0000 to 9999. It runs on an Arduino Uno, the input is done via an LED at the optical interface of the meter. The timings in this example are set for an EFR SGM-C8-A620N.

This project won't tell you the correct PIN. It just tries all possible PINs to unlock the meter, which usually needs to be done just once.

## Wiring Diagram

| Component       | Arduino Pin | LCD Pin | LED Pin | Resistor |
|-----------------|-------------|---------|---------|----------|
| I2C LCD VCC     | 5V          | VCC     |         |          |
| I2C LCD GND     | GND         | GND     |         |          |
| I2C LCD SDA     | A4          | SDA     |         |          |
| I2C LCD SCL     | A5          | SCL     |         |          |
| LED             | 12          |         | Anode   | [Calculator](https://www.digikey.com/en/resources/conversion-calculators/conversion-calculator-led-series-resistor)  |
| LED GND         | GND         |         | Cathode |          |
