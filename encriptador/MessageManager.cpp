#include "Crypto.h"
#include "FileManager.h"
#include "MessageManager.h"
#include <iostream>

namespace MessageManager {
	std::vector<std::string> messages;

	void AddMessage(const std::string& message) {
		messages.push_back(message);
	}

	std::vector<std::string>& GetMessages() {
		return messages;
	}

	void SaveMessages(const std::string& filename) {
		constexpr int SHIFT = 3;
		std::vector<std::string> encrypted;
		int checksum = 0;

		for(const auto& msg : messages) {
			int msgChecksum = 0;
			encrypted.push_back(Crypto::Encrypt(msg, SHIFT, msgChecksum));
			checksum += msgChecksum;
		}

		if(!FileManager::SaveToFile(filename, encrypted, checksum)) {
			std::cerr << "Error saving messages!\n";
		}
	}

	void LoadMessagesFromFile(const std::string& filename) {
		constexpr int SHIFT = 3;
		messages.clear();

		std::vector<std::string> encrypted;
		int storedChecksum = 0;

		if(!FileManager::LoadFromFile(filename, encrypted, storedChecksum)) return;

		int calculatedChecksum = 0;
		for(const auto& enc : encrypted) {
			int msgChecksum = 0;
			messages.push_back(Crypto::Decrypt(enc, SHIFT, msgChecksum));
			calculatedChecksum += msgChecksum;
		}

		if(calculatedChecksum != storedChecksum) {
			std::cout << "WARNING: File checksum mismatch!\n";
		}
	}
}