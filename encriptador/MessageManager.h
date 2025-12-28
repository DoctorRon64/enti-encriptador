#pragma once
#include <string>

class MessageManager {
public:
	MessageManager();
	~MessageManager();
	void AddMessage(const std::string& message);
	void SaveMessages(const std::string& filename);
	void LoadMessages(const std::string& filename);
};
