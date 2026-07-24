#include <iostream> 
#include <mutex>
#include <queue>
#include <string>
#include "json.hpp"
#include <condition_variable>
#include "q_functions.hpp"
#include <fstream>


void safe_push(CommandQueue& q, const std::string& command) { 


	std::lock_guard<std::mutex> q_lock( q.mutex);
	q.command_list.push(command); 




}

std::string safe_pop(CommandQueue& q) { 

	std::lock_guard<std::mutex> q_lock(q.mutex); 

	if(q.command_list.empty()) { 
		return "";
	}
	else { 
		std::string current_command = q.command_list.front(); 
		std::cout << current_command;
		q.command_list.pop();
		return current_command; 
	}

}

json load_json_from_file(const std::string& filepath) {

    std::ifstream file(filepath);
    json creature_data;

    if (!file.is_open()) {
        std::cout << "[Warning] No save file found. Please create or connect to a creature and retry.\n";
        return creature_data;
    }

    file >> creature_data; 
    
    return creature_data;
}


