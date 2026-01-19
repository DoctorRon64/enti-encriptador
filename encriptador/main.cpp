#include "FileManager.h"
#include "MessageManager.h"
#include <iostream>
#include <string>
#include <vector>

constexpr char EXIT_COMMAND[] = "exit";
constexpr char SAVE_FILE[] = "messages.dat";

int main() {
	std::vector<std::string> messages;
	bool recoveredMessages = false;
	bool hadPreviousFile = FileExists(SAVE_FILE);
	bool declinedRecovery = false;

	if(hadPreviousFile) {
		std::cout << "Previous messages found. Do you want to recover them? (y/n): ";
		char choice;
		std::cin >> choice;
		std::cin.ignore();

		if(choice == 'y' || choice == 'Y') {
			bool checksumValid = true;
			if(LoadMessagesFromFile(SAVE_FILE, messages, checksumValid)) {
				for(const auto& msg : messages) {
					std::cout << msg << std::endl;
				}
				if(!checksumValid) {
					std::cout << "WARNING: File checksum mismatch!\n";
				}
				recoveredMessages = true;
			}
		} else {
			declinedRecovery = true;
		}
	}

	std::cout << "Write messages (type 'exit' to quit):\n";

	while(true) {
		std::string input;
		std::getline(std::cin, input);
		if(input == EXIT_COMMAND) break;

		AddMessage(messages, input);
	}

	std::cout << "Do you want to save data? (y/n): ";
	char saveChoice;
	std::cin >> saveChoice;

	if(saveChoice == 'y' || saveChoice == 'Y') {
		if(hadPreviousFile && declinedRecovery) {
			std::cout << "The previous text has been deleted!\n";
		}
		SaveMessagesToFile(SAVE_FILE, messages);
	} else {
		if(hadPreviousFile && declinedRecovery) {
			if(DeleteFile(SAVE_FILE)) {
				std::cout << "The previous text has been deleted!\n";
			} else {
				std::cout << "Unable to delete previous text.\n";
			}
		}
	}

	return 0;
}
