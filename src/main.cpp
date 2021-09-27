/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// FrontRightBase       motor         1               
// FrontLeftBase        motor         2               
// BackRightBase        motor         3               
// BackLeftBase         motor         4               
// Conveyor             motor         20              
// Bar                  motor         11              
// TopLift              motor         8               
// BottomLift           motor         6               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
vex::competition Competition;


using namespace vex;



// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
  TopLift.resetPosition();
  BottomLift.resetPosition();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  while (1) {
    FrontRightBase.spin(directionType::fwd, Controller1.Axis2.position()*0.35,percentUnits::pct);
    BackRightBase.spin(directionType::fwd, Controller1.Axis2.position()*0.35, percentUnits::pct);
    FrontLeftBase.spin(directionType::fwd, Controller1.Axis3.position()*0.35, percentUnits::pct);
    BackLeftBase.spin(directionType::fwd, Controller1.Axis3.position()*0.35, percentUnits::pct);

    if (Controller1.ButtonL1.pressing()) {
      Conveyor.spin(directionType::fwd,50,percentUnits::pct);
    } else if (Controller1.ButtonL2.pressing()) {
      Conveyor.spin(directionType::rev,50,percentUnits::pct);
    } else {
      Conveyor.stop();
    }

    if (Controller1.ButtonA.pressing()){
      Bar.spin(directionType::fwd, 25, percentUnits::pct);
    } else if (Controller1.ButtonB.pressing()){
      Bar.spin(directionType::rev, 25, percentUnits::pct);
    } else {
      Bar.stop();
    }

    if (Controller1.ButtonR1.pressing()) {
      BottomLift.spin(forward, 15, velocityUnits::pct);
      TopLift.spin(reverse, 15, velocityUnits::pct);
    } else if(Controller1.ButtonR2.pressing()) {
      BottomLift.spin(reverse, 15, velocityUnits::pct);
      TopLift.spin(forward, 15, velocityUnits::pct);
    } else if(!(Controller1.ButtonR1.pressing() && Controller1.ButtonR2.pressing())) {
      BottomLift.stop();
      TopLift.stop();
    }

  }
}

 
  


//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
