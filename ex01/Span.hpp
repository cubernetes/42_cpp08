#pragma once

#include <exception>
#include <vector>

class Span {
    unsigned int _max_size;
    std::vector<int> _nums;

  public:
    ~Span();
    Span();
    Span(unsigned int size);
    void addNumber(int);
    void shortestSpan();
    void longestSpan();

    struct SpanFullException : public std::exception {
        const char *what() const throw() /*override*/;
    };
    struct SpanImpossibleException : public std::exception {
        const char *what() const throw() /*override*/;
    };
};
