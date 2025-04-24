#pragma once

#include <stdexcept>

namespace poss {

template <typename T>
class Option {
   public:
    typedef T type_value;

    class None {};

    Option();
    Option(T value);

    // checked, throws on bad access
    const T& value() const;
    T& value();

    // unchecked, UB on bad access
    const T& operator*() const;
    T& operator*();

    const T& value_or(const T& defaultValue) const;
    T& value_or(T& defaultValue);

    bool is_some() const { return this->some; }
    bool is_none() const { return !this->some; }

    void reset();

   private:
    union {
        T val;
        None none;
    };
    bool some;

   public:
    class BadOptionalAccess : public std::runtime_error {
        // might add more runtime information about failing state later
       public:
        BadOptionalAccess();
    };
};

#include "Option.inc.hpp"

}  // namespace poss
