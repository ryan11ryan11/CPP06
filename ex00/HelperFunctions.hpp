/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HelperFunctions.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:36:40 by junhhong          #+#    #+#             */
/*   Updated: 2026/03/24 14:36:41 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERFUNCTIONS_HPP
# define HELPERFUNCTIONS_HPP

#include <iostream>
#include <cerrno>
#include <climits>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <cfloat>

enum e_type {
		TYPE_CHAR,
		TYPE_INT,
		TYPE_FLOAT,
		TYPE_DOUBLE,
		TYPE_ERROR,
		TYPE_PSEUDO
	};

bool isAllInputPrintable(const std::string& input);
e_type detectType(const std::string& input);
bool isInvalid(const std::string& input, const char* c, const size_t& pos_d);
bool isChar(const std::string& input);
bool isInt(const std::string& input, const size_t& pos_d);
bool isInt(const double& val);
bool isDouble(const size_t& pos_d, const size_t& pos_f);
bool isFloat(const std::string& input, const size_t& pos_d, const size_t& pos_f);
void printChar(const char& c);
void printInt(const int& val);
void printFloat(const float& val);
void printDouble(const double& val);
void printImpossible(void);

#endif
