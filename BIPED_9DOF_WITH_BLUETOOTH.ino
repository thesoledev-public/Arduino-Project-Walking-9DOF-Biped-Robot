#include <Servo.h>

String commandInput;
String currentCommand = "";

const int servo_pin[9] = {5, 6, 7, 8, 9, 10, 11, 12,3};
Servo arr_servo[9];

int eyesLED = 2;
int mouthLED = 4;

void setup() {
    Serial.begin(9600);

    for (int ctr = 0; ctr < 9; ctr++)
    {
      arr_servo[ctr].attach(servo_pin[ctr]);
      delay(100);
    } 
    pinMode(eyesLED, OUTPUT);
    pinMode(mouthLED, OUTPUT);
  reset();
}

void loop() {

  setCommand();
    
    while(currentCommand != "") {

      Serial.println(currentCommand);
      
      if(currentCommand == "command1") {
       mouthLight();        
        dance1();
        Serial.println("command1");       
      }
      else if(currentCommand == "command2") {
        mouthLight();
        dance2();
        Serial.println("command2");       
      }
      else if(currentCommand == "command3") {
        mouthLight();
        armFront();
        Serial.println("command3");       
      }  
      else if(currentCommand == "command4") {
        mouthLight();
        Serial.println("command4");       
      }          
      else if(currentCommand == "forward") {
        mouthLight();
        walkForward();
        Serial.println("walkForward");       
      }
      else if(currentCommand == "backward") {
        walkBackward();
        Serial.println("walkBackward");       
      }
      else if(currentCommand == "left") {
        mouthLight();
        turnLeft();
        Serial.println("turnLeft");       
      }
      else if(currentCommand == "right") {
        mouthLight();
        turnRight();
        Serial.println("turnRight");       
      }
      else if(currentCommand == "reset") {
        reset();
        Serial.println("reset");       
      }
      commandInput="";
      setCommand();      
      delay(500);  
    }


}

void setCommand(){

    while (Serial.available()){ 
      delay(10);
      char c = Serial.read();
      if (c == '#') {break;}
      commandInput += c;
    }
    
    if(commandInput != currentCommand && commandInput != ""){
      currentCommand = commandInput; 
      Serial.println("Current:" + currentCommand); 
      commandInput = "";
      reset();
    }
    
}

void mouthLight(){
  digitalWrite(eyesLED, HIGH);
  digitalWrite(mouthLED, HIGH);
  delay(500); 
  digitalWrite(mouthLED, LOW);
}

void armFront(){
  arr_servo[4].write(180); 
  arr_servo[5].write(0);
}

void dance1(){
  arr_servo[4].write(180); 
  arr_servo[5].write(0);
  arr_servo[7].write(180); 
  arr_servo[6].write(80) ;
  arr_servo[8].write(0);   
  delay(500);
  arr_servo[6].write(0); 
  arr_servo[7].write(180); 
  arr_servo[8].write(80);
  delay(500);
  arr_servo[7].write(80); 
  arr_servo[6].write(0);
  arr_servo[8].write(180);
  delay(500);
  arr_servo[6].write(0); 
  arr_servo[7].write(180); 
  arr_servo[8].write(80);
  delay(500);  
  arr_servo[7].write(180); 
  arr_servo[6].write(80) ;
  arr_servo[8].write(0);   
  delay(500);
  arr_servo[6].write(0); 
  arr_servo[7].write(180); 
  arr_servo[8].write(80);
  delay(500);  
  arr_servo[7].write(80); 
  arr_servo[6].write(0);
  arr_servo[8].write(180);
  delay(500);    
  arr_servo[6].write(0); 
  arr_servo[7].write(180); 
  arr_servo[8].write(80);
 
}

