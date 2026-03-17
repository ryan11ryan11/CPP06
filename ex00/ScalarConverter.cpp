/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:06:34 by junhhong          #+#    #+#             */
/*   Updated: 2026/03/16 18:01:06 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& obj) {
	(void) obj;
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& obj) {
	(void) obj;
	return *this;
}

void ScalarConverter::convert(const std::string& input) {
	char *endPtr;
    errno = 0;
	double result = std::strtod(input.c_str(), &endPtr);
	e_type type = detectType(input);

    if (errno == ERANGE) {
        std::cout << "char: " << "impossible" << std::endl;
        std::cout << "int: " << "impossible" << std::endl;
        std::cout << "float: " << "impossible" << std::endl;
        std::cout << "double: " << "impossible" << std::endl;
        return ;
    }
	std::cout << std::fixed << std::setprecision(1);

    if (type == TYPE_PSEUDO) {
        std::cout << "char: " << "impossible" << std::endl;
        std::cout << "int: " << "impossible" << std::endl;
        std::cout << "float: " << input << "f" << std::endl;
        std::cout << "double: " << input << std::endl;
    }
	if (type == TYPE_CHAR) {
        std::cout << "char: " << input << std::endl;
		printInt(result);
		std::cout << "float: " << static_cast<float>(input[0]) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(input[0]) << std::endl;
	}
	if (type == TYPE_ERROR) {
		std::cerr << "Incorrect input. only the decimal notation is allowed for this project" << std::endl;
	}
	if (type == TYPE_DOUBLE) {
        printChar(result);
		printInt(result);
		std::cout << "float: " << static_cast<float>(result) << "f" << std::endl;
		std::cout << "double: " << result << std::endl;
	}
	if (type == TYPE_FLOAT) {
        printChar(result);
        printInt(result);
		std::cout << "float: " << result << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(result) << std::endl;
	}
	if (type == TYPE_INT) {
        printChar(result);
		printInt(result);
		std::cout << "float: " << static_cast<float>(result) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(result) << std::endl;
	}
}

ScalarConverter::e_type ScalarConverter::detectType(const std::string& input) {
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
	if (isInt(pos_d)) {
		return TYPE_INT;
	}
	if (isDouble(pos_d, pos_f)) {
		return TYPE_DOUBLE;
	}
	if (isFloat(pos_d, pos_f)) {
		return TYPE_FLOAT;
	}
	return TYPE_ERROR;
}

void ScalarConverter::printChar(const double& val) {
    if (isInt(val) &&  (0 <= val && val <= 127)) {
        if (std::isprint(static_cast<unsigned char>(val))) {
            std::cout << "char: " << static_cast<unsigned char>(val) << std::endl;
        } else {
            std::cout << "char: Non displayable"  << std::endl;
        }
    } else {
        std::cout << "char: " << "impossible" << std::endl;
    }  
}

void ScalarConverter::printInt(const double& val) {
    if (val > INT_MAX || val < INT_MIN) {
        std::cout << "int: impossible"  << std::endl;
        return ;
    }
    std::cout << "int: " << static_cast<int>(val) << std::endl;
}

bool ScalarConverter::isChar(const std::string& input) {
	if (input.length() == 1 && !std::isdigit(input[0]))
		return true;
	return false;
}

bool ScalarConverter::isInt(const size_t& pos_d) {	
	if (pos_d == std::string::npos)
		return true;
	return false;
}

bool ScalarConverter::isInt(const double& val) {
    return (std::floor(val) == val);
}


bool ScalarConverter::isDouble(const size_t& pos_d, const size_t& pos_f) {
	if (pos_d != std::string::npos && pos_f == std::string::npos)
		return true;
	return false;
}

bool ScalarConverter::isFloat(const size_t& pos_d, const size_t& pos_f) {
	if (pos_d != std::string::npos && pos_f != std::string::npos)
		return true;
	return false;
}

bool ScalarConverter::isInvalid(const std::string& input, const char* c, const size_t& pos_d) {
	std::string allowed = "0123456789.eEfF+-";
	size_t pos_e = input.find("eE");

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
