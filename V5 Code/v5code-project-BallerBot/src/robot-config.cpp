#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);

motor leftMotorA = motor(PORT7, ratio18_1, false);
motor leftMotorB = motor(PORT8, ratio18_1, false);
motor_group LeftDriveSmart = motor_group(leftMotorA, leftMotorB);

motor rightMotorA = motor(PORT5, ratio18_1, true); 
motor rightMotorB = motor(PORT6, ratio18_1, true); 
motor_group RightDriveSmart = motor_group(rightMotorA, rightMotorB);

drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 319.19, 230, 192, mm, 1);
motor L_Intake = motor(PORT9, ratio18_1, false);
motor R_Intake = motor(PORT10, ratio18_1, true);
motor FlingyBoi1 = motor(PORT11, ratio18_1, false);
motor FlingyBoi2 = motor(PORT12, ratio18_1, true);



// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

// define variables used for controlling motors based on controller inputs
bool DrivetrainLNeedsToBeStopped_Controller1 = true;
bool DrivetrainRNeedsToBeStopped_Controller1 = true;

// define a task that will handle monitoring inputs from Controller1
int rc_auto_loop_callback_Controller1() {
  // process the controller input every 20 milliseconds
  // update the motors based on the input values
  while(true) {
    if(RemoteControlCodeEnabled) {

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

    // Score Boi
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

      // calculate the drivetrain motor velocities from the controller joystick axies
      // left = Axis3 + Axis1
      // right = Axis3 - Axis1
      int drivetrainLeftSideSpeed = Controller1.Axis3.position() + Controller1.Axis1.position();
      int drivetrainRightSideSpeed = Controller1.Axis3.position() - Controller1.Axis1.position();
      // check if the value is inside of the deadband range
      if (drivetrainLeftSideSpeed < 5 && drivetrainLeftSideSpeed > -5) {
        // check if the left motor has already been stopped
        if (DrivetrainLNeedsToBeStopped_Controller1) {
          // stop the left drive motor
          LeftDriveSmart.stop(brakeType::hold);
          // tell the code that the left motor has been stopped
          DrivetrainLNeedsToBeStopped_Controller1 = false;
        }
      } else {
        // reset the toggle so that the deadband code knows to stop the left motor next time the input is in the deadband range
        DrivetrainLNeedsToBeStopped_Controller1 = true;
      }
      // check if the value is inside of the deadband range
      if (drivetrainRightSideSpeed < 5 && drivetrainRightSideSpeed > -5) {
        // check if the right motor has already been stopped
        if (DrivetrainRNeedsToBeStopped_Controller1) {
          // stop the right drive motor
          RightDriveSmart.stop(brakeType::hold);
          // tell the code that the right motor has been stopped
          DrivetrainRNeedsToBeStopped_Controller1 = false;
        }
      } else {
        // reset the toggle so that the deadband code knows to stop the right motor next time the input is in the deadband range
        DrivetrainRNeedsToBeStopped_Controller1 = true;
      }
      // only tell the left drive motor to spin if the values are not in the deadband range
      if (DrivetrainLNeedsToBeStopped_Controller1) {
        LeftDriveSmart.setVelocity(drivetrainLeftSideSpeed, percent);
        LeftDriveSmart.spin(forward);
      }
      // only tell the right drive motor to spin if the values are not in the deadband range
      if (DrivetrainRNeedsToBeStopped_Controller1) {
        RightDriveSmart.setVelocity(drivetrainRightSideSpeed, percent);
        RightDriveSmart.spin(forward);
      }
    }
    // wait before repeating the process
    wait(20, msec);
  }
  return 0;
}

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {

  task rc_auto_loop_task_Controller1(rc_auto_loop_callback_Controller1);
while (true) {
    vex::task::sleep(75); 
    Brain.Screen.setCursor(1, 1); 
    Brain.Screen.clearScreen(vex::color::black); 
    Brain.Screen.print(rightMotorA.current()); 
    Brain.Screen.newLine();
    Brain.Screen.print(rightMotorB.current()); 
    Brain.Screen.newLine();
    Brain.Screen.print(leftMotorA.current()); 
    Brain.Screen.newLine();
    Brain.Screen.print(leftMotorB.current()); 
  }
}
