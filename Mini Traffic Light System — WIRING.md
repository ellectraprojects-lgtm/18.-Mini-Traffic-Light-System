# Mini Traffic Light System — Wiring Guide

## ⚠️ Important

With the components listed in the project kit, the **NE555 alone cannot produce a proper Green → Yellow → Red traffic-light sequence**.

The NE555 can generate a timing/pulse signal, but a separate counter/sequencing stage is required for three independent traffic-light states.

Therefore, the wiring below describes the **power, LED, and NE555 connections**, while a proper automatic 3-state sequence requires additional components such as a **CD4017 decade counter**.

---

## 1. Battery Connection

Use the 2-cell 18650 battery holder.

| Battery Holder | Breadboard |
|---|---|
| `+` | Positive (+) rail |
| `−` | Ground (−) rail |

Two 3.7V cells in series provide approximately:

**7.4V nominal / 8.4V fully charged**

Do not reverse the battery polarity.

---

## 2. NE555 Pin Connections

Place the NE555 across the center gap of the breadboard.

| NE555 Pin | Connection |
|---:|---|
| Pin 1 — GND | Ground (−) rail |
| Pin 2 — TRIGGER | Timing circuit |
| Pin 3 — OUTPUT | Timing/output signal |
| Pin 4 — RESET | Positive (+) rail |
| Pin 5 — CONTROL | Leave unused |
| Pin 6 — THRESHOLD | Timing circuit |
| Pin 7 — DISCHARGE | Timing circuit |
| Pin 8 — VCC | Positive (+) rail |

### Basic Power

```text
Battery +  ─────────────── NE555 Pin 8
                         NE555 Pin 4

Battery −  ─────────────── NE555 Pin 1
```

---

## 3. LED Wiring

Every LED must have its own **220Ω current-limiting resistor**.

### Green LEDs

```text
NE555 / Sequencer Output
        |
       220Ω
        |
   Green LED
        |
       GND
```

Repeat for:

- Green LED 1
- Green LED 2
- Green LED 3

### Yellow LEDs

```text
Sequencer Output
      |
     220Ω
      |
 Yellow LED
      |
     GND
```

Repeat for:

- Yellow LED 1
- Yellow LED 2

### Red LEDs

```text
Sequencer Output
      |
     220Ω
      |
   Red LED
      |
     GND
```

Repeat for:

- Red LED 1
- Red LED 2
- Red LED 3

---

## 4. LED Polarity

For each LED:

```text
Long leg  → Anode (+)
Short leg → Cathode (−)
```

The LED cathode should ultimately return to the ground side of the circuit.

**Never connect an LED directly across the battery without a resistor.**

---

## 5. Required Traffic-Light Sequence

A proper traffic-light controller should operate like this:

```text
        ┌─────────────┐
        │    GREEN    │
        │   ON        │
        └──────┬──────┘
               ↓
        ┌─────────────┐
        │   YELLOW    │
        │   ON        │
        └──────┬──────┘
               ↓
        ┌─────────────┐
        │     RED     │
        │     ON      │
        └──────┬──────┘
               ↓
             GREEN
```

The NE555 can generate the clock signal required to advance this sequence, but an additional sequencing IC such as **CD4017** is needed to select Green, Yellow, and Red separately.

---

## 6. Recommended Expanded Circuit

For a true automatic traffic-light project, use:

```text
2 × 18650 Battery
        │
        ▼
      NE555
   Clock Generator
        │
        ▼
     CD4017
  Sequence Counter
        │
   ┌────┼────┐
   ▼    ▼    ▼
 GREEN YELLOW RED
   │    │    │
 220Ω  220Ω  220Ω
   │    │    │
 LEDs   LEDs  LEDs
   │    │    │
   └────┴────┘
        │
       GND
```

### Additional components required

- CD4017 IC
- Appropriate timing capacitor(s)
- Additional resistors/driver components if required by the final LED arrangement

---

## 7. Breadboard Power Rails

Keep the breadboard rails organized:

```text
RED rail  → Battery +
BLUE rail → Battery − / GND
```

Connect the NE555 and all LED return connections to the appropriate rails.

---

## 8. Final Wiring Checklist

- [ ] Battery positive connected to positive rail
- [ ] Battery negative connected to ground rail
- [ ] NE555 Pin 1 → GND
- [ ] NE555 Pin 8 → VCC
- [ ] NE555 Pin 4 → VCC
- [ ] NE555 timing pins connected correctly
- [ ] Every LED has a 220Ω resistor
- [ ] LED polarity checked
- [ ] No short circuit between VCC and GND
- [ ] Battery voltage checked before powering
- [ ] CD4017 added if a true 3-state traffic sequence is required

## ⚠️ Safety

Disconnect the 18650 battery pack before changing any breadboard connection. Never short-circuit lithium-ion cells.