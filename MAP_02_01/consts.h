#ifndef CONSTS_H
#define CONSTS_H

namespace consts
{
const std::chrono::milliseconds requests_period {1000};
const std::chrono::milliseconds response_period {2000};

const std::chrono::milliseconds time_delay {50};

const int max_client_number = 16;
}

#endif // CONSTS_H
