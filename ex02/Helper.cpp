/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Helper.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 13:20:30 by junhhong          #+#    #+#             */
/*   Updated: 2026/04/02 13:20:31 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Helper.hpp"

Base* generate(void) {
	Base *result = NULL;

	std::srand(std::time(0));
	int choice = std::rand() % 3;
	std::cout << "Random choice: " << choice << std::endl;
	switch (choice) {
		case 0: {
			result = new A;
			std::cout << "Class A has made" << std::endl;
			break;
		}
		case 1: {
			result = new B;
			std::cout << "Class B has made" << std::endl;
			break;
		}
		case 2: {
			result = new C;
			std::cout << "Class C has made" << std::endl;
			break;
		}
		default:
			return NULL;
	}
	return (result);
}


void identify(Base* p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "A" << std::endl;
	}
	else if(dynamic_cast<B*>(p)) {
		std::cout << "B" << std::endl;
	}
	else if(dynamic_cast<C*>(p)) {
		std::cout << "C" << std::endl;
	}
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (const std::exception& e) {}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (const std::exception& e) {}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (const std::exception& e) {}
}
