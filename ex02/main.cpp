/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 13:20:41 by junhhong          #+#    #+#             */
/*   Updated: 2026/04/02 13:20:56 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "Helper.hpp"

int main(){
	Base* baseClass;

	baseClass = generate();
	identify(baseClass);
	identify(*baseClass);
	delete baseClass;

	return 0;
}
