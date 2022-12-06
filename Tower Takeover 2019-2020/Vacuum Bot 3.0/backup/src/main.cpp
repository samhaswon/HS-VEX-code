// Team 4264A
// Vacuum Bot 3.0 
#include "vex.h"

using namespace vex;

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

void pre_auton( void ) {
  
  
}

void autonomous( void ) {
  
// Auton Stuffs 
    
  Brain.setTimer(15,timeUnits::sec);

  Brain.Screen.clearScreen( vex::color::black );
  Brain.Screen.print("          AUTONOMOUS");

  DriveR1.spin(directionType::fwd, 50, velocityUnits::pct);
  DriveR2.spin(directionType::fwd, 50, velocityUnits::pct);
  DriveL1.spin(directionType::fwd, 50, velocityUnits::pct);
  DriveL2.spin(directionType::fwd, 50, velocityUnits::pct);
  CubeSuck1.spin(directionType::rev, 175, velocityUnits::rpm);
  CubeSuck2.spin(directionType::rev, 175, velocityUnits::rpm); 
  task::sleep(1550);

  DriveR1.stop(brakeType::brake);
  DriveR2.stop(brakeType::brake);
  DriveL1.stop(brakeType::brake);
  DriveL2.stop(brakeType::brake);
  CubeSuck1.stop(brakeType::brake);
  CubeSuck2.stop(brakeType::brake);
  task::sleep(100);
      
  DriveR1.spin(directionType::rev, 50, velocityUnits::pct);
  DriveR2.spin(directionType::rev, 50, velocityUnits::pct);
  DriveL1.spin(directionType::fwd, 50, velocityUnits::pct);
  DriveL2.spin(directionType::fwd, 50, velocityUnits::pct);
  task::sleep(850);

  DriveR1.spin(directionType::fwd, 50, velocityUnits::pct);
  DriveR2.spin(directionType::fwd, 50, velocityUnits::pct);
  DriveL1.spin(directionType::fwd, 50, velocityUnits::pct);
  DriveL2.spin(directionType::fwd, 50, velocityUnits::pct);
  CubeSuck1.spin(directionType::rev, 175, velocityUnits::rpm);
  CubeSuck2.spin(directionType::rev, 175, velocityUnits::rpm); 
  task::sleep(750);

  DriveR1.spin(directionType::fwd, 12, velocityUnits::pct);
  DriveR2.spin(directionType::fwd, 12, velocityUnits::pct);
  DriveL1.spin(directionType::fwd, 10, velocityUnits::pct);
  DriveL2.spin(directionType::fwd, 10, velocityUnits::pct);
  CubeSuck1.spin(directionType::rev, 175, velocityUnits::rpm);
  CubeSuck2.spin(directionType::rev, 175, velocityUnits::rpm); 
  task::sleep(200);

  DriveR1.spin(directionType::fwd, 50, velocityUnits::pct);
  DriveR2.spin(directionType::fwd, 50, velocityUnits::pct);
  DriveL1.spin(directionType::fwd, 50, velocityUnits::pct);
  DriveL2.spin(directionType::fwd, 50, velocityUnits::pct);
  CubeSuck1.spin(directionType::rev, 175, velocityUnits::rpm);
  CubeSuck2.spin(directionType::rev, 175, velocityUnits::rpm); 
  task::sleep(1200);

  DriveR1.spin(directionType::fwd, 12, velocityUnits::pct);
  DriveR2.spin(directionType::fwd, 12, velocityUnits::pct);
  DriveL1.spin(directionType::fwd, 10, velocityUnits::pct);
  DriveL2.spin(directionType::fwd, 10, velocityUnits::pct);
  CubeSuck1.spin(directionType::rev, 175, velocityUnits::rpm);
  CubeSuck2.spin(directionType::rev, 175, velocityUnits::rpm); 
  task::sleep(200);

  DriveR1.spin(directionType::rev, 50, velocityUnits::pct);
  DriveR2.spin(directionType::rev, 50, velocityUnits::pct);
  DriveL1.spin(directionType::fwd, 50, velocityUnits::pct);
  DriveL2.spin(directionType::fwd, 50, velocityUnits::pct);
  task::sleep(500);

  DriveR1.spin(directionType::fwd, 50, velocityUnits::pct);
  DriveR2.spin(directionType::fwd, 50, velocityUnits::pct);
  DriveL1.spin(directionType::fwd, 50, velocityUnits::pct);
  DriveL2.spin(directionType::fwd, 50, velocityUnits::pct);
  CubeSuck1.spin(directionType::rev, 175, velocityUnits::rpm);
  CubeSuck2.spin(directionType::rev, 175, velocityUnits::rpm); 
  task::sleep(1800);

  DriveR1.stop(brakeType::brake);
  DriveR2.stop(brakeType::brake);
  DriveL1.stop(brakeType::brake);
  DriveL2.stop(brakeType::brake);
  CubeSuck1.stop(brakeType::brake);
  CubeSuck2.stop(brakeType::brake);
  task::sleep(10);

  CubeSuck1.spin(directionType::fwd, 150, velocityUnits::rpm);
  CubeSuck2.spin(directionType::fwd, 150, velocityUnits::rpm); 
  task::sleep(200);

  StackAngle.spin(directionType::rev, 60, velocityUnits::rpm);
  CubeSuck1.stop(brakeType::coast);
  CubeSuck2.stop(brakeType::coast);
  task::sleep(3700);

  DriveR1.spin(directionType::rev, 30, velocityUnits::pct);
  DriveR2.spin(directionType::rev, 30, velocityUnits::pct);
  DriveL1.spin(directionType::rev, 30, velocityUnits::pct);
  DriveL2.spin(directionType::rev, 30, velocityUnits::pct);
  StackAngle.spin(directionType::fwd, 35, velocityUnits::rpm);
  task::sleep(200);

  StackAngle.spin(directionType::fwd, 200, velocityUnits::rpm);
  task::sleep(300);

  DriveR1.spin(directionType::rev, 50, velocityUnits::pct);
  DriveR2.spin(directionType::rev, 50, velocityUnits::pct);
  DriveL1.spin(directionType::rev, 50, velocityUnits::pct);
  DriveL2.spin(directionType::rev, 50, velocityUnits::pct);
  StackAngle.spin(directionType::fwd, 75, velocityUnits::rpm);
  task::sleep(1200);
    
  //all stop
  DriveR1.stop(brakeType::brake);
  DriveR2.stop(brakeType::brake);
  DriveL1.stop(brakeType::brake);
  DriveL2.stop(brakeType::brake);
  CubeSuck1.stop(brakeType::brake);
  CubeSuck2.stop(brakeType::brake);
}



