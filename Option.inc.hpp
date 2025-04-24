#pragma once

#include "Option.hpp"

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
