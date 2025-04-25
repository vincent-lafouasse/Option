#include "poss/Option.hpp"

#include <cassert>
#include <iostream>
#include <typeinfo>

int main() {
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

    /*
    poss::Option<std::string> yes_string("what is up");
    assert(yes_string.is_some());
    assert(*yes_string == "what is up");

    poss::Option<std::string> no_string;
    assert(no_string.is_none());
    */

    std::cout << "All tests ok" << std::endl;
}
