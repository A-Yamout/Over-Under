/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Wed Sep 25 2019                                           */
/*    Description:  Split Arcade                                              */
/*    This sample allows you to control the V5 Clawbot using the both         */
/*    joystick. Adjust the deadband value for more accurate movements.        */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller
// LeftMotor            motor         1
// RightMotor           motor         10
// ClawMotor            motor         3
// ArmMotor             motor         8
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

void config()
{
  ArmMotorLeft.setStopping(hold);
  ArmMotorRight.setStopping(hold);
  ClawMotor.setStopping(hold);
}

int main() {
  config();
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // Deadband stops the motors when Axis values are close to zero.
  int deadband = 5;

  while (true) {
    
    if (Controller1.ButtonL2.pressing()) {
      ArmMotorLeft.spin(forward);
      ArmMotorRight.spin(reverse);
    } else if (Controller1.ButtonL1.pressing()) {
      ArmMotorLeft.spin(reverse);
      ArmMotorRight.spin(forward);
    } else {
      ArmMotorLeft.stop();
      ArmMotorRight.stop();
    }

    if (Controller1.ButtonR1.pressing()) {
      ClawMotor.spin(forward);
    } else if (Controller1.ButtonR2.pressing()) {
      ClawMotor.spin(reverse);
    } else {
      ClawMotor.stop();
    }
    // Get the velocity percentage of the left motor. (Axis3 + Axis1)
    int FrontLeftMotorSpeed =
        -Controller1.Axis3.position() + Controller1.Axis1.position() + Controller1.Axis4.position();
    int FrontRightMotorSpeed =
        Controller1.Axis3.position() + Controller1.Axis1.position()+ Controller1.Axis4.position();
    int BackLeftMotorSpeed = 
        Controller1.Axis3.position() + Controller1.Axis1.position()- Controller1.Axis4.position();
    int BackRightMotorSpeed = 
        Controller1.Axis3.position() - Controller1.Axis1.position()+ Controller1.Axis4.position();
    // Set the speed of the left motor. If the value is less than the deadband,
    // set it to zero.
    if (abs(FrontLeftMotorSpeed) < deadband) {
      // Set the speed to zero.
      FrontLeftMotor.setVelocity(0, percent);
    } else {
      // Set the speed to leftMotorSpeed
      FrontLeftMotor.setVelocity(FrontLeftMotorSpeed, percent);
    }

    // Set the speed of the right motor. If the value is less than the deadband,
    // set it to zero.
    if (abs(FrontRightMotorSpeed) < deadband) {
      // Set the speed to zero
      FrontRightMotor.setVelocity(0, percent);
    } else {
      // Set the speed to rightMotorSpeed
      FrontRightMotor.setVelocity(FrontRightMotorSpeed, percent);
    }
   if (abs(BackLeftMotorSpeed) < deadband) {
      // Set the speed to zero
      BackLeftMotor.setVelocity(0, percent);
    } else {
      // Set the speed to rightMotorSpeed
      BackLeftMotor.setVelocity(BackLeftMotorSpeed, percent);
    }
   if (abs(BackRightMotorSpeed) < deadband) {
      // Set the speed to zero
      BackRightMotor.setVelocity(0, percent);
    } else {
      // Set the speed to rightMotorSpeed
      BackRightMotor.setVelocity(BackRightMotorSpeed, percent);
    }

    // Spin both motors in the forward direction.
    BackLeftMotor.spin(forward);
    BackRightMotor.spin(forward);
    FrontLeftMotor.spin(forward);
    FrontRightMotor.spin(forward);

    wait(25, msec);
  }
}
