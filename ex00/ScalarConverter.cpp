/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:06:34 by junhhong          #+#    #+#             */
/*   Updated: 2026/03/24 14:51:50 by junhhong         ###   ########.fr       */
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
	errno = 0;
	e_type type = detectType(input);

	if (errno == ERANGE) {
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "impossible" << std::endl;
		std::cout << "double: " << "impossible" << std::endl;
		return ;
	}
	switch (type) {
		case (TYPE_ERROR): {
			std::cerr << "Incorrect input. only the decimal notation is allowed for this project" << std::endl;
		} break;
		case (TYPE_CHAR): {
			char c = input[0];
			printChar(c);
		} break;
		case (TYPE_PSEUDO): {
			std::string double_str = input;
			if (double_str == "-inff" || double_str == "+inff" || double_str == "nanf") {
				double_str = double_str.substr(0, double_str.length() - 1);
			}
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << double_str << "f" << std::endl;
			std::cout << "double: " << double_str << std::endl;
			return;
		} break;
		case (TYPE_INT): {
			long l = strtol(input.c_str(), NULL, 10);
			if (l > INT_MAX || l < INT_MIN) {
				printImpossible();
				return ;
			} else {
				int i = static_cast<int>(l);
				printInt(i);
			}
		} break;
		case (TYPE_FLOAT): {
			double d = std::strtod(input.c_str(), NULL);
			if (d > FLT_MAX || d < -FLT_MAX) {
				printImpossible();
			} else {
				float f = static_cast<float>(d);
				printFloat(f);
			}
		} break;
		case (TYPE_DOUBLE): {
			double d = std::strtod(input.c_str(), NULL);
			if (errno == ERANGE) {
				printImpossible();
			} else {
				printDouble(d);
			}
		} break;
	}
}
