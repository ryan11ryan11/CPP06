/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HelperFunctions.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:36:32 by junhhong          #+#    #+#             */
/*   Updated: 2026/04/02 12:26:33 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HelperFunctions.hpp"

bool isAllInputPrintable(const std::string& input) {
	int len = input.length();
	for (int i = 0; i < len - 1; i++) {
		if (!std::isprint(static_cast<unsigned char>(input[i])))
			return false;
	}
	return true;
}

void printImpossible(void) {
	std::cout << "char: impossible"  << std::endl;
	std::cout << "int: impossible"  << std::endl;
	std::cout << "float: impossible"  << std::endl;
	std::cout << "double: impossible"  << std::endl;
}

void printDouble(const double& val) {
	if (val > 127 || val < 0) {
		std::cout << "char: impossible"  << std::endl;
	} else {
		if (isprint(static_cast<unsigned char>(val))) {
			std::cout << "char: '" << static_cast<char>(val) << "'"  << std::endl;
		} else {
			std::cout << "char: Non displayable"  << std::endl;
		}
	}
	if (static_cast<double>(val) > static_cast<double>(INT_MAX) || static_cast<double>(val) < static_cast<double>(INT_MIN)) {
		std::cout << "int: impossible"  << std::endl;
	} else {
		std::cout << "int: " << static_cast<int>(val) << std::endl;
	}
	if (val > FLT_MAX || val < -FLT_MAX) {
		std::cout << "float: impossible" << std::endl;
	} else {
		std::cout << "float: " << static_cast<float>(val);
		if (val == std::floor(val))
			std::cout << ".0";
		std::cout << "f" << std::endl;
	}
	std::cout << "double: "  << val;
	if (val == std::floor(val))
		std::cout << ".0";
	std::cout << std::endl;
}

void printFloat(const float& val) {
	if (val > 127 || val < 0) {
		std::cout << "char: impossible"  << std::endl;
	} else {
		if (isprint(static_cast<unsigned char>(val))) {
			std::cout << "char: '" << static_cast<char>(val) << "'"  << std::endl;
		} else {
			std::cout << "char: Non displayable"  << std::endl;
		}
	}
	if (static_cast<double>(val) > static_cast<double>(INT_MAX) || static_cast<double>(val) < static_cast<double>(INT_MIN)) {
		std::cout << "int: impossible"  << std::endl;
	} else {
		std::cout << "int: " << static_cast<int>(val) << std::endl;
	}
	std::cout << "float: " << val;
	if (val == std::floor(val))
		std::cout << ".0";
	std::cout << "f" << std::endl;

	std::cout << "double: " << static_cast<double>(val);
    if (val == std::floor(val))
        std::cout << ".0";
    std::cout << std::endl;
}

e_type detectType(const std::string& input) {
	char *endPtr;
	strtod(input.c_str(), &endPtr);
	size_t pos_d = input.find('.');
	size_t pos_f = input.find('f');

	if (input == "-inf" || input == "+inf" || input == "-inff" || input == "+inff" || input == "nan" || input == "nanf") {
		return TYPE_PSEUDO;
	}
	if (pos_f == std::string::npos)
		pos_f = input.find('F');
	if (isChar(input)) {
		return TYPE_CHAR;
	}
	if (isInvalid(input, endPtr, pos_d)) {
		return TYPE_ERROR; 
	}
	if (isInt(input, pos_d)) {
		return TYPE_INT;
	}
	if (isDouble(pos_d, pos_f)) {
		return TYPE_DOUBLE;
	}
	if (isFloat(input, pos_d, pos_f)) {
		return TYPE_FLOAT;
	}
	return TYPE_ERROR;
}

void printChar(const char& c) {
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void printInt(const int& val) {
	if (val > 127 || val < 0) {
		std::cout << "char: impossible"  << std::endl;
	} else {
		if (isprint(static_cast<unsigned char>(val))) {
			std::cout << "char: '" << static_cast<char>(val) << "'"  << std::endl;
		} else {
			std::cout << "char: Non displayable"  << std::endl;
		}
	}
	std::cout << "int: " << static_cast<int>(val)  << std::endl;
	std::cout << "float: " << static_cast<float>(val) << ".0f"  << std::endl;
	std::cout << "double: " << static_cast<double>(val)  << ".0" << std::endl;
}

bool isChar(const std::string& input) {
	if (input.length() == 1 && !std::isdigit(input[0]))
		return true;
	return false;
}

bool isInt(const std::string& input, const size_t& pos_d) {	
	if (input.find_first_of("eE") == std::string::npos) {    
		if (pos_d == std::string::npos) {
			return true;
		}
	}
	return false;
}

bool isInt(const double& val) {
	return (std::floor(val) == val);
}


bool isDouble(const size_t& pos_d, const size_t& pos_f) {
	if (pos_d != std::string::npos && pos_f == std::string::npos)
		return true;
	return false;
}

bool isFloat(const std::string& input, const size_t& pos_d, const size_t& pos_f) {    
	if (input.find_first_not_of("eE") != std::string::npos) {
		return true;
	}
	if (pos_d != std::string::npos && pos_f != std::string::npos)
		return true;
	return false;
}

bool isInvalid(const std::string& input, const char* c, const size_t& pos_d) {
	std::string allowed = "0123456789.eEfF+-";
	size_t pos_e = input.find_first_of("eE");

	if (input.find_first_not_of(allowed) != std::string::npos)
		return true;
	if (*c == '\0')
		return false;
	if (((*c == 'f' || *c == 'F') && *(c + 1) == '\0')) {
		if (pos_d == std::string::npos && pos_e == std::string::npos) {
			return true;
		}
		return false;
	}
	return true;
}

