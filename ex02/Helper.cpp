#include "Helper.hpp"

Base* generate(void) {
	Base *result = NULL;

	std::srand(std::time(0));
	int choice = std::rand() % 3;
	std::cout << "Random choice: " << choice << std::endl;
	switch (choice) {
		case 0: result = new A;
		break;
		case 1: result = new B;
		break;
		case 2: result = new C;
		break;
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
