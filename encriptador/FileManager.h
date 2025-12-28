#pragma once
#include <string>
#include <vector>

class FileManager {
public:
	static bool FileExists(const std::string& filename);

	static bool LoadFromFile(
		const std::string& filename,
		std::vector<std::string>& outMessages,
		int& outChecksum
	);

	static bool SaveToFile(
		const std::string& filename,
		const std::vector<std::string>& messages,
		int checksum,
		bool append
	);
};
