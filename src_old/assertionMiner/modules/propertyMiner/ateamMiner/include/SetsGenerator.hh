#pragma once

// this file is only a wrapper of methods.
//
namespace ateam {
namespace setsGenerator {

struct Sets {
    Sets();

    // unsupported supportMethods
    Sets(const Sets &) = delete;
    void operator=(const Sets &) = delete;

    ~Sets();

    // the number of items
    size_t numItems;
    // the number of items in each generated set
    size_t setSize;
    // the number of generated sets
    size_t numSets;
    // the generated sets
    size_t *setsArray;
};

// the methods generating the sets
void makeSubSets(Sets &sets);

} // namespace setsGenerator
} // namespace ateam
