#ifndef _GAELLIB_PID_H_
#define _GAELLIB_PID_H_

#include <array>

namespace gaellib::pid {


// pid mode enums
extern int mode;
#define DISABLE 0
#define TRANSLATIONAL 1
#define ANGULAR 2




// pid functions
void pidlateral(double distance, double sv);
void pidturn(double angle, double sv);

// initializer
void init(double linearKP, double linearKI, double linearKD, double angularKP,
          double angularKI, double angularKD, double trackingKP, double minError, double leadPct);

}

#endif
