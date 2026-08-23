/*
 * ============================================================
 *  Mini Traffic Light System
 *  Target Board : Arduino Uno / Nano / any ATmega328P board
 *  Author       : Generated Firmware
 *  Version      : 1.0
 * ============================================================
 *
 *  WIRING DIAGRAM
 *  ──────────────
 *  Arduino Pin 8  ──[220Ω]──► Green  LED Anode │ Cathode ──► GND
 *  Arduino Pin 9  ──[220Ω]──► Yellow LED Anode │ Cathode ──► GND
 *  Arduino Pin 10 ──[220Ω]──► Red    LED Anode │ Cathode ──► GND
 *
 *  SEQUENCE
 *  ────────
 *  Power-on  : Red   ON  (safety default)
 *  Step 1    : Red   ON  for 5 seconds
 *  Step 2    : Green ON  for 5 seconds
 *  Step 3    : Yellow ON for 2 seconds
 *  Step 4    : Repeat from Step 1
 *
 *  IMPORTANT HARDWARE NOTE
 *  ───────────────────────
 *  An NE555 Timer IC is NOT a programmable microcontroller.
 *  This firmware requires an Arduino or compatible ATmega board.
 *  See the bottom of this file for an NE555-only hardware
 *  alternative if no microcontroller is available.
 * ============================================================
 */

// ── Pin Definitions ──────────────────────────────────────────
const uint8_t PIN_GREEN  = 8;   // Green  LED on digital pin 8
const uint8_t PIN_YELLOW = 9;   // Yellow LED on digital pin 9
const uint8_t PIN_RED    = 10;  // Red    LED on digital pin 10

// ── Timing Constants (milliseconds) ──────────────────────────
const unsigned long TIME_RED_MS    = 5000UL;  // Red   phase  : 5 s
const unsigned long TIME_GREEN_MS  = 5000UL;  // Green phase  : 5 s
const unsigned long TIME_YELLOW_MS = 2000UL;  // Yellow phase : 2 s

// ── Traffic Light States ──────────────────────────────────────
/*
 *  Using an enum makes the state machine readable and easy
 *  to extend (e.g., add a flashing-yellow night mode later).
 */
enum TrafficState : uint8_t {
    STATE_RED    = 0,
    STATE_GREEN  = 1,
    STATE_YELLOW = 2
};

// ── Global State Variables ────────────────────────────────────
TrafficState currentState    = STATE_RED;   // Always start on Red
unsigned long stateStartTime = 0UL;         // Timestamp of last state change


// ════════════════════════════════════════════════════════════════
//  HELPER FUNCTION — setLights()
//  Turns exactly ONE LED on and the other two off.
//  This guarantees only one colour is ever active at a time.
// ════════════════════════════════════════════════════════════════
void setLights(bool greenOn, bool yellowOn, bool redOn) {
    digitalWrite(PIN_GREEN,  greenOn  ? HIGH : LOW);
    digitalWrite(PIN_YELLOW, yellowOn ? HIGH : LOW);
    digitalWrite(PIN_RED,    redOn    ? HIGH : LOW);
}


// ════════════════════════════════════════════════════════════════
//  HELPER FUNCTION — enterState()
//  Transitions to a new state: activates the correct LED,
//  records the time, and prints a debug message over Serial.
// ════════════════════════════════════════════════════════════════
void enterState(TrafficState newState) {
    currentState    = newState;
    stateStartTime  = millis();   // Snapshot the current time

    switch (currentState) {

        case STATE_RED:
            setLights(false, false, true);  // Only Red ON
            Serial.println(F("▶ RED    ON  — waiting 5 s"));
            break;

        case STATE_GREEN:
            setLights(true, false, false);  // Only Green ON
            Serial.println(F("▶ GREEN  ON  — waiting 5 s"));
            break;

        case STATE_YELLOW:
            setLights(false, true, false);  // Only Yellow ON
            Serial.println(F("▶ YELLOW ON  — waiting 2 s"));
            break;

        // Defensive default — should never be reached
        default:
            setLights(false, false, true);
            currentState = STATE_RED;
            break;
    }
}


