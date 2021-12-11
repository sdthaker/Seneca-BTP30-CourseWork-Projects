#ifndef ARGV_ITERATOR_H
#define ARGV_ITERATOR_H

#include <iterator>

template <class T>
class argv_iterator : public std::iterator <std::forward_iterator_tag, T> {
    int argc_;
    char** argv_;
    char** base_argv_;
    int increment_;
public:
    argv_iterator() : argc_(0), argv_(nullptr), base_argv_(nullptr), increment_(0) {}
    argv_iterator(int argc, char** argv, int increment) : argc_(argc), argv_(argv), base_argv_(argv), increment_(increment) {}

    bool operator!=(const argv_iterator&) {
        return argv_ != (base_argv_ + argc_);
    }

    T operator *() {
        return T(argv_);
    }

    void operator++ () {
        argv_ += increment_;
    }
};

#endif