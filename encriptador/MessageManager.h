#pragma once
#include <string>
#include <vector>

//Manages during runtime the storage of user messages.

class MessageManager {
public:
	MessageManager();
	~MessageManager();

	void AddMessage(const std::string& message);
	void SaveMessages(const std::string& filename);
	void LoadMessages(const std::string& filename);
	const std::vector<std::string>& GetMessages() const;

private:
	std::vector<std::string> messages;
};
