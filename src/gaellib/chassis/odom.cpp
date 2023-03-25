#include "gaellib/api.hpp"
#define sin(r) sin(r / 180 * M_PI)
#define cos(r) cos(r / 180 * M_PI)
#define M_PI 3.14
namespace gaellib::odom{

void calcWheelVals(double dis, double ang){
  double x = dis * cos(ang); 
  double y = dis * sin(ang);
  IPos[0] += x;
  IPos[1] += y;
  IPos[2]  = 360.00 - inertial.get_heading();
}

void initialize(double fx, double fy, double orient){
  IPos[0] = fx;
  IPos[1] = fy;
  IPos[2] = orient;
  inertial.set_heading(360.00 - orient);
}

double a_tan(double ratio){
    return atan(ratio) * 180 / M_PI;
}

double calc_ang(double x1, double y1, double x2, double y2){
    int x = std::abs(x2-x1);
    int y = std::abs(y2-y1);
    if(x2>x1 && y2>y1){ //1st quadrant
        return (a_tan(y/x));
    }
    if(x2<x1 && y2>y1){ //2nd quadrant
        return 180 - (a_tan(y/x));
    }
    if(x2<x1 && y2<y1){ //3rd quadrant
        return 180 + (a_tan(y/x));
    }
    if(x2>x1 && y2<y1){ //4th quadrant
        return 360 - (a_tan(y/x));
    }
    return 0;
}
}