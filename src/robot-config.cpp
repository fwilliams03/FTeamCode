#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor FrontRightBase = motor(PORT1, ratio18_1, true);
motor FrontLeftBase = motor(PORT2, ratio18_1, false);
motor BackRightBase = motor(PORT3, ratio18_1, true);
motor BackLeftBase = motor(PORT4, ratio18_1, false);
motor Conveyor = motor(PORT20, ratio18_1, true);
motor Bar = motor(PORT11, ratio18_1, true);
motor TopLift = motor(PORT8, ratio36_1, true);
motor BottomLift = motor(PORT6, ratio18_1, true);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;
// define variables used for controlling motors based on controller inputs
bool Controller1LeftShoulderControlMotorsStopped = true;

// define a task that will handle monitoring inputs from Controller1
int rc_auto_loop_function_Controller1() {
  // process the controller input every 20 milliseconds
  // update the motors based on the input values
  while(true) {
    if(RemoteControlCodeEnabled) {
      // check the ButtonL1/ButtonL2 status to control Conveyor
      if (Controller1.ButtonL1.pressing()) {
        Conveyor.spin(forward);
        Controller1LeftShoulderControlMotorsStopped = false;
      } else if (Controller1.ButtonL2.pressing()) {
        Conveyor.spin(reverse);
        Controller1LeftShoulderControlMotorsStopped = false;
      } else if (!Controller1LeftShoulderControlMotorsStopped) {
        Conveyor.stop();
        // set the toggle so that we don't constantly tell the motor to stop when the buttons are released
        Controller1LeftShoulderControlMotorsStopped = true;
      }
    }
    // wait before repeating the process
    wait(20, msec);
  }
  return 0;
}

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  task rc_auto_loop_task_Controller1(rc_auto_loop_function_Controller1);
}