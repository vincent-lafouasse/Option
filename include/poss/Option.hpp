#pragma once

#include <stdexcept>

namespace poss {

template <typename T>
class Option {
   public:
    typedef T type_value;

    class None {};

    Option();
    Option(T value);  // NOLINT(*-explicit-constructor)

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

    void reset() {
        if (!this->some) {
            return;
        }

        this->val.~T();
        this->none = None();
        this->some = false;
    }

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

// ---------Implementation----------------

template <typename T>
Option<T>::BadOptionalAccess::BadOptionalAccess()
    : std::runtime_error("Direction vector is null") {}

template <typename T>
Option<T>::Option() : none(), some(false) {}

template <typename T>
Option<T>::Option(T value) : val(value), some(true) {}

template <typename T>
const T& Option<T>::value() const {
    if (!this->some) {
        throw BadOptionalAccess();
    }
    return this->val;
}
template <typename T>
T& Option<T>::value() {
    if (!this->some) {
        throw BadOptionalAccess();
    }
    return this->val;
}

template <typename T>
const T& Option<T>::operator*() const {
    return this->val;
}
template <typename T>
T& Option<T>::operator*() {
    return this->val;
}

template <typename T>
const T& Option<T>::value_or(const T& defaultValue) const {
    if (this->some) {
        return this->val;
    } else {
        return defaultValue;
    }
}
template <typename T>
T& Option<T>::value_or(T& defaultValue) {
    if (this->some) {
        return this->val;
    } else {
        return defaultValue;
    }
}

}  // namespace poss
