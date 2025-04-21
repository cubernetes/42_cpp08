#include "Span.hpp"
#include <cstdio>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

int main() {
    std::cout << "Input number space-separated. You can also use ranges using a minus. E.g. 1 4 2-5 315" << std::endl;
    std::string line;
    while (std::getline(std::cin, line)) {
        std::istringstream iss(line);
        std::string part;
        Span span(1000 * 1000);
        while (std::getline(iss, part, ' ')) {
            std::string::size_type minus = part.find('-');
            if (minus != std::string::npos) {
                std::string before = part.substr(0, minus);
                std::string after = part.substr(minus + 1);
                char *end;
                long numBefore = strtol(before.c_str(), &end, 10);
                if (*end != '\0' || numBefore > std::numeric_limits<int>::max()) {
                    std::cout << "Couldn't parse start of range integer: '" << before << "'" << std::endl;
                } else {
                    long numAfter = strtol(after.c_str(), &end, 10);
                    if (*end != '\0' || numAfter > std::numeric_limits<int>::max()) {
                        std::cout << "Couldn't parse end of range integer: '" << after << "'" << std::endl;
                    } else {
                        int numBeforeInt = static_cast<int>(numBefore);
                        int numAfterInt = static_cast<int>(numAfter);
                        if (numAfterInt >= numBeforeInt) {
                            std::vector<int> range;
                            range.reserve(static_cast<std::vector<int>::size_type>(numAfterInt - numBeforeInt));
                            for (int i(numBeforeInt); i <= numAfterInt; ++i)
                                range.push_back(i);
                            span.addRange(range.begin(), range.end());
                        } else {
                            std::cout << "Range end must be after range start" << std::endl;
                        }
                    }
                }
            } else {
                char *end;
                long num = strtol(part.c_str(), &end, 10);
                if (*end != '\0' || num > std::numeric_limits<int>::max()) {
                    std::cout << "Couldn't parse integer: '" << part << "'" << std::endl;
                } else {
                    span.addNumber(static_cast<int>(num));
                }
            }
        }
        try {
            std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
            std::cout << "Longest span: " << span.longestSpan() << std::endl;
        } catch (const std::exception &e) {
            std::cout << "\033[31mCaught exception: " << e.what() << "\033[m" << std::endl;
        }
    }
    return 0;
}
