/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:06:34 by junhhong          #+#    #+#             */
/*   Updated: 2026/03/10 17:54:03 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& obj) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& obj) {}

void ScalarConverter::convert(const std::string& input) {
	char *ptr;
	double result;
    e_type type;
	result = strtod(input.c_str(), &ptr);

    if (result == 0) {
        type =
    }
}

ScalarConverter::e_type ScalarConverter::detectType(std::string& input) {
	char **pointer;
	double result = strtod(input.c_str(), pointer);

	if (result == 0) {
		std::cerr << "No conversion can be performed" << std::endl;
		return -1;
	}
	if (!isInvalid(input, *pointer)) {
		std::cerr << "Bad input" << std::endl;
		return -1;
	}
}

bool ScalarConverter::isInvalid(std::string& input, char* c) {
	if (*c != 'f' && *c != '\0')
		return false;
	return true;
}

bool ScalarConverter::isVaildInput(const std::string& input) {
	char *ptr;
	int result;
	result = strtod(input.c_str(), &ptr);

	if (result == 0)
		return false;
	if (result != 0 && *ptr == '\0')
		return true;
}