void dance2(){
  arr_servo[4].write(80); 
  arr_servo[5].write(80);
  arr_servo[7].write(180); 
  arr_servo[6].write(80);
  arr_servo[8].write(0);
  delay(500);
  arr_servo[6].write(0); 
  arr_servo[7].write(180); 
  arr_servo[8].write(80);
  delay(500);  
  arr_servo[7].write(80); 
  arr_servo[6].write(0);
  arr_servo[8].write(180);  
  delay(500);
  arr_servo[6].write(0); 
  arr_servo[7].write(180); 
  arr_servo[8].write(80);
  delay(500);    
  arr_servo[7].write(180); 
  arr_servo[6].write(80) ;
  arr_servo[8].write(0);  
  delay(500);
  arr_servo[6].write(0); 
  arr_servo[7].write(180); 
  arr_servo[8].write(80);
  delay(500);    
  arr_servo[7].write(80); 
  arr_servo[6].write(0);
  arr_servo[8].write(180);
  delay(500);     
  arr_servo[6].write(0); 
  arr_servo[7].write(180); 
  arr_servo[8].write(80);
   
}

void walkForward(){

      int arrforwardBendLeft[4][26] = {
                        { 80,  85,  90,  95,  100,  105,  110,  115,  120,  125, 130, 130, 130,
                          130, 130, 130, 125, 120, 115, 110, 105, 100, 95, 90, 85, 80}, // LEFT FOOT
                        { 80,  85,  90,  95,  100,  105,  110,  115,  120,  125, 130, 135, 140,
                          140, 135, 130, 125, 120, 115, 110, 105, 100, 95, 90, 85, 80}, // RIGHT FOOT
                        { 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 
                          80,  75,  70,  65,  60,  55,  50,  45,  40,  40, 40, 40, 40 },  // LEFT HIP
                        { 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 
                          80,  75,  70,  65,  60,  55,  50,  50,  50,  50, 50, 50, 50}, // RIGHT HIP                        
                     };

      int arrforwardBendRight[4][26] = {
                        { 80,  75,  70,  65,  60,  55,  50,  45,  40,  35, 30, 25, 20,
                          20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80 }, // LEFT FOOT
                        { 80,  75,  70,  65,  65,  65,  65,  65,  65,  65, 65, 65, 65,
                          65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 70, 75, 80},  // RIGHT FOOT
                          
                        { 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40,
                          40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100 },  // LEFT HIP
                        { 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50,
                          50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100, 105, 110}, // RIGHT HIP                         
                     };                                         

        for (int ctr=0; ctr<26; ctr++)
        {
          if(arrforwardBendLeft[0][ctr] > 115){
            arr_servo[2].write(115); 
          }
          else{
            arr_servo[2].write(arrforwardBendLeft[0][ctr]);
          }          
           
          arr_servo[3].write(arrforwardBendLeft[1][ctr]); 
          arr_servo[0].write(arrforwardBendLeft[2][ctr]); 
          arr_servo[1].write(arrforwardBendLeft[3][ctr]);                    
          delay(100);
        }

        for (int ctr=0; ctr<26; ctr++)
        {
          arr_servo[2].write(arrforwardBendRight[0][ctr]); 
          arr_servo[3].write(arrforwardBendRight[1][ctr]); 
          arr_servo[0].write(arrforwardBendRight[2][ctr]); 
          arr_servo[1].write(arrforwardBendRight[3][ctr]);                      
          delay(100);
        }

}

void walkBackward(){
      int arrbackwardBendLeft[4][26] = {
                        { 80,  85,  90,  95,  100,  105,  110,  115,  120,  120, 120, 120, 120,
                          120, 120, 120, 120, 120, 115, 110, 105, 100, 95, 90, 85, 80}, // LEFT FOOT
                        { 80,  85,  90,  95,  100,  105,  110,  115,  120,  125, 130, 135, 140,
                          140, 135, 130, 125, 120, 115, 110, 105, 100, 95, 90, 85, 80}, // RIGHT FOOT
                        { 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 
                          80,  95,  100,  105,  110,  115,  115,  115,  115,  115, 115, 115, 115 },  // LEFT HIP
                        { 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 
                          80,  95,  100,  105,  110,  115,  115,  115,  115,  115, 115, 115, 115}, // RIGHT HIP                        
                     };

      int arrbackwardBendRight[4][26] = {
                        { 80,  75,  70,  65,  60,  55,  50,  45,  40,  35, 30, 25, 20,
                          20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80 }, // LEFT FOOT
                        { 80,  75,  70,  65,  65,  65,  65,  65,  65,  65, 65, 65, 65,
                          65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 70, 75, 80},  // RIGHT FOOT
                        { 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115,
                          115, 110, 105, 100, 95, 90, 85, 80, 75, 70, 65, 60, 55 },  // LEFT HIP
                        {  115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115,
                          115, 110, 105, 100, 95, 90, 85, 80, 75, 70, 65, 60, 55}, // RIGHT HIP                         
                     };   
        for (int ctr=0; ctr<26; ctr++)
        {
          arr_servo[2].write(arrbackwardBendLeft[0][ctr]); 
          arr_servo[3].write(arrbackwardBendLeft[1][ctr]); 
          arr_servo[0].write(arrbackwardBendLeft[2][ctr]); 
          arr_servo[1].write(arrbackwardBendLeft[3][ctr]);                    
          delay(100);
        }
        for (int ctr=0; ctr<26; ctr++)
        {
          arr_servo[2].write(arrbackwardBendRight[0][ctr]); 
          arr_servo[3].write(arrbackwardBendRight[1][ctr]); 
          arr_servo[0].write(arrbackwardBendRight[2][ctr]); 
          arr_servo[1].write(arrbackwardBendRight[3][ctr]);                    
          delay(100);
        } 
}
        
