#include <climits>
#include <stddef.h>

#include "../include/SetsGenerator.hh"
#include "oden/odenUtils/odenUtils.hh"

// https://en.wikipedia.org/wiki/Binomial_coefficient

namespace ateam {

namespace /**/ {

size_t binomial(size_t n, size_t k) {
    size_t c = 1, i;
    if (k > n - k)
        k = n - k; // take advantage of symmetry

    for (i = 1; i <= k; i++, n--) {
        // return 0 on overflow
        if (c / i > UINT_MAX / n)
            return 0;

        c = c / i * n + c % i * n / i; // split c*n/i into (c/i*i + c%i)*n/i
    }

    return c;
}

void store(const int comb[], int k, size_t *dictionary, size_t &dicPos) {
    for (int i = 0; i < k; ++i) {
        dictionary[dicPos] = static_cast<size_t>(comb[i]);
        ++dicPos;
    }
}

/*
    next_comb(int comb[], int k, int n)
    Generates the next combination of n elements as k after comb

    comb => the previous combination ( use (0, 1, 2, ..., k) for first)
    k => the size of the subsets to generate
    n => the size of the original set

    Returns: 1 if a valid combination was found
    0, otherwise
*/
int next_comb(int comb[], int k, int n) {
    int i = k - 1;
    ++comb[i];

    while ((i >= 0) && (comb[i] >= n - k + 1 + i)) {
        --i;

        if (i == -1)
            return 0;

        ++comb[i];
    }

    if (comb[0] > n - k) // Combination (n-k, n-k+1, ..., n) reached
        return 0;        // No more combinations can be generated

    // comb now looks like (..., x, n, n, n, ..., n).
    // Turn it into (..., x, x + 1, x + 2, ...)
    for (i = i + 1; i < k; ++i)
        comb[i] = comb[i - 1] + 1;

    return 1;
}

void generateSet(size_t nn, size_t kk, size_t *dictionary) {
    int n = static_cast<int>(nn);
    int k = static_cast<int>(kk);

    int *comb = new int[k];

    // Setup comb for the initial combination
    for (int i = 0; i < k; ++i)
        comb[i] = i;

    size_t dicPos = 0;
    store(comb, k, dictionary, dicPos);

    // Generate and store all the other combinations
    while (next_comb(comb, k, n))
        store(comb, k, dictionary, dicPos);

    delete[] comb;
}

} // namespace

namespace setsGenerator {

Sets::Sets() : numItems(0), setSize(0), numSets(0), setsArray(nullptr) {
    // ntd
}

Sets::~Sets() { delete[] setsArray; }

void makeSubSets(Sets &sets) {

    // generating the number of sets
    sets.numSets = binomial(sets.numItems, sets.setSize);

    if (sets.numSets == 0)
        messageWarning("Too many elements in the sets!");

    sets.setsArray = new size_t[sets.numSets * sets.setSize];

    // filling the array with all sets
    generateSet(sets.numItems, sets.setSize, sets.setsArray);
}

} // namespace setsGenerator
} // namespace ateam
