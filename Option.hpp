#pragma once

#include <stdexcept>

namespace poss {

template <typename T>
class Option {
   public:
    using type_value = T;

    class None {};

    class BadOptionalAccess : public std::runtime_error {
        // might add more runtime information about failing state later
       public:
        explicit BadOptionalAccess(const char* what) : runtime_error(what) {}
        BadOptionalAccess() : BadOptionalAccess("Direction vector is null") {}
    };

    Option() : self(None{}), some(false) {}
    Option(T value) : self(value), some(true) {}

    // checked, throws on bad access
    const T& value() const {
        if (!this->some) {
            throw BadOptionalAccess();
        }
        return this->self.val;
    }
    T& value() {
        if (!this->some) {
            throw BadOptionalAccess();
        }
        return this->self.val;
    }

    // unchecked, UB on bad access
    const T& operator*() const { return this->self.val; }
    T& operator*() { return this->self.val; }

    const T& value_or(const T& defaultValue) const {
        if (this->some) {
            return this->self.val;
        } else {
            return defaultValue;
        }
    }
    T& value_or(T& defaultValue) {
        if (this->some) {
            return this->self.val;
        } else {
            return defaultValue;
        }
    }

    void reset();

   private:
    union {
        T val;
        None none;
    } self;
    bool some;
};

}  // namespace poss
