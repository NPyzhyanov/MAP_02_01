#ifndef GLOBALS_H
#define GLOBALS_H
 
extern std::atomic<int> clients_counter;
extern std::chrono::time_point<std::chrono::steady_clock> start;

#endif // GLOBALS_H
