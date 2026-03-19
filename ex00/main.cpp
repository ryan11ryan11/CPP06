#include <iostream>
#include "HelperFunctions.hpp"
#include "ScalarConverter.hpp"
#include <string>

int main(int argc, char** argv)
{
	if (argc != 2) {
		std::cerr << "1 parameter only" << std::endl;
		return -1;
	}
	std::string input(argv[1]);
	if (!isAllInputPrintable(input)) {
		std::cerr << "Non printable char from input." << std::endl;
		return -1;
	}
	ScalarConverter::convert(input);
}
