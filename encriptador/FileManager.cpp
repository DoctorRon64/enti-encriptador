#include "FileManager.h"
#include <cstdio>
#include <fstream>
#include <limits>

bool FileExists(const std::string& filename) {
	std::ifstream file(filename);
	return file.good();
}

bool LoadFromFile(const std::string& filename, std::vector<std::string>& outMessages, int& outChecksum) {
	std::ifstream inFile(filename);
	if(!inFile.is_open()) return false;

	outMessages.clear();

	inFile >> outChecksum; // First line is checksum.
	inFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::string line;
	while(std::getline(inFile, line)) {
		if(!line.empty()) outMessages.push_back(line);
	}

	return true;
}

bool SaveToFile(const std::string& filename, const std::vector<std::string>& messages, int checksum) {
	std::ofstream outFile(filename, std::ios::out | std::ios::trunc);
	if(!outFile.is_open()) return false;

	outFile << checksum << '\n'; // Write checksum first.
	for(const auto& msg : messages) {
		outFile << msg << '\n';
	}

	return true;
}

bool DeleteFile(const std::string& filename) {
	return std::remove(filename.c_str()) == 0;
}
