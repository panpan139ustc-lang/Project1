//
// Created by panpan on 2025/12/12.
//

#ifndef TEMPLATEMETA_LOGGER_H
#define TEMPLATEMETA_LOGGER_H

#include <iostream>
#include <type_traits> //std::false_type std::true_type std::void_t

template<typename T, typename = void>
class Logger {
public:

    static void log(T const& value) {
        std::cout << "value: " << value << std::endl;
    }
};

template<typename T>
class Logger<T, typename std::enable_if<std::is_pointer<T>::value>::type> {
public:
    static void log(T const& value) {
        if (value ) {
            std::cout << "Pointer: " << *value << std::endl;
        } else {
            std::cout << "Pointer is nullptr" << std::endl;
        }
    }
};

template<>
class Logger<std::string> {
public:
    static void log(std::string const & value ) {
        std::cout << "std::string: " << value << std::endl;
    }
};

namespace MyStd {
    template<typename From, typename To, typename = void>
    struct is_convertible : std::false_type{};

    template<typename To>
    void test_implicit(To);


    template<typename From, typename To>
    struct is_convertible<From, To,
    std::void_t<decltype(test_implicit(std::declval<From>()))>>: std::true_type{};

    template<typename From, typename To>
    constexpr bool is_convertible_v = is_convertible<From, To>::value;
}


#endif //TEMPLATEMETA_LOGGER_H