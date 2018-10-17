#include "include/server.hpp"
#include "include/event.hpp"

#include <map>
#include <string>
#include <iostream>

using namespace mmn_model;
using namespace std;

static int GLOABAL_ID = 0;
//
Server::Server(
    Math_lib &math_func_config):_math_func_config(math_func_config)
{
    //pass
    _id = GLOABAL_ID ++;
    _busy = false;
}

bool Server::isBusy()
{
    return _busy;
}

Event *Server::getNextClientEvent(Client &next_client, float curtime)
{
    _busy = true;
    map<string, int> temp_args;
    temp_args["server_id"] = _id;
    temp_args["client_id"] = next_client.getID();
    float event_time = curtime + _math_func_config.getRandom();
    Event *temp_event = new  Event(event_time, 
                             EVENT_TYPE_CLIENT_DEPART,
                             temp_args);
    _last_serving_time = curtime;
    return temp_event;
}

void Server::setFree(float curtime) {
    _busy = false;
    _total_serving_time += curtime - _last_serving_time;
    cout << "Server ID:" << _id << " is free" << endl;
}

float Server::getTotalServingTime() {
    return _total_serving_time;
}