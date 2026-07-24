#include <iostream> 
#include <atomic>
#include <thread>
#include <mutex>
#include <functional>
#include <fstream>
#include <SFML/System.hpp>
#include "json.hpp"
#include "network.hpp"
#include "q_functions.hpp"


using json = nlohmann::json;



void game_loop(CommandQueue& cq, std::atomic<bool>& is_running, json& creature_data, const std::string& filepath) { 


	while(is_running) { 

		std::string current_command = safe_pop(cq);
		if(current_command == ""){ 
			sf::sleep(sf::milliseconds(100));
			continue;
		}
		else { 
			if(current_command == "feed\n") { 
				//+= is concatenation in the json library (which is super cool and youre all so talented or whatever) 
				//but fuck this looks ugly
				int current_hunger = creature_data["Creature"]["hunger"];
				current_hunger += 10;
				creature_data["Creature"]["hunger"] = current_hunger;
				
				std::ofstream file(filepath); 
				file << creature_data;
				file.close();
			}


		}

		


	}


}




int main(void) { 

	CommandQueue cq;
	sf::TcpListener listener; 
	std::string filepath = "creature_data.json";
	json joe = load_json_from_file(filepath);

	setup_listener(listener, 6767); 


	std::atomic<bool> is_running{true};

	std::thread daemon_thread(game_loop, std::ref(cq), std::ref(is_running), std::ref(joe), std::ref(filepath));
	std::thread network_thread(listen_to_port, std::ref(listener), std::ref(cq));

	daemon_thread.join();
	network_thread.join();


return 0;


}
