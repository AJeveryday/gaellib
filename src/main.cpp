#include "main.h"
#include <cmath>
#include <iostream>
#include <cstdio>

#define M_PI  3.1415926535
#define sin(r) sin(r / 180 * M_PI)
#define cos(r) cos(r / 180 * M_PI)
#define calc_distance(rot) rot / 360 * 2.75 * M_PI;
double TW_A_dis, TW_B_dis;
double prev_TW_A_dis, prev_TW_B_dis;
double target_ang;
bool dir = true;
double err=3, ang_accept=1;
double dis = 1, dis_accept = 0.3, prev_dis = -1, powVal;
gaellib::odom::robot now;

void record(){
using namespace gaellib::odom;
using namespace gaellib::purePursuit;

  while(true){
	
    TW_A_dis = calc_distance(TW_forw.get_position()/100); 
    TW_B_dis = calc_distance(TW_side.get_position()/100);
    gaellib::odom::calcWheelVals(TW_A_dis - prev_TW_A_dis, (360.00 - inertial.get_heading())); //to unit cirling it
    gaellib::odom::calcWheelVals(TW_B_dis - prev_TW_B_dis, std::fmod((360.00 - (inertial.get_heading()-90)), 360.00));
     //-90 coz perpendicular
    prev_TW_A_dis = TW_A_dis;
    prev_TW_B_dis = TW_B_dis;


	
	pros::lcd::print(1, "x position%f ", IPos[0]);
	pros::lcd::print(2, "y position%f ", IPos[1]);
	pros::lcd::print(3, "T:%f ", IPos[2]);
	pros::lcd::print(4, "Side encoder %f inches", TW_B_dis);
	pros::lcd::print(5, "Forward encoder %f inches", TW_A_dis);
	
	dis = get_dis({now.x, now.y}, {IPos[0], IPos[1]});
	pros::delay(10);
  }}




void initialize() {
	pros::lcd::initialize();
	//pros::lcd::set_text(1, "Hello PROS User!");
	TW_forw.reset_position();
	TW_side.reset_position();
	inertial.reset();
	gaellib::odom::initialize(0.00,0.00,360.0);
	pros::Task odom(record);
	
	
}


void disabled() {}


void competition_initialize() {}


void autonomous() {
	
	
	
}


void opcontrol() {
	

	while (true) {
		gaellib::drive::tank();
	}
}
