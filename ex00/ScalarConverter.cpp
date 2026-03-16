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
	double result = strtod(input.c_str(), &endPtr);
	e_type type = detectType(input);

	std::cout << std::fixed << std::setprecision(1);

	if (type == TYPE_CHAR) {
		std::cout << "char: " << input << std::endl;
		std::cout << "int: " << static_cast<int>(result) << std::endl;
		std::cout << "float: " << static_cast<float>(result) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(result) << std::endl;
	}
	if (type == TYPE_ERROR) {
		std::cerr << "Incorrect input. only the decimal notation is allowed for this project" << std::endl;
	}
	if (type == TYPE_DOUBLE) {
		std::cout << "char: " << static_cast<char>(result) << std::endl;
		std::cout << "int: " << static_cast<int>(result) << std::endl;
		std::cout << "float: " << static_cast<float>(result) << "f" << std::endl;
		std::cout << "double: " << result << std::endl;
	}
	if (type == TYPE_FLOAT) {
		std::cout << "char: " << static_cast<char>(result) << std::endl;
		std::cout << "int: " << static_cast<int>(result) << std::endl;
		std::cout << "float: " << result << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(result) << std::endl;
	}
	if (type == TYPE_INT) {
		std::cout << "char: " << static_cast<char>(result) << std::endl;
		std::cout << "int: " << result << std::endl;
		std::cout << "float: " << static_cast<float>(result) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(result) << std::endl;
	}
	if (type == TYPE_NOT_POSSIBLE) {
		std::cerr << "No conversion can be performed" << std::endl;
	}
}

void ScalarConverter::print(const double& result) {
	std::cout << "int: " <<static_cast<int>(result) << std::endl;
}

ScalarConverter::e_type ScalarConverter::detectType(const std::string& input) {
	char *endPtr;
	double result = strtod(input.c_str(), &endPtr);
	size_t pos_d = input.find('.');
	size_t pos_f = input.find('f');

	if (pos_f == std::string::npos)
		pos_f = input.find('F');
	if (isChar(input)) {
		return TYPE_CHAR;
	}
	if (isInvalid(input, endPtr, pos_d)) {
		return TYPE_ERROR;
	}
	if (result == 0) {
		return TYPE_NOT_POSSIBLE;
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
