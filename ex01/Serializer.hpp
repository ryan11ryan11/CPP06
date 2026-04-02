#pragma once
#include <stdint.h> // uintptr_t
#include <iostream>


class Serializer {
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer& obj);
		Serializer& operator=(const Serializer& obj);

	public:
		struct Data {
			std::string name;
		};
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};
