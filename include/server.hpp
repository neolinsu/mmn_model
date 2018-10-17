/////////////////////////////////////////////
//Basic Server 
/////////////////////////////////////////////
#ifndef _SERVER_HPP_
#define _SERVER_HPP_

#include "client.hpp"
#include "event.hpp"
#include <list>

namespace mmn_model {

    class Server {
        public:
            Server(Math_lib &math_func_config); //constractor
            bool isBusy();
            Event *getNextClientEvent(Client &next_client, float curtime);
            void setFree(float curtime);
            float getTotalServingTime();
        private:
            bool _busy = false;
            Math_lib &_math_func_config;
            int _id;
            float _total_serving_time = 0;
            float _last_serving_time = 0;
    };
}





#endif //_END_SERVER_HPP_