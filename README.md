# Autonomous Fire Detection & Suppression System

An embedded mechatronics prototype engineered to detect early-stage indoor fire outbreaks and deploy targeted suppression autonomously.

## System Architecture & Components
- **Microcontroller:** Arduino Uno (ATmega328P)
- **Sensor Array:** 3x Analog/Digital IR Flame Sensors, 1x MQ-2 Smoke/Gas Sensor
- **Actuation:** 5V Optocoupler Relay Module, 12V Submersible Fluid Pump / Directional Servo Mechanism
- **Software Stack:** C++, Arduino IDE

## Operational Logic
1. **Multi-Zone Polling:** Continuously reads analog inputs across directional IR flame channels (Left, Center, Right).
2. **Threshold Verification:** Cross-checks temperature/flame intensity against MQ-2 smoke sensor thresholds to eliminate false positives from ambient light.
3. **Targeted Deployment:** Actuates the directional nozzle via servo motor toward the detected zone and pulses the relay-driven pump until sensors read nominal values.

## Pin Configuration
- `A0` — IR Flame Sensor (Left)
- `A1` — IR Flame Sensor (Center)
- `A2` — IR Flame Sensor (Right)
- `A3` — MQ-2 Gas/Smoke Sensor
- `Pin 8` — Relay Signal Trigger
- `Pin 9` — Servo PWM Output
- `Pin 12` — Alarm Buzzer
