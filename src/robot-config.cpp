#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor BackLeftMotor = motor(PORT1, ratio18_1, true);
motor BackRightMotor = motor(PORT3, ratio18_1, false);
motor FrontLeftMotor = motor(PORT4, ratio18_1, true);
motor FrontRightMotor = motor(PORT2, ratio18_1, true);
motor ClawMotor = motor(PORT10, ratio18_1, false);
motor ArmMotorRight = motor(PORT9, ratio18_1, false);
motor ArmMotorLeft = motor(PORT8, ratio18_1, false);

// VEXcode generated functions

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
  // nothing to initialize
}