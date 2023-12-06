#include <thread>
#include <chrono>
#include <atomic>

#include "consts.h"
#include "globals.h"
#include "events.h"
#include "print_event.h"
#include "responding_function.h"

void responding_function()
{
    
//    do
//    {
//        //std::this_thread::sleep_for(consts::time_delay);
//    }
//    while(clients_counter == 0);
    
    int client = 0;
    
    while (int clients_amount = clients_counter.load())
    {
        client++;
        auto serving_start = std::chrono::steady_clock::now();
        
        print_event(clients_amount, client, serving_start, events::client_called);
        
        std::this_thread::sleep_for(consts::response_period);
        
        clients_amount = clients_counter.fetch_sub(1) - 1;
        
        auto serving_finish = std::chrono::steady_clock::now();
        print_event(clients_amount, client, serving_finish, events::client_served);
    }
}
