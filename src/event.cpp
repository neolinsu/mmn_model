#include "include/event.hpp"
#include <iostream>
using namespace std;
using namespace mmn_model;

//STATIC
bool Event::cmpEvent(
    Event* &e1,
    Event* &e2)
{
    return e1->getEventTime() < e2->getEventTime();
}

//
Event::Event(
    float time,
    int type,
    std::map<std::string, int> &args_map_config)
{
    _event_time = time;
    _event_type = type;
    for (auto item: args_map_config) {
        _args_map[item.first] = item.second;
        //cout << item.first << ":" << item.second << endl;
    }
}

float Event::getEventTime()
{
    return _event_time;
}

int Event::getEventType()
{
    return _event_type;
}
