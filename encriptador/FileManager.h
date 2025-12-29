#pragma once
#include <string>
#include <vector>

// Handles file operations such as saving, loading, and verifying stored message data.

class FileManager {
public:
	// Checks whether the save file exists on disk.
	bool FileExists(const std::string& filename) const;

	// Loads encrypted messages and checksum from file.
	bool LoadFromFile(const std::string& filename, std::vector<std::string>& outMessages, int& outChecksum) const;

	// Saves encrypted messages and checksum to file.
	bool SaveToFile(const std::string& filename, const std::vector<std::string>& messages, int checksum, bool append) const;
};
