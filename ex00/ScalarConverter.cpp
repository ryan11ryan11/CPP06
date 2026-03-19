/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:06:34 by junhhong          #+#    #+#             */
/*   Updated: 2026/03/19 14:58:23 by junhhong         ###   ########.fr       */
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
    std::cout << std::fixed << std::setprecision(1);
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

void ScalarConverter::printImpossible(void) {
    std::cout << "char: impossible"  << std::endl;
    std::cout << "int: impossible"  << std::endl;
    std::cout << "float: impossible"  << std::endl;
    std::cout << "double: impossible"  << std::endl;
}

void ScalarConverter::printDouble(const double& val) {
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
        std::cout << "float: " << static_cast<float>(val) << "f" << std::endl;
    }
    std::cout << "double: "  << val << std::endl;
}

void ScalarConverter::printFloat(const float& val) {
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
    std::cout << "float: " << val << "f" << std::endl;
    std::cout << "double: "  << static_cast<double>(val) << std::endl;
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
	if (isInt(input, pos_d)) {
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

void ScalarConverter::printChar(const char& c) {
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void ScalarConverter::printInt(const int& val) {
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
    std::cout << "float: " << static_cast<float>(val) << "f"  << std::endl;
    std::cout << "double: " << static_cast<double>(val)  << std::endl;
}

bool ScalarConverter::isChar(const std::string& input) {
	if (input.length() == 1 && !std::isdigit(input[0]))
		return true;
	return false;
}

bool ScalarConverter::isInt(const std::string& input, const size_t& pos_d) {	
    if (input.find_first_of("eE") == std::string::npos) {    
        if (pos_d == std::string::npos) {
            return true;
        }
    }
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
