#pragma once
#include <string>

namespace Crypto {
	/// Invert the case of a character
	inline char InvertCase(char c) {
		if(std::islower(static_cast<unsigned char>(c))) return std::toupper(c);
		if(std::isupper(static_cast<unsigned char>(c))) return std::tolower(c);
		return c;
	}

	/// Encrypt a string using Caesar cipher and invert case, calculate checksum
	std::string Encrypt(const std::string& text, int shift, int& checksum);

	/// Decrypt a string using Caesar cipher and invert case, calculate checksum
	std::string Decrypt(const std::string& text, int shift, int& checksum);
}
