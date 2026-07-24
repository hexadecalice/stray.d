#pragma once

#include <iostream> 
#include <mutex>
#include <queue>
#include <string>
    
#include <condition_variable>
#include "json.hpp"

using json = nlohmann::json;


struct CommandQueue {
    std::queue<std::string> command_list;
    std::mutex mutex;
};


void safe_push(CommandQueue& q, const std::string& command);
std::string safe_pop(CommandQueue& q);
json load_json_from_file(const std::string& filepath);