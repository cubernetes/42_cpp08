#include "Span.hpp"

Span::~Span() {}
Span::Span() : _max_size(), _nums(_max_size) {}
Span::Span(unsigned int size) : _max_size(size), _nums() {}
void Span::addNumber(int num) {
    if (_nums.size() < _max_size)
        _nums.push_back(num);
    else
        throw SpanFullException();
}
void shortestSpan() {}
void longestSpan() {}

const char *Span::SpanFullException::what() const throw() { return "Span is full"; }
const char *Span::SpanImpossibleException::what() const throw() { return "Not enough numbers"; }
