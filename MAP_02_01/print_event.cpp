#include <iostream>
#include <string>
#include <chrono>
#include <mutex>

#include "events.h"
#include "print_event.h"

extern std::chrono::time_point<std::chrono::steady_clock> start;
extern std::mutex ostream_mut;

void print_event(int clients_amount, int client_number, std::chrono::time_point<std::chrono::steady_clock> time, events event)
{
    auto event_time = std::chrono::duration_cast<std::chrono::milliseconds>(time - start);
    
    std::string out = "";
    
    out += std::to_string(event_time.count());
    out += "ms\t";
    
    out += "Client #";
    out += std::to_string(client_number);
    switch (event)
    {
    case events::client_arrived:
        out += " has arrived.";
        break;
    case events::client_called:
        out += " is called.";
        break;
        
    case events::client_served:
        out += " was served.";
        break;
    }
    
    out += "\tThere are ";
    out += std::to_string(clients_amount);
    out += " unserved clients.";
    
    std::lock_guard<std::mutex> grd(ostream_mut);
    std::cout << out << std::endl;;
}
