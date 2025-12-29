#pragma once
#include <string>
#include <vector>

// Handles file operations such as saving, loading, and verifying stored message data.

class FileManager {
public:
	bool FileExists(const std::string& filename) const;

	bool LoadFromFile(
		const std::string& filename,
		std::vector<std::string>& outMessages,
		int& outChecksum
	) const;

	bool SaveToFile(
		const std::string& filename,
		const std::vector<std::string>& messages,
		int checksum,
		bool append
	) const;
};
