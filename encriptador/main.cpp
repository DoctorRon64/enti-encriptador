#include "MessageManager.h"
#include <iostream>
#include <string>

int main() {
	std::cout << "Hello World!\n";

	//Program loop
	//User input
	//Calls other modules
	//Handles exit

	MessageManager messageManager;

	while(true) {
		std::getline(std::cin, input);

		if(input == EXIT_COMMAND)
			break;

		messageManager.AddMessage(input);
	}

	return 0;
}