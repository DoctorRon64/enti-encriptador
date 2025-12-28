#include "MessageManager.h"
#include <iostream>
#include <string>

constexpr int CAESAR_SHIFT = 3;
constexpr char EXIT_COMMAND[] = "exit";
constexpr char SAVE_FILE[] = "messages.dat";

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