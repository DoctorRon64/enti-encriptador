#include "FileManager.h"
#include <fstream>
#include <iostream>

bool FileManager::FileExists(const std::string& filename) {
	std::ifstream file(filename);
	return file.good();
}

bool FileManager::LoadFromFile(const std::string& filename, std::vector<std::string>& outMessages, int& outChecksum) {
	std::ifstream inFile(filename);

	if(!inFile.is_open()) {
		return false;
	}

	outMessages.clear();

	inFile >> outChecksum;
	inFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::string line;
	while(std::getline(inFile, line)) {
		if(!line.empty()) {
			outMessages.push_back(line);
		}
	}

	inFile.close();
	return true;
}

bool FileManager::SaveToFile(const std::string& filename, const std::vector<std::string>& messages, int checksum, bool append) {
	std::ios::openmode mode = std::ios::out;

	if(append) {
		mode |= std::ios::app;
	}
	else {
		mode |= std::ios::trunc;
	}

	std::ofstream outFile(filename, mode);

	if(!outFile.is_open()) {
		return false;
	}

	if(!append) {
		outFile << checksum << std::endl;
	}

	for(const std::string& message : messages) {
		outFile << message << std::endl;
	}

	outFile.close();
	return true;
}