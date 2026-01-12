#pragma once
#include <string>
#include <vector>

//Manages during runtime the storage of user messages.

namespace MessageManager {
	extern std::vector<std::string> messages;

	void AddMessage(const std::string& message);
	std::vector<std::string>& GetMessages();

	void SaveMessages(const std::string& filename);
	void LoadMessagesFromFile(const std::string& filename);
}