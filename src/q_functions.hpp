#pragma once

#include <iostream> 
#include <mutex>
#include <queue>
#include <string>
    
#include <condition_variable>

struct CommandQueue {
    std::queue<std::string> command_list;
    std::mutex mutex;
    std::condition_variable cv;
};


void queue_push(CommandQueue& q, const std::string& command);
std::string queue_pop(CommandQueue& q);