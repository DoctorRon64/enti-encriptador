#pragma once
#include <string>
#include <vector>

// Check if a file exists.
bool FileExists(const std::string& filename);

// Load encrypted messages and checksum from a file.
bool LoadFromFile(const std::string& filename, std::vector<std::string>& outMessages, int& outChecksum);

// Save encrypted messages and checksum to a file.
bool SaveToFile(const std::string& filename, const std::vector<std::string>& messages, int checksum);
