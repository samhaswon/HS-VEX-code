#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor Drive1 = motor(PORT1, ratio18_1, true);
motor ClawHeight = motor(PORT3, ratio18_1, false);
motor Claw = motor(PORT8, ratio18_1, false);
motor Drive2 = motor(PORT10, ratio18_1, false);
controller Controller1 = controller(primary);
limit LimitSwitchA = limit(Brain.ThreeWirePort.A);
limit LimitSwitchB = limit(Brain.ThreeWirePort.B);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}