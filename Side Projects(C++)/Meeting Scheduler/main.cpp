#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

#include "argv_iterator.h"
#include "meeting.h"

template <typename InputIterator>
static void check_for_conflicts(InputIterator begin, InputIterator end);

int
main(int argc, char* argv[]) {
    std::vector<meeting> schedule;

    // Use the argv_iterator to convert the argc/argv command-line
    // parameters into an iterator and copy the contents into the
    // schedule vector.
    std::copy(argv_iterator<meeting>(argc - 1, argv + 1, 4),
        argv_iterator<meeting>(),
        std::back_inserter(schedule));

    std::sort(schedule.begin(), schedule.end());

    check_for_conflicts(schedule.begin(), schedule.end());

    std::copy(schedule.cbegin(),
        schedule.cend(),
        std::ostream_iterator<meeting>(std::cout, "\n"));

    return 0;
}

template <class InputIterator>
static void check_for_conflicts(InputIterator begin, InputIterator end) {
    
    for (auto itr = begin; itr != end;) {
        itr = std::adjacent_find(itr, end);

        if (itr != end) {
            std::cout << "CONFLICT:\n" << " " << itr[0] << std::endl << " " << itr[1] << std::endl << std::endl;
            ++itr;
        } 
    }
}