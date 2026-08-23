# Mini Traffic Light System

## 📌 Project Overview

The **Mini Traffic Light System** is a simple electronics project that demonstrates how traffic lights can be controlled using a **NE555 Timer IC**. The circuit uses red, yellow, and green LEDs to create a basic automatic traffic-light sequence.

This project is suitable for beginners learning about **555 timer circuits, LEDs, resistors, breadboard wiring, and timing circuits**.

## 🧰 Components Required

| Component | Quantity |
|---|---:|
| NE555 Timer IC | 1 |
| 220Ω Resistors | 6 |
| Green LED 5mm | 3 |
| Yellow LED 5mm | 2 |
| Red LED 5mm | 3 |
| 18650 Battery 3.7V | 2 |
| 2-Cell Battery Holder | 1 |
| Jumper Wires | 1 set |
| Connecting Wires | 1 |
| Breadboard 400 Points | 1 |

## ⚙️ Working Principle

The **NE555 Timer IC** is configured as an oscillator/timer. It generates a repeating timing signal that controls the LED sequence.

The LEDs represent the three traffic-light states:

1. 🟢 **Green** — Vehicles can move.
2. 🟡 **Yellow** — Vehicles should slow down or prepare to stop.
3. 🔴 **Red** — Vehicles must stop.

The LEDs are connected through **220Ω current-limiting resistors** to protect them from excessive current.

## 🔌 Power Supply

The circuit uses **two 18650 3.7V cells** in a 2-cell battery holder.

- Each cell: approximately **3.7V nominal**
- Two cells in series: approximately **7.4V nominal**
- Fully charged pack: approximately **8.4V**

⚠️ **Important:** Use a suitable protected/approved 18650 battery pack and holder. Do not short-circuit lithium-ion cells.

## 🎯 Learning Objectives

By completing this project, you can learn:

- Basic NE555 Timer operation
- LED polarity and current limiting
- Resistor selection
- Breadboard circuit construction
- Battery connections
- Basic timing circuits
- Traffic-light sequencing concepts

## 🧪 Testing

Before powering the circuit:

- Check the battery polarity.
- Check the NE555 IC orientation.
- Confirm every LED has a **220Ω resistor**.
- Check LED polarity.
- Ensure there are no short circuits on the breadboard.
- Verify the battery voltage with a multimeter.

After powering the circuit, the LEDs should operate according to the designed traffic-light sequence.

## 📁 Project Files

Recommended project documentation:

- `README.md` — Project overview and working principle
- `SETUP.md` — Assembly and testing procedure
- `WIRING.md` — Complete wiring connections
- `CODE_PROMPT.md` — Prompt for generating firmware/code if a programmable controller is added

## 💰 Approximate Component Cost

Based on the provided component list, the listed prices are approximately:

**Total: ₹489**

> Prices may vary depending on the supplier and component quality.

## ⚠️ Safety

- Do not short the 18650 batteries.
- Do not connect an incorrectly charged lithium-ion cell.
- Observe battery polarity.
- Use current-limiting resistors with LEDs.
- Disconnect the battery before modifying the circuit.

## ✅ Project Status

**Status: Components Checked**

All listed components in the provided checklist are marked as checked.