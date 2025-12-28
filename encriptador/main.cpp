#include "FileManager.h"
#include "MessageManager.h"
#include <iostream>
#include <string>
#include <vector>

constexpr char EXIT_COMMAND[] = "exit";
constexpr char SAVE_FILE[] = "messages.dat";

int main() {
	MessageManager messageManager;
	FileManager fileManager;

	if(fileManager.FileExists(SAVE_FILE)) {
		std::vector<std::string> loadedMessages;
		int storedChecksum = 0;

		fileManager.LoadFromFile(SAVE_FILE, loadedMessages, storedChecksum);

		for(const std::string& msg : loadedMessages) {
			messageManager.AddMessage(msg);
		}
	}

	std::cout << "Write messages (type 'exit' to quit):\n";

	while(true) {
		std::string input;
		std::getline(std::cin, input);

		if(input == EXIT_COMMAND) {
			break;
		}

		messageManager.AddMessage(input);
	}

	std::cout << "Do you want to save data? (y/n): ";
	char choice;
	std::cin >> choice;

	if(choice == 'y' || choice == 'Y') {
		fileManager.SaveToFile(
			SAVE_FILE,
			messageManager.GetMessages(), 0, false
		);
	}

	return 0;
}