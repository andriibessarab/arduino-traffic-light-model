# Traffic Light Summative

## Description

This project is a model of a working traffic light system that controls traffic in a one-way junction. It utilizes two traffic lights and an Arduino Uno Board for control. The project includes an online model created in Tinkercad Circuits and a physical model. The code for the project contains comments for clarity and understanding.

## Online Model

The online model of the project can be accessed at [Tinkercad Circuits](https://www.tinkercad.com/circuits). The traffic lights are placed on separate small breadboards, and the wiring is color-coded with resistors to ensure the LEDs' protection. Each LED is labeled on the breadboard for easy identification (e.g., R1, Y1, G1, ...).

![Tinkercad Model](https://www.tinkercad.com/things/0xAFoJhsGaJ-andrii-bessarab-traffic-light-summative/editel?sharecode=JuWizzzB1o9VSWKSFVF6vfNwyri5DGA9H-TU8fn0q_w)

## Regular Cycle

The regular traffic light cycle operates as follows:

1. Traffic Light 1 (Red) --- Traffic Light 2 (Green) - 9 Seconds
2. Traffic Light 1 (Red) --- Traffic Light 2 (Yellow) – 3 Seconds
3. Traffic Light 1 (Red) --- Traffic Light 2 (Red) – 2 Seconds
4. Traffic Light 1 (Green) --- Traffic Light 2 (Red) – 9 Seconds
5. Traffic Light 1 (Yellow) --- Traffic Light 2 (Red) - 3 Seconds
6. Traffic Light 1 (Red) --- Traffic Light 2 (Red) – 2 Seconds
7. Repeat...

[//]: # (![Regular Cycle]&#40;regular_cycle.gif&#41;)

## Night Cycle

When the switch is activated, simulating night-time, the traffic lights change to a flashing red sequence in both directions. The night cycle operates as follows:

1. Red ON for 4 seconds
2. Red OFF for 4 seconds
3. Repeat...

[//]: # (![Night Cycle]&#40;night_cycle.gif&#41;)

## Turn Left

The push button is used to simulate a car waiting to turn left at the traffic lights. When the button is pressed and held, the following sequence occurs:

1. On the next light sequence, Traffic Light 1 flashes green for 10 seconds.
2. Traffic Light 2 remains solid red.
3. Once the flashing green starts, the button must be released.
4. After 10 seconds of flashing green, the lights return to their normal sequence.

[//]: # (![Turn Left]&#40;turn_left.gif&#41;)

## Additional Feature: Photocell Detection

An additional feature of this project is the utilization of a photocell to detect low brightness. When the photocell detects low brightness, the street light LEDs turn on to enhance visibility.

## Physical Model

The physical model of the project includes a platform provided for this purpose. The platform is raised from the ground to accommodate all the circuitry underneath. Feel free to decorate the platform according to your creativity.
