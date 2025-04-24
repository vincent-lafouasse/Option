#include "Option.hpp"

#include <cassert>
#include <iostream>

int main(void) {
    poss::Option<int> some(420);
    assert(some.is_some());

    poss::Option<int> none;
    assert(none.is_none());

    assert(typeid(poss::Option<int>::type_value) == typeid(int));

    std::cout << "All tests ok" << std::endl;
}
