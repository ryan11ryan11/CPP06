/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:06:29 by junhhong          #+#    #+#             */
/*   Updated: 2026/03/16 17:54:10 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <cerrno>
#include <climits>
#include <cmath>
#include <iomanip>
#include <cstdlib> // ?????
#include "HelperFunctions.hpp"

class ScalarConverter 
{
    private:
        enum e_type {
                TYPE_CHAR,
                TYPE_INT,
                TYPE_FLOAT,
                TYPE_DOUBLE,
                TYPE_ERROR,
                TYPE_PSEUDO
            };
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter& obj);
        ScalarConverter& operator=(const ScalarConverter& obj);

        static e_type detectType(const std::string& input);
        static bool isInvalid(const std::string& input, const char* c, const size_t& pos_d);
        static bool isChar(const std::string& input);
        static bool isInt(const size_t& pos_d);
        static bool isInt(const double& val);
        static bool isDouble(const size_t& pos_d, const size_t& pos_f);
        static bool isFloat(const size_t& pos_d, const size_t& pos_f);
        static void printChar(const double& val);
        static void printInt(const double& val);

    public:
        static void convert(const std::string& input); 
};
