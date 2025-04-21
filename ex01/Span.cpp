#include "Span.hpp"
#include <algorithm>
#include <cstdlib>
#include <iterator>
#include <limits>
#include <set>
#include <vector>

Span::~Span() {}
Span::Span() : _nums(), _maxSize(), _minSpan(std::numeric_limits<unsigned int>::max()) {}
Span::Span(unsigned int size) : _nums(), _maxSize(size), _minSpan(std::numeric_limits<unsigned int>::max()) {}

void Span::addNumber(int x) {
    if (_nums.size() >= _maxSize)
        throw SpanFullException();

    std::multiset<int>::const_iterator it = _nums.lower_bound(x);
    if (it != _nums.end())
        _minSpan = std::min<unsigned int>(_minSpan, static_cast<unsigned int>(std::abs(*it - x)));
    if (it != _nums.begin()) {
        std::multiset<int>::const_iterator prev = it;
        --prev;
        _minSpan = std::min<unsigned int>(_minSpan, static_cast<unsigned int>(std::abs(x - *prev)));
    }

    _nums.insert(it, x);
}
void Span::addRange(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end) {
    if (_nums.size() + static_cast<unsigned long>(std::distance(begin, end)) > _maxSize) {
        throw SpanFullException();
    }
    //_nums.insert(_nums.end(), begin, end);
    for (std::vector<int>::const_iterator it = begin; it != end; ++it)
        addNumber(*it);
}
unsigned int Span::shortestSpan() const {
    if (_nums.size() < 2)
        throw SpanImpossibleException();
    return _minSpan;
}
unsigned int Span::longestSpan() const {
    if (_nums.size() < 2)
        throw SpanImpossibleException();
    return static_cast<unsigned int>(*_nums.rbegin() - *_nums.begin());
}

const char *Span::SpanFullException::what() const throw() { return "Span is full"; }
const char *Span::SpanImpossibleException::what() const throw() { return "Not enough numbers"; }
