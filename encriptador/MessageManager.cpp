#include "MessageManager.h"
#include <fstream>
#include <iostream>

MessageManager::MessageManager() {}

MessageManager::~MessageManager() {}

void MessageManager::AddMessage(const std::string& message) {
	messages.push_back(message);
}

void MessageManager::SaveMessages(const std::string& filename) {
	std::ofstream outFile(filename, std::ios::out | std::ios::trunc);

	if(!outFile.is_open()) {
		std::cerr << "Error opening file for writing.\n";
		return;
	}

	for(const std::string& message : messages) {
		outFile << message << std::endl;
	}

	outFile.close();
}

void MessageManager::LoadMessages(const std::string& filename) {
	std::ifstream inFile(filename);

	if(!inFile.is_open()) {
		std::cerr << "Error opening file for reading.\n";
		return;
	}

	messages.clear();

	std::string line;
	while(std::getline(inFile, line)) {
		messages.push_back(line);
	}

	inFile.close();
}

const std::vector<std::string>& MessageManager::GetMessages() const {
	return messages;
}