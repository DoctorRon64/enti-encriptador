#include "Crypto.h"

namespace Crypto {
	std::string Encrypt(const std::string& text, int shift, int& checksum) {
		std::string result;
		checksum = 0;

		for(char c : text) {
			char inverted = InvertCase(c);
			char encrypted = static_cast<char>(inverted + shift);
			checksum += static_cast<int>(encrypted);
			result += encrypted;
		}

		return result;
	}

	std::string Decrypt(const std::string& text, int shift, int& checksum) {
		std::string result;
		checksum = 0;

		for(char c : text) {
			checksum += static_cast<int>(c);
			char decrypted = static_cast<char>(c - shift);
			char original = InvertCase(decrypted);
			result += original;
		}

		return result;
	}
}