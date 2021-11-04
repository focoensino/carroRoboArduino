#include <AFMotor.h>
#include <Servo.h>
#include <Ultrasonic.h>

 
#define TRIGGER_PIN  19
#define ECHO_PIN     18

Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);
Servo myservo1;  // create servo object to control a servo

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

unsigned char velocidade = 0x00;

void setup() {

   myservo1.attach(10);   
   velocidade =  0xFF;
   Serial.begin(9600);
}

void loop() {

      float cmMsec;
      long microsec = ultrasonic.timing();
      cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
      Serial.print(", CM: ");
      Serial.println(cmMsec);


      if(cmMsec <= 10){
          tras();
        
      }else if(cmMsec <= 20){

        parado();
      }else{

        frente();
      }

    
      //myservo1.write(pos);
}



void frente(){
     motor1.setSpeed(velocidade);
     motor1.run(BACKWARD);
     motor2.setSpeed(velocidade);
     motor2.run(FORWARD);
     motor3.setSpeed(velocidade);
     motor3.run(BACKWARD);
     motor4.setSpeed(velocidade);
     motor4.run(FORWARD);
}

void tras (){

     motor1.setSpeed(velocidade);
     motor1.run(FORWARD);
     motor2.setSpeed(velocidade);
     motor2.run(BACKWARD);
     motor3.setSpeed(velocidade);
     motor3.run(FORWARD);
     motor4.setSpeed(velocidade);
     motor4.run(BACKWARD);
}


void parado(){
     motor1.setSpeed(velocidade);
     motor1.run(RELEASE);
     motor2.setSpeed(velocidade);
     motor2.run(RELEASE);
     motor3.setSpeed(velocidade);
     motor3.run(RELEASE);
     motor4.setSpeed(velocidade);
     motor4.run(RELEASE);
  
}
