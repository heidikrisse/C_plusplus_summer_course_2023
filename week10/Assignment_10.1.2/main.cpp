// main.cpp
#include "include/user_input.h"
#include "include/log.h"

#include <thread>

int main()
{
    // Launch the functions 'read_user_input' and 'add_message_to_log' in separate threads
    std::thread user_input_thread(read_user_input);
    std::thread log_thread(add_message_to_log);

    // Join the threads
    user_input_thread.join();
    log_thread.join();

    return 0;
}
