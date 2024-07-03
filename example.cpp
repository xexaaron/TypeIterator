
#include "TypeIterator.h"
#include <iostream>

void example() {
    using MyTypeIterator = Utility::type_iterator<int, float, char>;

    static_assert(MyTypeIterator::Has<int>()); // SUCCESS
    // static_assert(MyTypeIterator::Has<bool>()); // ERROR
    static_assert(MyTypeIterator::HasAny<int, bool, char, float, std::byte>()); // SUCCESS
    // static_assert(MyTypeIterator::HasAll<int, bool, char, float, std::byte>()); // ERROR

    MyTypeIterator::Iterate([]<typename T>(){
        std::cout << Utility::GetTypename<T>() << std::endl;
    });
    
}

