#pragma once

#include <stack>

template <typename T> struct MutantStack : public std::stack<T> {
    typedef typename std::stack<T>::container_type ctr;
    typedef typename ctr::iterator iterator;
    typedef typename ctr::const_iterator const_iterator;
    typedef typename ctr::reverse_iterator reverse_iterator;
    typedef typename ctr::const_reverse_iterator const_reverse_iterator;

    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
    const_iterator begin() const { return this->c.begin(); }
    const_iterator end() const { return this->c.end(); }
    reverse_iterator rbegin() { return this->c.rbegin(); }
    reverse_iterator rend() { return this->c.rend(); }
    const_reverse_iterator rbegin() const { return this->c.rbegin(); }
    const_reverse_iterator rend() const { return this->c.rend(); }
};
