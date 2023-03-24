#ifndef _GAELLIB_ODOM_H_
#define _GAELLIB_ODOM_H_

#include "gaellib/Point.hpp"
#include "api.h"
#include <memory>

namespace gaellib::odom {

typedef enum EncoderType { ENCODER_ADI, ENCODER_ROTATION } EncoderType_e_t;

// Odom Configuration
typedef struct config_data_s {
	int expanderPort = 0;
    int rightEncoderPort = 0;
    int leftEncoderPort = 0;
	int middleEncoderPort = 0;
    int imuPort = 0;
    EncoderType_e_t encoderType;
} config_data_s_t;

// sensors
extern std::shared_ptr<pros::Imu> imu;


double getLeftEncoder();


double getRightEncoder();


double getMiddleEncoder();


Point getPosition();


double getHeading(bool radians = false);


void reset(Point point = {0, 0});


void reset(Point point, double angle);


double getAngleError(Point point);


double getDistanceError(Point point);


void init(bool debug, EncoderType_e_t encoderType, std::array<int, 3> encoderPorts,
          int expanderPort, int imuPort, double track_width,
          double middle_distance, double tpi, double middle_tpi);

} 

#endif
