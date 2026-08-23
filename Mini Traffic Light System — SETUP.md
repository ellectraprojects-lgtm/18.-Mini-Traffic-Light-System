# Mini Traffic Light System — Setup Guide

## 1. Required Components

Prepare all components before starting:

- NE555 Timer IC × 1
- 220Ω Resistors × 6
- Green LED 5mm × 3
- Yellow LED 5mm × 2
- Red LED 5mm × 3
- 18650 Battery 3.7V × 2
- 2-Cell Battery Holder × 1
- Jumper Wires
- Connecting Wires
- 400-Point Breadboard × 1

## 2. Prepare the Breadboard

1. Place the **NE555 Timer IC** across the center gap of the breadboard.
2. Make sure the IC notch/dot is oriented correctly.
3. Connect the breadboard power rails to the battery holder.
4. Do **not** connect the battery yet.

## 3. Install the LEDs

Arrange the LEDs according to the traffic-light groups:

### Green
- Green LED 1
- Green LED 2
- Green LED 3

### Yellow
- Yellow LED 1
- Yellow LED 2

### Red
- Red LED 1
- Red LED 2
- Red LED 3

Connect each LED through its own **220Ω resistor**.

### LED Polarity

- **Long leg:** Anode (+)
- **Short leg:** Cathode (−)
- Flat edge on LED body usually indicates the cathode side.

## 4. Connect the NE555 Timer

The NE555 pins are:

| Pin | Name | Function |
|---:|---|---|
| 1 | GND | Ground |
| 2 | TRIGGER | Trigger input |
| 3 | OUTPUT | Timing output |
| 4 | RESET | Reset |
| 5 | CONTROL | Control voltage |
| 6 | THRESHOLD | Timing threshold |
| 7 | DISCHARGE | Discharge |
| 8 | VCC | Positive supply |

Connect:

- Pin 1 → GND
- Pin 8 → Positive supply
- Pin 4 → Positive supply
- Pin 2 and Pin 6 → Timing network
- Pin 7 → Timing network
- Pin 3 → LED control section

## 5. Power Connection

The two 18650 cells are placed in the **2-cell battery holder**.

Before connecting power:

1. Confirm the cells are inserted in the correct direction.
2. Measure the battery-pack voltage with a multimeter.
3. Confirm there is no short circuit between positive and negative rails.
4. Connect the battery only after the complete circuit has been checked.

A two-cell series pack will be approximately:

**7.4V nominal / 8.4V fully charged**

## 6. Initial Testing

After completing the wiring:

1. Inspect every breadboard connection.
2. Check all LED polarities.
3. Check every 220Ω resistor connection.
4. Check the NE555 orientation.
5. Check the battery polarity.
6. Power the circuit.
7. Observe the LED sequence.

If the LEDs do not operate correctly, disconnect the battery before troubleshooting.

## 7. Troubleshooting

### LEDs Not Turning ON

Check:

- LED polarity
- 220Ω resistor connections
- NE555 pin orientation
- Battery voltage
- Breadboard power rails

### LEDs Always ON

Check:

- NE555 pin 3 output connection
- Timing network
- Pin 2 and Pin 6 connections
- Possible breadboard short circuit

### NE555 Gets Hot

**Immediately disconnect the battery.**

Check for:

- Short circuit
- Incorrect IC orientation
- Incorrect VCC/GND connection
- Reversed power connection

## 8. Final Checklist

- [ ] NE555 IC correctly inserted
- [ ] All LEDs installed with correct polarity
- [ ] 220Ω resistors connected
- [ ] Battery holder connected correctly
- [ ] Power rails checked
- [ ] No short circuit
- [ ] Battery voltage verified
- [ ] LED sequence tested

## ⚠️ Safety Note

18650 lithium-ion cells can deliver high current. Never short the cells, use damaged cells, or connect them with reversed polarity. Disconnect the battery before changing the breadboard wiring.