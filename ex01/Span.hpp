#pragma once

#include <exception>
#include <set>
#include <vector>

class Span {
    std::multiset<int> _nums;
    unsigned int _maxSize;
    unsigned int _minSpan;

  public:
    ~Span();
    Span();
    Span(unsigned int size);
    void addNumber(int);
    void addRange(std::vector<int>::const_iterator, std::vector<int>::const_iterator);
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

    struct SpanFullException : public std::exception {
        const char *what() const throw() /*override*/;
    };
    struct SpanImpossibleException : public std::exception {
        const char *what() const throw() /*override*/;
    };
};
