#include <iostream> 
#include <mutex>
#include <queue>
#include <string>

#include <condition_variable>
#include "q_functions.hpp"



void queue_push(CommandQueue& q, const std::string& command) { 


	std::lock_guard<std::mutex> q_lock(q.mutex);
	q.command_list.push(command); 

	//notify daemon that command was pushed to queue
	q.cv.notify_one();




}



std::string queue_pop(CommandQueue& q) { 

	std::unique_lock<std::mutex> q_lock(q.mutex); 

	//if queue is empty, wait until its not
	//if its got data, take that shit baby 
	q.cv.wait(q_lock, [&q] { 
        return !q.command_list.empty(); 
    });

	std::string current_command = q.command_list.front(); 
	q.command_list.pop();
	return current_command; 	



}