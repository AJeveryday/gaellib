#include "gaellib/api.hpp"

namespace gaellib{
    
    namespace drive{
        
        void tank(){
            auto leftstick = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
            auto rightstick = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);

            if(leftstick <= 10){
                left.move(0);
            }
            if(rightstick <= 10){
                right.move(0);
            }
            left.move(leftstick * (double)100 / 127);
		    right.move(rightstick * (double)100 /127);

            pros::delay(10);
        }

        void arcade(){
            auto leftstick = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
            auto rightstick = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

            if(leftstick <= 10){
                left.move(0);
            }
            if(rightstick <= 10){
                right.move(0);
            }
            left.move(leftstick * (double)100 / 127) && right.move(leftstick * (double)100 /127);
            left.move(-(rightstick * (double)100 / 127)) && right.move(rightstick * (double)100 /127);

            pros::delay(10);
		    

        }

        
    }
}