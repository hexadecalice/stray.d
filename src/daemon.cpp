#include <iostream> 
#include <atomic>
#include <thread>
#include <mutex>
#include <functional>
#include "network.hpp"
#include "q_functions.hpp"




void game_loop(CommandQueue& cq, std::atomic<bool>& is_running) { 


	while(is_running) { 

		std::string current_command = queue_pop(cq);
		std::cout << current_command;

		//Add code to write to JSON file later
		//im so goddamn tired i need to sleep before work lol


	}


}




int main(void) { 

	CommandQueue cq;
	sf::TcpListener listener; 

	setup_listener(listener, 6767); 


	std::atomic<bool> is_running{true};

	std::thread daemon_thread(game_loop, std::ref(cq), std::ref(is_running));
	std::thread network_thread(listen_to_port, std::ref(listener), std::ref(cq));

	daemon_thread.join();
	network_thread.join();


return 0;


}