void turnRight(){
        int arrTurnRight[4][26] = {
                        { 80,  85,  90,  95,  100,  105,  110,  115,  120,  125, 130, 130, 130,
                          130, 130, 130, 125, 120, 115, 110, 105, 100, 95, 90, 85, 80},// LEFT FOOT
                        { 80,  85,  90,  95,  100,  105,  110,  115,  120,  125, 130, 135, 140,
                          140, 135, 130, 125, 120, 115, 110, 105, 100, 95, 90, 85, 80},// RIGHT FOOT
                        { 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 
                          80,  75,  70,  65,  60,  55,  50,  45,  40,  40, 40, 40, 40 },// LEFT HIP
                        { 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 
                          80,  75,  70,  65,  60,  55,  50,  50,  50,  50, 50, 50, 50},// RIGHT HIP                        
                     };
                       
        for (int ctr=0; ctr<26; ctr++)
        {
          if(arrTurnRight[0][ctr] > 115){
            arr_servo[2].write(115); 
          }
          else{
            arr_servo[2].write(arrTurnRight[0][ctr]);
          }          
          arr_servo[3].write(arrTurnRight[1][ctr]); 
          arr_servo[0].write(arrTurnRight[2][ctr]); 
          arr_servo[1].write(arrTurnRight[3][ctr]);                    
          delay(100);
        }    
}

void turnLeft(){
      int arrTurnLeft[4][26] = {
                        { 80,  75,  70,  65,  60,  55,  50,  45,  40,  35, 30, 25, 20,
                          20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80 }, // LEFT FOOT
                        { 80,  75,  70,  65,  60,  55,  50,  50,  50,  50, 50, 50, 50,
                          50, 50, 50, 50, 50, 50, 50, 55, 60, 65, 70, 75, 80},  // RIGHT FOOT
                          
                        { 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80,
                          80, 85, 90, 95, 100, 105, 110, 115, 120, 120, 120, 120, 120 },  // LEFT HIP
                        { 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80,
                          80, 85, 90, 95, 100, 105, 110, 115, 120, 120, 120, 120, 120}, // RIGHT HIP                         
                     };   
        for (int ctr=0; ctr<26; ctr++)
        {
          arr_servo[2].write(arrTurnLeft[0][ctr]); 
          
          if(arrTurnLeft[1][ctr] <65){
            arr_servo[3].write(65); 
          }
          else{
            arr_servo[3].write(arrTurnLeft[1][ctr]); 
          }           
          
          arr_servo[0].write(arrTurnLeft[2][ctr]); 
          arr_servo[1].write(arrTurnLeft[3][ctr]);                    
          delay(100);
        }  
}       

void reset(){ 
    digitalWrite(eyesLED, HIGH);
    digitalWrite(mouthLED, LOW);  
  arr_servo[0].write(80); 
  arr_servo[1].write(80); 
  arr_servo[2].write(80); 
  arr_servo[3].write(80);
  
  arr_servo[4].write(80); 
  arr_servo[5].write(80); 
  arr_servo[6].write(20); 
  arr_servo[7].write(180);   
  arr_servo[8].write(85); 
}
