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

void ScalarConverter::convert(const std::string& input) {
    errno = 0;
	char *ptr;
	double result;
	result = strtod(input.c_str(), &ptr);

    if (errno == HUGE_VAL) {
        std::cerr << "Expands to positive double expression that indicates overflow, not necessarily representable as a float" << std::endl;
        return ;
    }
	if (result == 0) {
        std::cerr << "Error: Conversion was not successful" << std::endl;
        return ;
    }
	if (*ptr == '\0')
    if (*ptr == 'f' && *(ptr + 1) == '\0')
}
