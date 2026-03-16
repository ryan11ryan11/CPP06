#include "HelperFunctions.hpp"

bool isAllInputPrintable(const std::string& input) {
	int len = input.length();
	for (int i = 0; i < len - 1; i++) {
		if (!std::isprint(static_cast<unsigned char>(input[i])))
			return false;
	}
	return true;
}
