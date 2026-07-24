#include <iostream>
#include <SFML/Network.hpp>
#include <string>
#include "q_functions.hpp"

void setup_listener(sf::TcpListener &listener, int port) {
    if (listener.listen(port) != sf::Socket::Done) {
        std::cout << "Sorry! Couldn't bind to port.";
        exit(-1);
    }

    std::cout << "Success! Bound to port " << port << ".\n";
}

void listen_to_port(sf::TcpListener &listener, CommandQueue& cq) {
    sf::TcpSocket client;
    char buffer[1024];
    std::size_t received;
    //Outer loop waits for connections
    while (true) {
        if (listener.accept(client) == sf::Socket::Done) {
            std::cout << "Successful Connection!\n";
            //Inner loop maintains connection
            while (true) {
                sf::Socket::Status status = client.receive(buffer, sizeof(buffer), received);

                if (status == sf::Socket::Done) {
                	//push command to queue
                    std::string command(buffer, received);
                    safe_push(cq, command);
                    
                } else if (status == sf::Socket::Disconnected || status == sf::Socket::Error) {
                    std::cout << "Client disconnected. Going back to listening...\n";
                    break;
                }
            }
        } else {
            sf::sleep(sf::milliseconds(100));
        }
    }
}