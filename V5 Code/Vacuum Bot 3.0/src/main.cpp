// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  // Global variable declaration
  // Brain
  vex::brain Brain;

  // Declares as a competition program
  vex::competition Competition;

  // Controller
  vex::controller Controller1;

  // Motors

  // Drive
  vex::motor DriveR1(vex::PORT1,false);
  vex::motor DriveR2(vex::PORT2,false);
  vex::motor DriveL1(vex::PORT9,true);
  vex::motor DriveL2(vex::PORT10,true);

  // Stack
  vex::motor StackAngle(vex::PORT5,false);

  //Intake
  vex::motor IntakeAngle(vex::PORT4,false);
  vex::motor CubeSuck1(vex::PORT3,false);
  vex::motor CubeSuck2(vex::PORT7,true);

}

//vex::motor IntakeAngle(vex::PORT4,false);

void autonomous( void ) {
// Auton Stuffs 
    
  Brain.setTimer(15,timeUnits::sec);

  Brain.Screen.clearScreen( vex::color::black );
  Brain.Screen.print("          AUTONOMOUS");

  
}

void drivercontrol( void ) {
  

  // Global variable declaration
  // Brain
  vex::brain Brain;

  // Declares as a competition program
  vex::competition Competition;

  // Controller
  vex::controller Controller1;

  // Motors

  // Drive
  vex::motor DriveR1(vex::PORT1,false);
  vex::motor DriveR2(vex::PORT2,false);
  vex::motor DriveL1(vex::PORT9,true);
  vex::motor DriveL2(vex::PORT10,true);

  // Stack
  vex::motor StackAngle(vex::PORT5,false);

  //Intake
  vex::motor IntakeAngle(vex::PORT4,false);
  vex::motor CubeSuck1(vex::PORT3,false);
  vex::motor CubeSuck2(vex::PORT7,true);

  while (true) {
    
    // Autonomous Switch
    if(Controller1.ButtonB.pressing()){
      autonomous();
    }

// Intake button
    if(Controller1.ButtonL1.pressing()){
      CubeSuck1.spin(directionType::rev, 175, velocityUnits::rpm);
      CubeSuck2.spin(directionType::rev, 175, velocityUnits::rpm);
    }
    else if(Controller1.ButtonL2.pressing()){
      CubeSuck1.spin(directionType::fwd, 100, velocityUnits::rpm);
      CubeSuck2.spin(directionType::fwd, 100, velocityUnits::rpm);
    }
    else{
      CubeSuck1.stop(brakeType::coast);
      CubeSuck2.stop(brakeType::coast);
    }

    // Cube intake angle: forward is up, reverse is down
    if(Controller1.ButtonR1.pressing()) {
      IntakeAngle.spin(directionType::fwd, 100, velocityUnits::pct);
    }
    else if(Controller1.ButtonR2.pressing()) {
      IntakeAngle.spin(directionType::rev, 100, velocityUnits::pct);
    }
    else{
      IntakeAngle.stop(brakeType::hold);
    }

    // Cube stack angle adjustment using the arrow pad
    if(Controller1.ButtonDown.pressing()) {
      StackAngle.spin(directionType::fwd, 200, velocityUnits::rpm);
    }
    else if(Controller1.ButtonUp.pressing()) {
      StackAngle.spin(directionType::rev, 60, velocityUnits::rpm);
    }
    else{
      StackAngle.stop(brakeType::hold);
    }

    // Primary drive controls
    DriveR1.spin(vex::directionType::fwd, (Controller1.Axis3.value() + Controller1.Axis1.value())/1, vex::velocityUnits::pct);
    DriveR2.spin(vex::directionType::fwd, (Controller1.Axis3.value() + Controller1.Axis1.value())/1, vex::velocityUnits::pct);
    DriveL1.spin(vex::directionType::fwd, (Controller1.Axis3.value() - Controller1.Axis1.value())/1, vex::velocityUnits::pct);
    DriveL2.spin(vex::directionType::fwd, (Controller1.Axis3.value() - Controller1.Axis1.value())/1, vex::velocityUnits::pct);

  }
}