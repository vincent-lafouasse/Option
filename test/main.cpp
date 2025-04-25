#include "poss/Option.hpp"

#include <cassert>
#include <iostream>
#include <typeinfo>

int main(void) {
    poss::Option<int> some(420);
    assert(some.is_some());
    assert(*some == 420);
    assert(some.value() == 420);
    assert(some.value_or(69) == 420);

    some.reset();
    assert(some.is_none());

    poss::Option<int> none;
    assert(none.is_none());
    try {
        none.value();
    } catch (const poss::Option<int>::BadOptionalAccess& e) {
        // success
    }
    assert(none.value_or(69) == 69);

    assert(typeid(poss::Option<int>::type_value) == typeid(int));

    std::cout << "All tests ok" << std::endl;
}
