#pragma once
#include <string>
#include <vector>

// Message helpers for encrypting and saving chat history.

void AddMessage(std::vector<std::string>& messages, const std::string& message);

bool LoadMessagesFromFile(const std::string& filename, std::vector<std::string>& outMessages, bool& outChecksumValid);
bool SaveMessagesToFile(const std::string& filename, const std::vector<std::string>& messages);
