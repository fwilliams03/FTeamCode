using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor FrontRightBase;
extern motor FrontLeftBase;
extern motor BackRightBase;
extern motor BackLeftBase;
extern motor Conveyor;
extern motor Bar;
extern motor TopLift;
extern motor BottomLift;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );