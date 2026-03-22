#include "Serializer.hpp"

int main()
{
    // 1. Create a non-empty Data structure 
    Serializer::Data myData;
    myData.name = "42 Common Core";

    Serializer::Data* originalPtr = &myData;

    // 2. Use serialize() on the address
    uintptr_t raw = Serializer::serialize(originalPtr);

    // 3. Pass return value to deserialize()
    Serializer::Data* deserializedPtr = Serializer::deserialize(raw);

    // 4. Ensure the return value compares equal to the original pointer 
    std::cout << "Original Pointer:     " << originalPtr << std::endl;
    std::cout << "Deserialized Pointer: " << deserializedPtr << std::endl;

    if (deserializedPtr == originalPtr) {
        std::cout << "Verification: SUCCESS (Pointers match)" << std::endl;
    } else {
        std::cout << "Verification: FAILURE (Pointers do not match)" << std::endl;
    }

    // 5. Verify data integrity to show the peer-evaluator it actually works
    std::cout << "Data inside deserialized pointer: " << deserializedPtr->name << std::endl;

    return 0;
}