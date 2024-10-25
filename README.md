# MeterForce

MeterForce is designed to guess the PIN of a SmartMeter by rolling through all possible PINs from 0000 to 9999. It runs on an Arduino Uno, the input is done via an LED at the optical interface of the meter. The timings in this example are set for an EFR SGM-C8-A620N.

## Introduction

 The project starts with a single blink, waits for 3 seconds, and then blinks each digit of the PIN. The blink duration is set to 750 milliseconds.

## Wiring Diagram

| Component       | Arduino Pin | LCD Pin | LED Pin | Resistor |
|-----------------|-------------|---------|---------|----------|
| I2C LCD VCC     | 5V          | VCC     |         |          |
| I2C LCD GND     | GND         | GND     |         |          |
| I2C LCD SDA     | A4          | SDA     |         |          |
| I2C LCD SCL     | A5          | SCL     |         |          |
| LED             | 12          |         | Anode   | (Calculator)[https://www.digikey.com/en/resources/conversion-calculators/conversion-calculator-led-series-resistor]  |
| LED GND         | GND         |         | Cathode |          |