#include "MutantStack.hpp"
#include <cstddef>
#include <iostream>
#include <limits>

int main() {
    MutantStack<int> m;
    m.push(13);
    m.push(42);
    m.push(1337);
    m.push(1729);
    m.push(9999);
    m.push(std::numeric_limits<int>::max());
    m.push(19);
    std::cout << "Top of stack: " << m.top() << std::endl;
    std::cout << "Popping top of stack" << std::endl;
    m.pop();
    std::size_t idx = 0;
    for (MutantStack<int>::const_reverse_iterator it = m.rbegin(); it != m.rend(); ++it) {
        std::cout << "Stack at " << idx << ": " << *it << std::endl;
        ++idx;
    }
    return 0;
}
