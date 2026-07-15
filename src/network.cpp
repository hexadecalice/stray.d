#include <iostream> 
#include <SFML/Network.hpp>
#include <string>
#include "q_functions.hpp"




void setup_listener(sf::TcpListener &listener, int port) { 

	if(listener.listen(port) != sf::Socket::Done) { 

		std::cout << "Sorry! Couldn't bind to port.";
		exit(-1);
	}

	std::cout << "Success! Bound to port " << port << "."; 


}



void listen_to_port(sf::TcpListener &listener, CommandQueue& cq) { 

	sf::TcpSocket client; 

	char buffer[1024];
	std::size_t received; 



	while(true) { 

		if(listener.accept(client) == sf::Socket::Done) { 

			if(client.receive(buffer, sizeof(buffer), received) == sf::Socket::Done) { 
					std::string command(buffer, received); 
					queue_push(cq, command);
			}
			else { 
				std::cout << "Couldn't receive data into the variables. Cry about it.";
				exit(1);
			}

		}
		else { 
			std::cout << "Accept() failed when trying to create client socket. Whoops.";
			exit(2);

		}
	}




}

