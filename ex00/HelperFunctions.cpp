#include "HelperFunctions.hpp"

bool isAllInputPrintable(const std::string& input) {
	int len = input.length();
	for (int i = 0; i < len - 1; i++) {
		if (std::isprint(input[i]) != true)
			return false;
	}
	return true;
}

int detectType(std::string& input) {
	
}

bool isVaildInput(const std::string& input) {
	char *ptr;
	int result;
	result = strtod(input.c_str(), &ptr);

	if (result == 0)
		return false;
	if (result != 0 && *ptr == '\0')
		return true;
}