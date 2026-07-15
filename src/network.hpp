#pragma once

#include <SFML/Network.hpp>
#include <string>
#include "q_functions.hpp"

void setup_listener(sf::TcpListener &listener, int port);
void listen_to_port(sf::TcpListener &listener, CommandQueue& command_list);
