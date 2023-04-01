/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\samue                                            */
/*    Created:      Thu Jun 04 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// DriveR1              motor         5               
// DriveR2              motor         6               
// DriveL1              motor         7               
// DriveL2              motor         8               
// L_Intake             motor         9               
// R_Intake             motor         10              
// FlingyBoi1           motor         11              
// FlingyBoi2           motor         12              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "robot-config.h"

using namespace vex;

vex::competition    Competition;


void pre_auton( void ) {
  return;

}

void autonomous( void ) {
  return;
}

void drivercontrol( void ) {
  while(true){

    // Autonomous Switch
    if(Controller1.ButtonB.pressing()){
      autonomous();
    } 

    // Intake
    if(Controller1.ButtonL1.pressing()){
      L_Intake.spin(directionType::fwd, 100, velocityUnits::pct);
      R_Intake.spin(directionType::fwd, 100, velocityUnits::pct);
    }
    else if(Controller1.ButtonL2.pressing()){
      L_Intake.spin(directionType::rev, 100, velocityUnits::pct);
      R_Intake.spin(directionType::rev, 100, velocityUnits::pct);
    }
    else {
      L_Intake.stop(brakeType::coast);
      R_Intake.stop(brakeType::coast);
    }

    // Score 
    if(Controller1.ButtonR1.pressing()){
      FlingyBoi1.spin(directionType::fwd, 100, velocityUnits::pct);
      FlingyBoi2.spin(directionType::fwd, 100, velocityUnits::pct);
    }
    else if(Controller1.ButtonR2.pressing()){
      FlingyBoi1.spin(directionType::rev, 100, velocityUnits::pct);
      FlingyBoi2.spin(directionType::rev, 100, velocityUnits::pct);
    }
    else {
      FlingyBoi1.stop(brakeType::coast);
      FlingyBoi2.stop(brakeType::coast);
    }    
  }
}

int main() {
  // Run the pre-autonomous function.
  pre_auton();

  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(drivercontrol);

  while (true) {
    vex::task::sleep(75); 
    /* Brain.Screen.setCursor(1, 1); 
    Brain.Screen.clearScreen(vex::color::black); 
    Brain.Screen.print(rightMotorA.current()); 
    Brain.Screen.newLine();
    Brain.Screen.print(rightMotorB.current()); 
    Brain.Screen.newLine();
    Brain.Screen.print(leftMotorA.current()); 
    Brain.Screen.newLine();
    Brain.Screen.print(leftMotorB.current()); */
  }
}
