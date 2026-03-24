#include "Base.hpp"
#include "Helper.hpp"

int main(){
	Base* baseClass;

	baseClass = generate();
	identify(baseClass);
	identify(*baseClass);
	return 0;
}
