#include "FileManager.h"
#include "MessageManager.h"
#include <iostream>
#include <string>

constexpr char EXIT_COMMAND[] = "exit";
constexpr char SAVE_FILE[] = "messages.dat";

int main() {
	bool recoveredMessages = false;

	if(FileManager::FileExists(SAVE_FILE)) {
		std::cout << "Previous messages found. Do you want to recover them? (y/n): ";
		char choice;
		std::cin >> choice;
		std::cin.ignore();

		if(choice == 'y' || choice == 'Y') {
			MessageManager::LoadMessagesFromFile(SAVE_FILE);
			for(const auto& msg : MessageManager::GetMessages()) {
				std::cout << msg << std::endl;
			}
			recoveredMessages = true;
		}
	}

	std::cout << "Write messages (type 'exit' to quit):\n";

	while(true) {
		std::string input;
		std::getline(std::cin, input);
		if(input == EXIT_COMMAND) break;

		MessageManager::AddMessage(input);
	}

	std::cout << "Do you want to save data? (y/n): ";
	char saveChoice;
	std::cin >> saveChoice;

	if(saveChoice == 'y' || saveChoice == 'Y') {
		if(!recoveredMessages) {
			// Overwrite old file if user wants
			std::cout << "The previous text has been deleted!\n";
		}
		MessageManager::SaveMessages(SAVE_FILE);
	}

	return 0;
}