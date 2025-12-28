#pragma once
#include <string>

namespace Crypto {
	std::string Encrypt(const std::string& text, int shift, int& checksum);
	std::string Decrypt(const std::string& text, int shift, int& checksum);
}