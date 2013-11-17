/* Robot Line Follow Config V02

   This version fixes some errors currently present
   in the online version at: http://arduino.cc/en/Reference/RobotLineFollowConfig

   Circuit:
 * Arduino Robot

   modified 17 November 2013
   by Michele Maffucci
   17.11.13
   http://www.maffucci.it
 
   This example is in the public domain
*/ 
 
#include <ArduinoRobot.h>
long timer;

void setup(){
  Robot.begin();
  Robot.beginTFT();
  // example on-line has been wrongly inserted Robot.beginLCD();
  // The Robot class does not have a method beginLCD()
  // but a method beginTFT().

  delay(3000);

  Robot.lineFollowConfig(11,5,50,10); // set PID parameters
  Robot.setMode(MODE_LINE_FOLLOW);
  timer=millis();
  while(!Robot.isActionDone()){
    // pauses line-following for 3 seconds every 5 seconds
    if(millis()-timer>=5000){
      Robot.pauseMode(true);
      delay(3000);
      Robot.pauseMode(false);
      timer=millis();
    }
    Robot.debugPrint(millis());
  }
  Robot.text("Done!",0,10);
  // on-line version: Robot.text("Done!",0,10, true);
  // The syntax of text is Robot.text (towrite, x, y, writeOrErase),
  // but writeOrErase, which assumes the value true or false is not accepted
  while(true);

}
void loop(){
}

