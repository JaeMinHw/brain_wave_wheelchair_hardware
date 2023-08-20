#include <SoftwareSerial.h>

#include <AFMotor.h>

AF_DCMotor motor_1(1);
AF_DCMotor motor_2(2);
AF_DCMotor motor_3(3);
AF_DCMotor motor_4(4);


int move_time = 1000;

unsigned long duration = 6000;
unsigned long accelerationTime = 3000;

unsigned long before = 0;


String fo = "FORWARD";
String ba = "BACKWARD";



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  char read_data;

  if(Serial.available()) {
    read_data = Serial.read();
    if(read_data == '0') {
      stop();
      Serial.println("emergency!!");
    }
    else if(read_data == '1') {
      go();
//      move("FORWARD","FORWARD","FORWARD","FORWARD");
      Serial.println("go");
    }
    else if(read_data == '2') {
      back();
      Serial.println("back");
    }
    else if(read_data == '3') {
      right();
      Serial.println("right");
    }
    else if(read_data == '4') {
      left();
      Serial.println("left");
    }
    else if(read_data == '5') {
      Turning_right();
      Serial.println("Turning_right");
    }
    else if(read_data == '6') {
      Turning_left();
      Serial.println("Turning_left");
    }
   
  }

}



void stop() {
 
  motor_1.setSpeed(0);
  motor_2.setSpeed(0);
  motor_3.setSpeed(0);
  motor_4.setSpeed(0);

  motor_1.run(RELEASE);
  motor_2.run(RELEASE);
  motor_3.run(RELEASE);
  motor_4.run(RELEASE);
}




void go(){
  unsigned long startTime = millis();

  while(millis() - startTime <= duration) {

    unsigned long elapsedTime = millis() - startTime;

    int speed;
    if(elapsedTime <= accelerationTime) {
      speed = map(elapsedTime, 0,accelerationTime,0,80);

      // 여기서 delay를 주는거는 어떨까??? 그럼 초음파 센서 감지가 불가능할까??
      // delay(100);
      motor_1.setSpeed(speed);
      motor_2.setSpeed(speed);
      motor_3.setSpeed(speed);
      motor_4.setSpeed(speed);
      motor_1.run(FORWARD);
      motor_2.run(FORWARD);
      motor_3.run(FORWARD);
      motor_4.run(FORWARD);
    }
    else {
      // 여기서 delay를 주는거는 어떨까??? 그럼 초음파 센서 감지가 불가능할까??
      // delay(100);
      speed = map(elapsedTime-accelerationTime,0,duration - accelerationTime, 80,0);
      motor_1.setSpeed(speed);
      motor_2.setSpeed(speed);
      motor_3.setSpeed(speed);
      motor_4.setSpeed(speed);
      motor_1.run(FORWARD);
      motor_2.run(FORWARD);
      motor_3.run(FORWARD);
      motor_4.run(FORWARD);
    }


    if(Serial.available()) {
      char read_data = Serial.read();
      if(read_data == '7') {
        stop();
        Serial.println("force stop");
        return;
      }
    }
    
    unsigned long currentTime = millis();
    if(currentTime - startTime >= duration) {
      break; // if over the total move time, is ending
    }
  }

  motor_1.setSpeed(0);
  motor_2.setSpeed(0);
  motor_3.setSpeed(0);
  motor_4.setSpeed(0);

  motor_1.run(RELEASE);
  motor_2.run(RELEASE);
  motor_3.run(RELEASE);
  motor_4.run(RELEASE);

}


void back(){
  unsigned long startTime = millis();

 

  while(millis() - startTime <= duration) {

    if(Serial.available()) {
      char read_data = Serial.read();
      if(read_data == '7') {
        stop();
        Serial.println("force stop");
        return;
      }
    }
    unsigned long elapsedTime = millis() - startTime;

    int speed;
    if(elapsedTime <= accelerationTime) {
      speed = map(elapsedTime, 0,accelerationTime,0,80);
    }
    else {
      speed = map(elapsedTime-accelerationTime,0,duration - accelerationTime, 80,0);
    }

    motor_1.setSpeed(speed);
    motor_2.setSpeed(speed);
    motor_3.setSpeed(speed);
    motor_4.setSpeed(speed);
    motor_1.run(BACKWARD);
    motor_2.run(BACKWARD);
    motor_3.run(BACKWARD);
    motor_4.run(BACKWARD);

    unsigned long currentTime = millis();
    if(currentTime - startTime >= duration) {
      break; // if over the total move time, is ending
    }
  }

  motor_1.setSpeed(0);
  motor_2.setSpeed(0);
  motor_3.setSpeed(0);
  motor_4.setSpeed(0);

  motor_1.run(RELEASE);
  motor_2.run(RELEASE);
  motor_3.run(RELEASE);
  motor_4.run(RELEASE);

}


void right(){
  unsigned long startTime = millis();

  while(millis() - startTime <= duration) {
    if(Serial.available()) {
      char read_data = Serial.read();
      if(read_data == '7') {
        stop();
        Serial.println("force stop");
        return;
      }
    }
    unsigned long elapsedTime = millis() - startTime;

    int speed;
    if(elapsedTime <= accelerationTime) {
      speed = map(elapsedTime, 0,accelerationTime,0,80);
    }
    else {
      speed = map(elapsedTime-accelerationTime,0,duration - accelerationTime, 80,0);
    }

    motor_1.setSpeed(speed);
    motor_2.setSpeed(speed);
    motor_3.setSpeed(speed);
    motor_4.setSpeed(speed);
    motor_1.run(FORWARD);
    motor_2.run(BACKWARD);
    motor_3.run(BACKWARD);
    motor_4.run(FORWARD);

    unsigned long currentTime = millis();
    if(currentTime - startTime >= duration) {
      break; // if over the total move time, is ending
    }
  }

  motor_1.setSpeed(0);
  motor_2.setSpeed(0);
  motor_3.setSpeed(0);
  motor_4.setSpeed(0);

  motor_1.run(RELEASE);
  motor_2.run(RELEASE);
  motor_3.run(RELEASE);
  motor_4.run(RELEASE);

}



