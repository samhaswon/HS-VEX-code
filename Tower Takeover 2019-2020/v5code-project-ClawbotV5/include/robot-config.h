using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor Drive1;
extern motor ClawHeight;
extern motor Claw;
extern motor Drive2;
extern controller Controller1;
extern limit LimitSwitchA;
extern limit LimitSwitchB;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );