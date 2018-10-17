#include "include/client.hpp"
#include "include/event.hpp"

using namespace mmn_model;

static int CLIENT_ID = 0;

Client::Client(
    float last_client_time,
    Math_lib &math_func_config):_math_func_config(math_func_config)
{
    _arrive_time =  last_client_time + math_func_config.getRandom();
    _id = CLIENT_ID++;
}

float Client::getArriveTime()
{
    return _arrive_time;
}

int Client::getID()
{
    return _id;
}

void Client::startWaiting(float curtime) {
    _start_waiting_time = curtime;
}

float Client::getWaitingTime(float curtime) {
    return curtime - _start_waiting_time;
}