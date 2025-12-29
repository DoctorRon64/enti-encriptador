#pragma once
#include <string>

// Provides encryption, decryption, and checksum generation using a Caesar cipher.

namespace Crypto {
	std::string Encrypt(const std::string& text, int shift, int& checksum);
	std::string Decrypt(const std::string& text, int shift, int& checksum);
}