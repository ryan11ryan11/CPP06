/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:06:29 by junhhong          #+#    #+#             */
/*   Updated: 2026/03/10 17:50:36 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <cerrno>
#include <cmath>
#include "HelperFunctions.hpp"

class ScalarConverter 
{
    private:
        enum e_type {
                TYPE_CHAR,
                TYPE_INT,
                TYPE_FLOAT,
                TYPE_DOUBLE,
                TYPE_NOT_POSSIBLE,
                TYPE_ERROR
            };
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter& obj);
        ScalarConverter& operator=(const ScalarConverter& obj);

        static e_type detectType(std::string& input);
        static bool isInvalid(std::string& input, char* c);
        static bool isVaildInput(const std::string& input);

    public:
        static void convert(const std::string& input); 
};
