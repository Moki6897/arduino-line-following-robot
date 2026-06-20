int sensor1Pin = 2;
int sensor2Pin = 12;
int sensor1Value;
int sensor2Value;

void setup()
{
  pinMode(sensor1Pin, INPUT);
  pinMode(sensor2Pin, INPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  Serial.begin(9600);
}
void forward() 
{
  digitalWrite(10, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(3, LOW);
}
void stopMotors() 
{
  digitalWrite(10, LOW);
  digitalWrite(5, LOW);
}
void turnRight() 
{
  analogWrite(10, 200);   // Motor A — keep moving
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);
  analogWrite(5, 80);     // Motor B — slow down, don't reverse
  digitalWrite(4, HIGH);
  digitalWrite(3, LOW);
}

void turnLeft() 
{
  analogWrite(10, 80);    // Motor A — slow down
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);
  analogWrite(5, 200);    // Motor B — keep moving
  digitalWrite(4, HIGH);
  digitalWrite(3, LOW);
}
void reverseMotor() 
{
  digitalWrite(10, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(3, HIGH);
  delay(500);
}

void loop()
{
  sensor1Value = digitalRead(sensor1Pin);
  sensor2Value = digitalRead(sensor2Pin);
  
  Serial.print("Left: ");
  Serial.print(sensor1Value);
  Serial.print("Right: ");
  Serial.println(sensor2Value);
 
  if (sensor1Value == 0 && sensor2Value == 0)
{
  forward();
}
else if (sensor1Value == 0 && sensor2Value == 1)
{
  turnRight();
}
else if (sensor1Value == 1 && sensor2Value == 0)
{
  turnLeft();
}
else
{
  stopMotors();
}
  
}