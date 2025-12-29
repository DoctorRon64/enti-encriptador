#include "Crypto.h"
#include <cctype>

namespace Crypto {
	static char InvertCase(char c) {
		if(std::islower(c))
			return std::toupper(c);
		if(std::isupper(c))
			return std::tolower(c);
		return c;
	}

	std::string Encrypt(const std::string& text, int shift, int& checksum) {
		std::string result;
		checksum = 0;

		for(char c : text) {
			char inverted = InvertCase(c);
			char encrypted = inverted + shift;

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

			char decrypted = c - shift;
			char original = InvertCase(decrypted);

			result += original;
		}

		return result;
	}
}