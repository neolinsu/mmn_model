/////////////////////////////////////////////
//Basic Client
/////////////////////////////////////////////
#ifndef _EVENT_HPP_
#define _EVENT_HPP_

#include <map>
#include <string>

namespace mmn_model{
    
    //EVENT TYPE
    #define EVENT_TYPE_CLIENT_ARRIVE (0)
    #define EVENT_TYPE_CLIENT_DEPART (1)

    class Event {
        public:
            static bool cmpEvent(Event* &e1, Event* &e2);

            Event(float time, int type, std::map<std::string, int> &args_map_config); //constractor
            float getEventTime();
            int getEventType();

        public:
            std::map<std::string, int> _args_map;
        private:
            float _event_time;
            int _event_type;
            int _client_id;
            int _server_id;
            
    };
}

#endif //_END_EVENT_HPP