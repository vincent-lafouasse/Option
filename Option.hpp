#pragma once

#include <stdexcept>

namespace poss {

template <typename T>
class Option {
   public:
    using type_value = T;

    class None {};

    Option() : self(None{}), some(false) {}
    Option(T value) : self(value), some(true) {}

    // checked, throws on bad access
    const T& value() const;
    T& value();

    // unchecked, UB on bad access
    const T& operator*() const;
    T& operator*();

    const T& value_or(const T& defaultValue) const;
    T& value_or(T& defaultValue);

    void reset();

   private:
    union {
        T val;
        None none;
    } self;
    bool some;

   public:
    class BadOptionalAccess : public std::runtime_error {
        // might add more runtime information about failing state later
       public:
        explicit BadOptionalAccess(const char* what) : runtime_error(what) {}
        BadOptionalAccess() : BadOptionalAccess("Direction vector is null") {}
    };
};

}  // namespace poss