// ════════════════════════════════════════════════════════════════
//  setup()
//  Runs once at power-on or after reset.
// ════════════════════════════════════════════════════════════════
void setup() {

    // ── Configure LED pins as outputs ────────────────────────
    pinMode(PIN_GREEN,  OUTPUT);
    pinMode(PIN_YELLOW, OUTPUT);
    pinMode(PIN_RED,    OUTPUT);

    // ── Make sure all LEDs start OFF ─────────────────────────
    //    (avoids a random HIGH state on some boards)
    setLights(false, false, false);

    // ── Start Serial for optional debug monitoring ────────────
    Serial.begin(9600);
    Serial.println(F("============================"));
    Serial.println(F("  Mini Traffic Light System "));
    Serial.println(F("============================"));

    // ── Enter the initial safe state: RED ON ─────────────────
    enterState(STATE_RED);
}


// ════════════════════════════════════════════════════════════════
//  loop()
//  Runs continuously after setup().
//  Uses millis() — non-blocking — so the board stays responsive.
// ════════════════════════════════════════════════════════════════
void loop() {

    /*
     *  Calculate how many milliseconds have passed since the
     *  current state was entered.
     *
     *  NOTE: millis() overflows back to 0 after ~49.7 days.
     *  Subtracting unsigned longs handles this correctly as long
     *  as no single state lasts longer than 49.7 days (it won't).
     */
    unsigned long elapsed = millis() - stateStartTime;

    // ── State Machine ─────────────────────────────────────────
    switch (currentState) {

        // ── RED phase (5 seconds) ─────────────────────────────
        case STATE_RED:
            if (elapsed >= TIME_RED_MS) {
                enterState(STATE_GREEN);    // Red → Green
            }
            break;

        // ── GREEN phase (5 seconds) ───────────────────────────
        case STATE_GREEN:
            if (elapsed >= TIME_GREEN_MS) {
                enterState(STATE_YELLOW);   // Green → Yellow
            }
            break;

        // ── YELLOW phase (2 seconds) ──────────────────────────
        case STATE_YELLOW:
            if (elapsed >= TIME_YELLOW_MS) {
                enterState(STATE_RED);      // Yellow → Red
            }
            break;

        // ── Defensive default ─────────────────────────────────
        default:
            enterState(STATE_RED);
            break;
    }

    /*
     *  Nothing else is blocked here.
     *  You can safely add sensor reads, button checks,
     *  or serial commands in this space without disrupting
     *  the traffic-light timing.
     */
}


/*
 * ============================================================
 *  HARDWARE-ONLY ALTERNATIVE — NE555 + CD4017 (No Arduino)
 * ============================================================
 *
 *  If the build uses ONLY an NE555 (and no microcontroller),
 *  the traffic-light sequence must be built from discrete
 *  logic ICs.  A common approach:
 *
 *  COMPONENTS NEEDED
 *  ─────────────────
 *  • 1× NE555   — Astable oscillator (clock source)
 *  • 1× CD4017  — Decade counter / Johnson counter
 *                 (divides the clock into 10 sequential outputs)
 *  • 3× LED     — Red, Yellow, Green
 *  • 3× 220Ω   — Current-limiting resistors
 *  • Resistors + capacitors to set the NE555 frequency
 *  • Diodes (1N4148) to OR multiple CD4017 outputs together
 *
 *  HOW IT WORKS
 *  ────────────
 *  1. NE555 in astable mode generates a square-wave clock.
 *     Choose R1, R2, C so the period = 1 second per pulse
 *     (use the formula f = 1.44 / ((R1 + 2·R2) · C)).
 *
 *  2. CD4017 advances one output HIGH per clock pulse.
 *     Outputs Q0–Q9 go HIGH in turn, then repeat.
 *
 *  3. Map CD4017 outputs to LED colours with diodes:
 *     ┌─────────────────┬──────────────────────────────┐
 *     │ CD4017 Outputs  │ Action                       │
 *     ├─────────────────┼──────────────────────────────┤
 *     │ Q0 – Q4  (×5)   │ OR together → Red   LED ON   │
 *     │ Q5 – Q9  (×5)   │ OR together → Green LED ON   │
 *     │ Q8 – Q9  (×2)   │ OR together → Yellow LED ON  │
 *     └─────────────────┴──────────────────────────────┘
 *     Adjust which outputs feed which LED to match your
 *     desired timing ratios.
 *
 *  4. Connect CD4017 RESET pin back to an appropriate Q
 *     output to shorten the count cycle if needed
 *     (e.g., tie RESET to Q10/Q7 to create a 7-step cycle).
 *
 *  LIMITATION
 *  ──────────
 *  This purely hardware approach cannot run Arduino (.ino)
 *  code.  The NE555 is an analogue timer IC — it has no CPU,
 *  no memory, and no ability to interpret software instructions.
 *
 * ============================================================
 */
