/*
 * Project: Autonomous Fire Detection & Suppression Controller
 * Author: Mechatronics Engineering Prototypes
 * Target: Arduino Uno / ATmega328P
 */

const int flameLeft = A0;
const int flameCenter = A1;
const int flameRight = A2;
const int gasSensor = A3;

const int relayPump = 8;
const int buzzer = 12;

const int FLAME_THRESHOLD = 400; // Calibrated for active flame signatures
const int GAS_THRESHOLD = 300;

void setup() {
  pinMode(flameLeft, INPUT);
  pinMode(flameCenter, INPUT);
  pinMode(flameRight, INPUT);
  pinMode(gasSensor, INPUT);

  pinMode(relayPump, OUTPUT);
  pinMode(buzzer, OUTPUT);

  // Default state: Actuators deactivated
  digitalWrite(relayPump, HIGH); 
  digitalWrite(buzzer, LOW);

  Serial.begin(9600);
}

void loop() {
  int leftVal = analogRead(flameLeft);
  int centerVal = analogRead(flameCenter);
  int rightVal = analogRead(flameRight);
  int gasVal = analogRead(gasSensor);

  bool flameDetected = (leftVal < FLAME_THRESHOLD) || 
                       (centerVal < FLAME_THRESHOLD) || 
                       (rightVal < FLAME_THRESHOLD);

  bool hazardConfirmed = flameDetected && (gasVal > GAS_THRESHOLD);

  if (hazardConfirmed) {
    digitalWrite(buzzer, HIGH);
    digitalWrite(relayPump, LOW); // Trigger active-low relay to dispense
    Serial.println("STATUS: Fire outbreak detected. Actuating pump suppression.");
  } else {
    digitalWrite(buzzer, LOW);
    digitalWrite(relayPump, HIGH);
  }

  delay(200);
}