void left(){
  unsigned long startTime = millis();

  while(millis() - startTime <= duration) {

    if(Serial.available()) {
      char read_data = Serial.read();
      if(read_data == '7') {
        stop();
        Serial.println("force stop");
        return;
      }
    }
    unsigned long elapsedTime = millis() - startTime;

    int speed;
    if(elapsedTime <= accelerationTime) {
      speed = map(elapsedTime, 0,accelerationTime,0,80);
    }
    else {
      speed = map(elapsedTime-accelerationTime,0,duration - accelerationTime, 80,0);
    }

    motor_1.setSpeed(speed);
    motor_2.setSpeed(speed);
    motor_3.setSpeed(speed);
    motor_4.setSpeed(speed);
    motor_1.run(BACKWARD);
    motor_2.run(FORWARD);
    motor_3.run(FORWARD);
    motor_4.run(BACKWARD);

    unsigned long currentTime = millis();
    if(currentTime - startTime >= duration) {
      break; // if over the total move time, is ending
    }
  }

  motor_1.setSpeed(0);
  motor_2.setSpeed(0);
  motor_3.setSpeed(0);
  motor_4.setSpeed(0);

  motor_1.run(RELEASE);
  motor_2.run(RELEASE);
  motor_3.run(RELEASE);
  motor_4.run(RELEASE);

}




void Turning_right(){
  unsigned long startTime = millis();

  while(millis() - startTime <= duration) {
   
    if(Serial.available()) {
      char read_data = Serial.read();
      if(read_data == '7') {
        stop();
        Serial.println("force stop");
        return;
      }
    }
   
    unsigned long elapsedTime = millis() - startTime;

    int speed;
    if(elapsedTime <= accelerationTime) {
      speed = map(elapsedTime, 0,accelerationTime,0,80);
    }
    else {
      speed = map(elapsedTime-accelerationTime,0,duration - accelerationTime, 80,0);
    }

    motor_1.setSpeed(speed);
    motor_2.setSpeed(speed);
    motor_3.setSpeed(speed);
    motor_4.setSpeed(speed);
    motor_1.run(FORWARD);
    motor_2.run(BACKWARD);
    motor_3.run(FORWARD);
    motor_4.run(BACKWARD);

    unsigned long currentTime = millis();
    if(currentTime - startTime >= duration) {
      break; // if over the total move time, is ending
    }
  }

  motor_1.setSpeed(0);
  motor_2.setSpeed(0);
  motor_3.setSpeed(0);
  motor_4.setSpeed(0);

  motor_1.run(RELEASE);
  motor_2.run(RELEASE);
  motor_3.run(RELEASE);
  motor_4.run(RELEASE);

}





void Turning_left(){
  unsigned long startTime = millis();

  while(millis() - startTime <= duration) {
   
    if(Serial.available()) {
      char read_data = Serial.read();
      if(read_data == '7') {
        stop();
        Serial.println("force stop");
        return;
      }
    }
   
    unsigned long elapsedTime = millis() - startTime;

    int speed;
    if(elapsedTime <= accelerationTime) {
      speed = map(elapsedTime, 0,accelerationTime,0,80);
    }
    else {
      speed = map(elapsedTime-accelerationTime,0,duration - accelerationTime, 80,0);
    }

    motor_1.setSpeed(speed);
    motor_2.setSpeed(speed);
    motor_3.setSpeed(speed);
    motor_4.setSpeed(speed);
    motor_1.run(BACKWARD);
    motor_2.run(FORWARD);
    motor_3.run(BACKWARD);
    motor_4.run(FORWARD);

    unsigned long currentTime = millis();
    if(currentTime - startTime >= duration) {
      break; // if over the total move time, is ending
    }
  }

  motor_1.setSpeed(0);
  motor_2.setSpeed(0);
  motor_3.setSpeed(0);
  motor_4.setSpeed(0);

  motor_1.run(RELEASE);
  motor_2.run(RELEASE);
  motor_3.run(RELEASE);
  motor_4.run(RELEASE);

}







//
//
//void move(String m1, String m2, String m3, String m4){
//  unsigned long startTime = millis();
//
//  while(millis() - startTime <= duration) {
//    unsigned long elapsedTime = millis() - startTime;
//
//    int speed;
//    if(elapsedTime <= accelerationTime) {
//      speed = map(elapsedTime, 0,accelerationTime,0,80);
//    }
//    else {
//      speed = map(elapsedTime-accelerationTime,0,duration - accelerationTime, 80,0);
//    }
//
//    motor_1.setSpeed(speed);
//    motor_2.setSpeed(speed);
//    motor_3.setSpeed(speed);
//    motor_4.setSpeed(speed);
//    motor_1.run(&m1);
//    motor_2.run(&m2);
//    motor_3.run(&m3);
//    motor_4.run(&m4);
//
//    unsigned long currentTime = millis();
//    if(currentTime - startTime >= duration) {
//      break; // if over the total move time, is ending
//    }
//  }
//
//  motor_1.setSpeed(0);
//  motor_2.setSpeed(0);
//  motor_3.setSpeed(0);
//  motor_4.setSpeed(0);
//
//  motor_1.run(RELEASE);
//  motor_2.run(RELEASE);
//  motor_3.run(RELEASE);
//  motor_4.run(RELEASE);
//
//}
//
//
//