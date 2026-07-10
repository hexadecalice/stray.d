#include <iostream> 
#include <SFML/Network.hpp>
#include <string>

void setup_listener(sf::TcpListener &listener, int port) { 

	if(listener.listen(port) != sf::Socket::Done) { 

		std::cout << "Sorry! Couldn't bind to port.";
		exit(-1);
	}

	listener.setBlocking(false); 

	std::cout << "Success! Bound to port " << port << "."; 


}

void listen_to_port(sf::TcpListener &listener) { 

	sf::TcpSocket client; 

	char buffer[1024];
	std::size_t received; 


	if(listener.accept(client) == sf::Socket::Done) { 

		if(client.receive(buffer, sizeof(buffer), received) == sf::Socket::Done) { 
				std::string command(buffer, received); 
				std::cout << command;

		}

	}
	else { 


	}




}

int main(void) { 


	sf::TcpListener my_listener; 
	setup_listener(my_listener, 6767);

	while(true) { 
		listen_to_port(my_listener);
		sf::sleep(sf::milliseconds(100));

	}


	return 0; 
} 
