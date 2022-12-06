/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\samue                                            */
/*    Created:      Tue Mar 03 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drive1               motor         1               
// ClawHeight           motor         3               
// Claw                 motor         8               
// Drive2               motor         10              
// Controller1          controller                    
// LimitSwitchA         limit         A               
// LimitSwitchB         limit         B               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "robot-config.h"

using namespace vex;

vex::competition    Competition;


void pre_auton( void ) {
    
}

void autonomous( void ) {
    
}


void speed( void ) {
    
    //Use these variables to set the speed of the arm and claw.
    int armSpeedPCT = 50;
    int clawSpeedPCT = 25;
    
    Controller1.rumble("-");
    
    
    Brain.Screen.clearScreen( vex::color::black );
    Brain.Screen.print("4264");
    
    while (true) { 
        
        if(Controller1.ButtonY.pressing()){
        Drive1.setMaxTorque(25,percentUnits::pct);
        Drive2.setMaxTorque(25,percentUnits::pct);
        }
        
        if(Controller1.ButtonX.pressing()){
        Drive1.setMaxTorque(100,percentUnits::pct);
        Drive2.setMaxTorque(100,percentUnits::pct);

        }
        
        if(Controller1.ButtonA.pressing()){
            autonomous();
        }
        
        if(Controller1.ButtonL1.pressing()) {
          if(LimitSwitchA.pressing()){
            ClawHeight.stop(brakeType::hold);
          }
          else{
            ClawHeight.spin(directionType::rev, armSpeedPCT, velocityUnits::pct);
          }
        }
        else if(Controller1.ButtonL2.pressing()) {
          if(LimitSwitchB.pressing()){
            ClawHeight.stop(brakeType::hold);
          }
          else{
            ClawHeight.spin(directionType::fwd, armSpeedPCT, velocityUnits::pct);
          }
        }
        else {
            ClawHeight.stop(brakeType::hold);
        }

        if(Controller1.ButtonR1.pressing()) {
            Claw.spin(directionType::fwd, clawSpeedPCT, velocityUnits::pct);
        }
        else if(Controller1.ButtonR2.pressing()) {
            Claw.spin(directionType::rev, clawSpeedPCT, velocityUnits::pct);
        }
        else {
            Claw.stop(brakeType::hold);        
        }
        
        Drive2.spin(vex::directionType::fwd, Controller1.Axis3.value()+Controller1.Axis1.value(), vex::velocityUnits::pct);
        Drive1.spin(vex::directionType::fwd, Controller1.Axis3.value()-Controller1.Axis1.value(), vex::velocityUnits::pct);
        
        task::sleep(20);
    }
}

  
int main() {
    
    //Run the pre-autonomous function. 
    pre_auton();
    
    //Set up callbacks for autonomous and driver control periods.
    Competition.autonomous( autonomous );
    Competition.drivercontrol( speed );
    
    Controller1.Screen.clearScreen();
    Controller1.Screen.print("4264");
    
    //Prevent main from exiting with an infinite loop.                        
    while(1) {
        
        vex::task::sleep(75);   //Sleep the task for a short amount of time to prevent wasted resources.
    }    
       
}