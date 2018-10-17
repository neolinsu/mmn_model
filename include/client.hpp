/////////////////////////////////////////////
//Basic Client
/////////////////////////////////////////////
#ifndef _CLIENT_HPP_
#define _CLIENT_HPP_

#include "math_lib.hpp"
namespace mmn_model {
    class Client {
        public:
            Client(float last_client_time, Math_lib &math_func_config); //constractor
            float getArriveTime();
            int getID();
            void startWaiting(float curtime);
            float getWaitingTime(float curtime);
        private:
            float _arrive_time;
            Math_lib &_math_func_config;
            int _id;
            float _start_waiting_time;

    };
}


#endif //_END_CLIENT_HPP_