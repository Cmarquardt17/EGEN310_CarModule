/* Christian Marquardt
 *  10/21/2019
 *  EGEN310
 *  TEAM: B.5
 *  Overview: This is the control module for the RC Car that we are developing 
 *  As of right now it has two motors that control it for all directions of speed
 *  It will have three different types of speeds Slow, Normal, and High
 *  
 */


int state; //The state of the RC-Car


int flag=0; //makes sure that the serial only prints once the state

//Motor1
int OP1MotorFaultA = 11;
int OP1MotorDirA = 7;
int OP1MotorSpeedA = 9;

//Motor2
int OP1MotorFaultB = 12;
int OP1MotorDirB = 8;
int OP1MotorSpeedB = 10;

int Speed = 255; //Variable used for determining speed of the motors

void setup() {
  
  // motor1 pin assignment
  pinMode(OP1MotorFaultA, OUTPUT); //Initiates Motor Channel A pin
  pinMode(OP1MotorDirA, OUTPUT); //Initiates Brake Channel A pin
  pinMode(OP1MotorSpeedA, OUTPUT);

  //motor2 pin assignment
  pinMode(OP1MotorFaultB, OUTPUT); //Initiates Motor Channel A pin
  pinMode(OP1MotorDirB, OUTPUT); //Initiates Brake Channel A pin
  pinMode(OP1MotorSpeedB, OUTPUT);

  //This begins the connection
  Serial.begin(9600);
  Serial.println("This is end of setup");
} 
void loop() {

 //if some date is sent, reads it and saves in state
 if(Serial.available() > 0){ 
   state = Serial.read();
   flag=0; //Resetting the flag every loop for debugging/Serial Monitor
 } 
    //If state is 1 we are moving forward
    if(state == '5' || state == '6' || state == '7'){
      if(flag == 0){
        Serial.println("Speed CHANGE");
        flag=1;
        Speed = speedChange(state);
      }
    }
    if (state == '1') {
      //Motor A forward 
      digitalWrite(OP1MotorFaultA, LOW); //Establishes forward direction of Channel B
      digitalWrite(OP1MotorDirA, HIGH);   //Disengage the Brake for Channel B
      analogWrite(OP1MotorSpeedA, Speed);   //Spins the motor on Channel B at full speed

      //Motor B forward 
      digitalWrite(OP1MotorFaultB, LOW); //Establishes forward direction of Channel B
      digitalWrite(OP1MotorDirB, HIGH);   //Disengage the Brake for Channel B
      analogWrite(OP1MotorSpeedB, Speed);   //Spins the motor on Channel B at full speed

      if(flag == 0){
        Serial.println("1 was pressed going forward");
        flag=1;
      }
     }
     
    //If state is 2 we are moving backwards
    else if (state == '2') {
      //Motor A Backwards
      digitalWrite(OP1MotorFaultA, LOW); //Establishes forward direction of Channel B
      digitalWrite(OP1MotorDirA, LOW);   //Disengage the Brake for Channel B
      analogWrite(OP1MotorSpeedA, Speed);   //Spins the motor on Channel B at full speed
  
      //Motor B Backwards
      digitalWrite(OP1MotorFaultB, LOW); //Establishes forward direction of Channel B
      digitalWrite(OP1MotorDirB, LOW);   //Disengage the Brake for Channel B
      analogWrite(OP1MotorSpeedB, Speed);   //Spins the motor on Channel B at full speed
    
       if(flag == 0){
        Serial.println("2 was pressed going backwards");
        flag=1;
      }
     }
     
    //If state is 3 we are moving Left
    else if (state == '3') {
      //Motor B forward 
      digitalWrite(OP1MotorFaultB, HIGH); //Establishes forward direction of Channel B
      digitalWrite(OP1MotorDirB, LOW);   //Disengage the Brake for Channel B
      analogWrite(OP1MotorSpeedB, Speed);   //Spins the motor on Channel B at full speed
  
       //Motor A Backwards
       digitalWrite(OP1MotorFaultA, HIGH); //Establishes forward direction of Channel B
       digitalWrite(OP1MotorDirA, HIGH);   //Disengage the Brake for Channel B
       analogWrite(OP1MotorSpeedA, Speed);   //Spins the motor on Channel B at full speed

       if(flag == 0){
        Serial.println("3 was pressed going left");
        flag=1;
       }
      }
     //If state is 4 we are moving Right
     else if (state == '4') {
       //Motor A forward 
       digitalWrite(OP1MotorFaultA, HIGH); //Establishes forward direction of Channel B
       digitalWrite(OP1MotorDirA, LOW);   //Disengage the Brake for Channel B
       analogWrite(OP1MotorSpeedA, Speed);   //Spins the motor on Channel B at full speed

       //Motor B Backwards
       digitalWrite(OP1MotorFaultB, HIGH); //Establishes forward direction of Channel B
       digitalWrite(OP1MotorDirB, HIGH);   //Disengage the Brake for Channel B
       analogWrite(OP1MotorSpeedB, Speed);   //Spins the motor on Channel B at full speed
    
       if(flag == 0){
        Serial.println("4 was pressed right");
        flag=1;
       }
      }
      //If the state is 0 we are braking or stopping
      else if (state == '0'){
        //Motor A stop
        digitalWrite(OP1MotorFaultA, LOW); //Establishes forward direction of Channel B
        digitalWrite(OP1MotorDirA, LOW);   //Disengage the Brake for Channel B
        analogWrite(OP1MotorSpeedA, 0);   //Spins the motor on Channel B at full speed

        //Motor B stop
        digitalWrite(OP1MotorFaultB, LOW); //Establishes forward direction of Channel B
        digitalWrite(OP1MotorDirB, LOW);   //Disengage the Brake for Channel B
        analogWrite(OP1MotorSpeedB, 0);   //Spins the motor on Channel B at full speed
   
       if(flag == 0){
        Serial.println("0 was pressed we stopped");
        flag=1;
       }
      }
}

//This function is for speed change by passing in a message of type char
//And returns the speed
int speedChange(char x){
     if(x == '5'){
     Serial.println("This is the speed 255");
     return 255;
   }
   else if(x == '6'){
     Serial.println("This is the speed 200");
     return 200;
   }
   else if(x == '7'){
     Serial.println("This is the speed 150");
     return 150;
   }
   }
