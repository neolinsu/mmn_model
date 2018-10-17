#include "include/event.hpp"
#include "include/client.hpp"
#include "include/server.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <iostream>
#include <list>
#include <vector>

using namespace std;
using namespace mmn_model;

static float param_avg_arrive_time = 5;
static float param_avg_serve_time = 3;
static int param_client_num = 20;
static int max_length = 15;

static float getArriveRandByLn() {
    srand(time(0) );
    float u = (float)rand() / RAND_MAX;
    return  -param_avg_arrive_time*log(u);
}

static float getServeRandByLn() {
    srand(time(0) );
    float u = (float)rand() / RAND_MAX;
    return  -param_avg_serve_time*log(u);
}

int main() {

    cout << "avg_arrive_time: " << param_avg_arrive_time << endl;
    cout << "avg_serve_time: " << param_avg_serve_time << endl;
    cout << "client_num: " << param_client_num << endl;
    cout << "max_length: " << max_length << endl;

    //init
    Math_lib client_math_config = Math_lib();
    client_math_config.setBasicRandomFunc(getArriveRandByLn);
    Math_lib server_math_config = Math_lib();
    server_math_config.setBasicRandomFunc(getServeRandByLn);
    
    list<Client*> client_list;
    list<Event*> event_list;
    list<Client*> waitting_list;
    Server server_0 = Server(server_math_config);
    float temp_client_arrive = 0;
    float waitting_list_last_time = 0;
    float waitting_list_area = 0;
    float curtime = 0;
    float total_waitting_time = 0;
    int total_waitting_num = 0;
    float serving_time = 0;
    for (int i = 0; i < param_client_num; ++i) {
        Client *p_temp_client = new Client(temp_client_arrive, client_math_config);
        temp_client_arrive = p_temp_client->getArriveTime() ;
        client_list.push_back(p_temp_client);
        map<string, int> temp_map;
        temp_map["client_id"] = p_temp_client->getID();
        Event *temp_event = new Event(p_temp_client->getArriveTime(), EVENT_TYPE_CLIENT_ARRIVE,temp_map);
        event_list.push_back(temp_event);
        cout << temp_map["client_id"] << endl;
    }

    while(event_list.size() > 0) {

        Event *cur_event = event_list.front();event_list.pop_front();
        curtime = cur_event->getEventTime();
        cout << "curtime: " << curtime <<endl;
        switch (cur_event->getEventType() ) {
            case EVENT_TYPE_CLIENT_ARRIVE:{
                
                Client* cur_client = client_list.front();client_list.pop_front();
                //for()
                if(server_0.isBusy() ) {
                    std::cout << cur_event->_args_map["client_id"] << " starts waitting at " << curtime << endl;
                    waitting_list_area += waitting_list.size() * (curtime-waitting_list_last_time);
                    waitting_list_last_time = curtime;
                    waitting_list.push_back(cur_client);
                    if (waitting_list.size() > max_length) goto final_cout;
                    total_waitting_num++;
                    cur_client->startWaiting(curtime);
                }
                else {
                    if (waitting_list.size() > 0) {
                        waitting_list_area += waitting_list.size() * (curtime-waitting_list_last_time);
                        waitting_list_last_time = curtime;
                        waitting_list.push_back(cur_client);
                        if (waitting_list.size() > max_length) goto final_cout;
                        total_waitting_num++;
                        cur_client->startWaiting(curtime);
                        std::cout << cur_event->_args_map["client_id"] << " starts waitting at " << curtime << endl;
                        cur_client = waitting_list.front();waitting_list.pop_front();
                        std::cout << cur_event->_args_map["client_id"] << " start being served at " << curtime << endl;
                        Event * temp_event = server_0.getNextClientEvent(*cur_client, curtime);
                        event_list.push_back(temp_event);
                        event_list.sort(Event::cmpEvent);
                        total_waitting_time += cur_client->getWaitingTime(curtime);
                    }
                    else {
                        int temp = cur_event->_args_map.at("client_id");
                        cout << temp << " start being served at " << curtime << endl;
                        Event * temp_event = server_0.getNextClientEvent(*cur_client, curtime);
                        event_list.push_back(temp_event);
                        event_list.sort(Event::cmpEvent);
                    }
                }
                break;
                }
            case EVENT_TYPE_CLIENT_DEPART:{
                server_0.setFree(curtime);
                std::cout << cur_event->_args_map["client_id"] << " left at " << cur_event->getEventTime() << endl;
                if (waitting_list.size() > 0) {
                    waitting_list_area += waitting_list.size() * (curtime-waitting_list_last_time);
                    waitting_list_last_time = curtime; 
                    Client* cur_client = waitting_list.front();waitting_list.pop_front();
                    Event * temp_event = server_0.getNextClientEvent(*cur_client, curtime);
                    std::cout << temp_event->_args_map["client_id"] << " start being served at " << curtime << endl;
                    event_list.push_back(temp_event);
                    event_list.sort(Event::cmpEvent);
                    total_waitting_time += cur_client->getWaitingTime(curtime);
                    delete cur_client;
                }
                break;
            }
        }
        delete cur_event;
    }
    final_cout:
    cout << "average number of customers in queue: " << waitting_list_area / curtime << endl;
    if (total_waitting_num == 0) {
        total_waitting_num = 1;    
    }
    cout << "average delay in the queue: " << total_waitting_time / total_waitting_num << endl;
    cout << "utilisation of server: " << server_0.getTotalServingTime() / curtime << endl;

    return 0;
}