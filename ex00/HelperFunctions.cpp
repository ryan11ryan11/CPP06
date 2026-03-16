#include "HelperFunctions.hpp"

bool isAllInputPrintable(const std::string& input) {
	int len = input.length();
	for (int i = 0; i < len - 1; i++) {
		if (std::isprint(input[i]) != true)
			return false;
	}
	return true;
}
