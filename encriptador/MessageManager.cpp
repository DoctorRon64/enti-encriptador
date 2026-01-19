#include "Crypto.h"
#include "FileManager.h"
#include "MessageManager.h"
#include <iostream>

namespace {
	constexpr int kCaesarShift = 3;
}

void AddMessage(std::vector<std::string>& messages, const std::string& message) {
	messages.push_back(message);
}

bool SaveMessagesToFile(const std::string& filename, const std::vector<std::string>& messages) {
	std::vector<std::string> encrypted;
	int checksum = 0;

	for(const auto& msg : messages) {
		int msgChecksum = 0;
		encrypted.push_back(Encrypt(msg, kCaesarShift, msgChecksum));
		checksum += msgChecksum;
	}

	if(!SaveToFile(filename, encrypted, checksum)) {
		std::cerr << "Error saving messages!\n";
		return false;
	}

	return true;
}

bool LoadMessagesFromFile(const std::string& filename, std::vector<std::string>& outMessages, bool& outChecksumValid) {
	outMessages.clear();

	std::vector<std::string> encrypted;
	int storedChecksum = 0;

	if(!LoadFromFile(filename, encrypted, storedChecksum)) return false;

	int calculatedChecksum = 0;
	for(const auto& enc : encrypted) {
		int msgChecksum = 0;
		outMessages.push_back(Decrypt(enc, kCaesarShift, msgChecksum));
		calculatedChecksum += msgChecksum;
	}

	outChecksumValid = (calculatedChecksum == storedChecksum);
	return true;
}
