#include "gaellib/api.hpp"

namespace gaellib::pid {
#define M_PI 3.14
#define M_PI_2 3.14


// constants
double linearKP;
double angularKP;
double linearKI;
double linearKD;
double angularKI;
double angularKD;
double trackingKP;
double minError;
double leadPct;
double leftPrev;
double rightPrev;
// integral
double in_lin;
double in_ang;

// kp defaults
double defaultLinearKP;
double defaultAngularKP;
double defaultTrackingKP;




void init(double linearKP, double linearKI, double linearKD, double angularKP,
          double angularKI, double angularKD, double trackingKP,
          double minError, double leadPct) {

	pid::defaultLinearKP = linearKP;
	pid::linearKI = linearKI;
	pid::linearKD = linearKD;
	pid::defaultAngularKP = angularKP;
	pid::angularKI = angularKI;
	pid::angularKD = angularKD;
	pid::defaultTrackingKP = trackingKP;
	pid::minError = minError;
	pid::leadPct = leadPct;
}

void leftmotorMove(double speed,
               bool velocity) {
	if (velocity)
		left.move_velocity(speed * (double)left.get_gearing()[0] / 100);
	else
		left.move_voltage(speed * 120);

	left= speed;
}


void rightmotorMove(double speed,
               bool velocity) {
	if (velocity)
		right.move_velocity(speed * (double)right.get_gearing()[0] / 100);
	else
		right.move_voltage(speed * 120);

	right= speed;
}

//pid function
double lateralpid(double error, double* pe, double* in, double kp, double ki,
           double kd) {

	double derivative = error - *pe;
	if ((*pe > 0 && error < 0) || (*pe < 0 && error > 0))
		*in = 0; // remove integral at zero error
	double speed = error * kp + *in * ki + derivative * kd;

	// only let integral wind up if near the target
	if (fabs(error) < 15) {
		*in += error;
	}

	*pe = error;

    leftmotorMove(speed, true);
    rightmotorMove(speed, true);

	return speed;
}


double angularpid(double error, double* pe, double* in, double kp, double ki,
           double kd) {

	double derivative = error - *pe;
	if ((*pe > 0 && error < 0) || (*pe < 0 && error > 0))
		*in = 0; // remove integral at zero error
	double speed = error * kp + *in * ki + derivative * kd;

	// only let integral wind up if near the target
	if (fabs(error) < 15) {
		*in += error;
	}

	*pe = error;

    leftmotorMove(speed, true);
    rightmotorMove(-speed, true);

	return speed;
}




void pidlateral(double target, double sv) {
	double error = target - sv;

	lateralpid(error, 0, 0, defaultLinearKP, linearKI, linearKD);
    
}
void pidturn(double target, double sv) {
	double error = target - sv;

	angularpid(error, 0, 0, defaultAngularKP, angularKI, angularKD);
    
}






double limitSpeed(double speed, double max) {
	if (speed > max)
		speed = max;
	if (speed < -max)
		speed = -max;

	return speed;
}



double slew(double target_speed, double step, double current_speed) {

	if (fabs(current_speed) > fabs(target_speed))
		step = 200;

	if (target_speed > current_speed + step)
		current_speed += step;
	else if (target_speed < current_speed - step)
		current_speed -= step;
	else
		current_speed = target_speed;

	return current_speed;
}







} 
