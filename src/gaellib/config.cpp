#include "gaellib/api.hpp"

//CONTROLLER
pros::Controller master(pros::E_CONTROLLER_MASTER);

//IMU
pros::Imu inertial(IMU_PORT);


//MOTORS
auto GEAR = pros::E_MOTOR_GEARSET_06;
pros::Motor LF(DRIVE_LF, GEAR, LEFTDIR);
pros::Motor LM(DRIVE_LM, GEAR, LEFTDIR);
pros::Motor LB(DRIVE_LB, GEAR, LEFTDIR);
pros::Motor RF(DRIVE_RF, GEAR, RIGHTDIR);
pros::Motor RM(DRIVE_RM, GEAR, RIGHTDIR);
pros::Motor RB(DRIVE_RB, GEAR, RIGHTDIR);

pros::Motor_Group left({LF,LM, LB});
pros::Motor_Group right({RF, RM, RB});

//ROTATIONAL 
