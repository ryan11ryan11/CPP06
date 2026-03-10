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

    public:
        virtual void wow() = 0;
        static void convert(const std::string& input); 
};
