#include <iostream>
#include "Logger.h"
#include <vector>


int main() {
    int a = 10;
    Logger<int>::log(a);

    Logger<int*>::log(&a);

    std::cout << std::boolalpha;
    std::cout << MyStd::is_convertible_v<int, double> << std::endl;

    std::vector<int> v{1, 2, 3, 4};
    for (auto const& item: v) {
        std::cout << item << ' ';
    }
    std::cout << std::endl;

    return 0;
}