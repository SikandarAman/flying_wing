Servo elevonLeft;
Servo elevonRight;
int motorPin = 3;

void setup() {
    elevonLeft.attach(9);
    elevonRight.attach(10);
pinMode(motorPin, OUTPUT);
}

void loop() {
  //take inputs from rc

  //uske baad koi pid wagara lagake output nikalo
  
  int throttleOutput = map(throttle, 0, 1023, 0, 255);
  int rollOutput = map(roll, 0, 1023, 0, 180);
  int pitchOutput = map(pitch, 0, 1023, 0, 180);

  int elevonLeftPos = constrain(pitchOutput - rollOutput, 0, 180);
  int elevonRightPos = constrain(pitchOutput + rollOutput, 0, 180);

  //up = x <---
//upper = x+y
//down = x-y

  //roll = 0
  //pitch = 30

  elevonLeft.write(elevonLeftPos);
  elevonRight.write(elevonRightPos);
  analogWrite(motorPin, throttleOutput);

  //iske baad delay daaldo
}