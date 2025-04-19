#include "easyfind.hpp"

#include <iostream>
#include <iterator>
#include <vector>

int main() {
    std::vector<int> ints(10);
    ints[0] = 2;
    ints[1] = 4;
    ints[2] = 6;
    ints[3] = 8;
    ints[4] = 10;
    ints[5] = 12;
    ints[6] = 42;
    ints[7] = 16;
    ints[8] = 18;
    ints[9] = 20;
    std::vector<int>::iterator res = easyfind(ints, 42);
    if (res != ints.end()) {
        std::cout << "Found 42 at position: " << std::distance(ints.begin(), res) << std::endl;
    } else {
        std::cout << "Couldn't find 42" << std::endl;
    }

    // Also works for const iterators
    const std::vector<int> ints2(10);
    std::vector<int>::const_iterator res2 = easyfind(ints2, 42);
    if (res2 != ints2.end()) {
        std::cout << "Found 42 at position: " << std::distance(ints2.begin(), res2) << std::endl;
    } else {
        std::cout << "Couldn't find 42" << std::endl;
    }

    std::cout << "Distance: " << std::distance(ints.begin(), ints.end()) << std::endl;
    return 0;
}
