#include "main.h"


//MOTOR PORTS
#define DRIVE_LF 18
#define DRIVE_LM 15
#define DRIVE_LB 20
#define DRIVE_RF 12
#define DRIVE_RM 13
#define DRIVE_RB 11

//DIRECTION
#define LEFTDIR false
#define RIGHTDIR true
//GEARSET



//IMU
#define IMU_PORT 21

//ROTATIONAL ENCODERS
#define RTL 7
#define RTR 8
#define RTB 9


//MOVEMENT
// Movement tuning
#define SLEW_STEP 8          // Smaller number = more slew
#define LINEAR_EXIT_ERROR 1 // default exit distance for linear movements
#define ANGULAR_EXIT_ERROR 1 // default exit distance for angular movements
#define SETTLE_THRESH_LINEAR .5      // amount of linear movement for settling
#define SETTLE_THRESH_ANGULAR 1      // amount of angular movement for settling
#define SETTLE_TIME 250      // amount of time to count as settled
#define LINEAR_KP 1
#define LINEAR_KI 0
#define LINEAR_KD 0
#define TRACKING_KP 1	 // point tracking turning strength
#define ANGULAR_KP 1
#define ANGULAR_KI 0
#define ANGULAR_KD 0
#define MIN_ERROR 5          // Minimum distance to target before angular componenet is disabled
#define LEAD_PCT .6		
//EXTERNS
extern pros::Controller master;
extern pros::Motor LF;
extern pros::Motor LM;
extern pros::Motor LB;
extern pros::Motor RF;
extern pros::Motor RM;
extern pros::Motor LB;
extern pros::Motor_Group left;
extern pros::Motor_Group right;
extern pros::Imu inertial;



