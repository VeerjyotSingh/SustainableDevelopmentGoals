// C++ code
//
int Distance = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  pinMode(6, OUTPUT);
}

void loop()
{
  Distance = 0.01723 * readUltrasonicDistance(11, 10);
  if (Distance < 15) {
    digitalWrite(6, HIGH);
  } else {
    digitalWrite(6, LOW);
  }
  delay(10); // Delay a little bit to improve simulation performance
}