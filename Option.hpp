#pragma once

#include <stdexcept>

namespace poss {

template <typename T>
class Option {
   public:
    using type_value = T;

    class None {};

    Option(): self(None{}), some(false) {}
    Option(T value): self(value), some(true) {}

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
   class BadOptionalAccess: std::runtime_error {

   };
};

}  // namespace poss