void drivercontrol( void ) {
  
  while (true) {
    
    // Autonomous Switch
    if(Controller1.ButtonB.pressing()){
      autonomous();
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
    
    
    // Cube intake angle: forward is up, reverse is down
    if(Controller1.ButtonR1.pressing()) {
      IntakeAngle.spin(directionType::fwd, 200, velocityUnits::rpm);
    }
    else if(Controller1.ButtonR2.pressing()) {
      IntakeAngle.spin(directionType::rev, 200, velocityUnits::rpm);
    }
    else{
      IntakeAngle.stop(brakeType::hold);
    }
    
    // Sticky intake button
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

    // Primary drive controls
    DriveR1.spin(vex::directionType::fwd, (Controller1.Axis3.value() + Controller1.Axis1.value())/1, vex::velocityUnits::pct);
    DriveR2.spin(vex::directionType::fwd, (Controller1.Axis3.value() + Controller1.Axis1.value())/1, vex::velocityUnits::pct);
    DriveL1.spin(vex::directionType::fwd, (Controller1.Axis3.value() - Controller1.Axis1.value())/1, vex::velocityUnits::pct);
    DriveL2.spin(vex::directionType::fwd, (Controller1.Axis3.value() - Controller1.Axis1.value())/1, vex::velocityUnits::pct);

    // Delay to prevent wasted resources
    vex::task::sleep(20); 
  }
}


int main() {
    //Set up callbacks for autonomous and driver control periods.
    Competition.autonomous( autonomous );
    Competition.drivercontrol( drivercontrol );
     
    pre_auton();
                      
    while(1) {

      if(Brain.timer(timeUnits::sec) == 0){
        drivercontrol();
      }

      //Sleep the task for a short amount of time to prevent wasted resources.
      vex::task::sleep(100);
    }    
       
}