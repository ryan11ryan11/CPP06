#include "helper.hpp"

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

}