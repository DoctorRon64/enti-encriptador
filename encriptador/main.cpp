#include "Crypto.h"
#include "FileManager.h"
#include "MessageManager.h"
#include <iostream>
#include <string>
#include <vector>

constexpr int CAESAR_SHIFT = 3;
constexpr char EXIT_COMMAND[] = "exit";
constexpr char SAVE_FILE[] = "messages.dat";

int main() {
	MessageManager messageManager;
	FileManager fileManager;

	bool recoveredMessages = false;
	bool fileExists = fileManager.FileExists(SAVE_FILE);

	if(fileExists) {
		std::cout << "Previous messages found. Do you want to recover them? (y/n): ";
		char choice;
		std::cin >> choice;
		std::cin.ignore();

		if(choice == 'y' || choice == 'Y') {
			std::vector<std::string> encryptedMessages;
			int storedChecksum = 0;

			fileManager.LoadFromFile(SAVE_FILE, encryptedMessages, storedChecksum);

			int calculatedChecksum = 0;

			for(const std::string& enc : encryptedMessages) {
				int msgChecksum = 0;
				std::string decrypted = Crypto::Decrypt(enc, CAESAR_SHIFT, msgChecksum);

				calculatedChecksum += msgChecksum;
				messageManager.AddMessage(decrypted);
				std::cout << decrypted << std::endl;
			}

			if(calculatedChecksum != storedChecksum) {
				std::cout << "WARNING: The file has been altered!" << std::endl;
			}

			recoveredMessages = true;
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
	char saveChoice;
	std::cin >> saveChoice;

	if(saveChoice == 'y' || saveChoice == 'Y') {
		std::vector<std::string> encryptedMessages;
		int calculatedChecksum = 0;

		for(const std::string& msg : messageManager.GetMessages()) {
			int msgChecksum = 0;
			std::string encrypted = Crypto::Encrypt(msg, CAESAR_SHIFT, msgChecksum);

			calculatedChecksum += msgChecksum;
			encryptedMessages.push_back(encrypted);
		}

		fileManager.SaveToFile(SAVE_FILE, encryptedMessages, calculatedChecksum, recoveredMessages);
	}
	else if(fileExists && !recoveredMessages) {
		std::cout << "Se ha eliminado el texto anterior!" << std::endl;
	}

	return 0;
}