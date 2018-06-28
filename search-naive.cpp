// Identify each semitone in the octave with one of the integers from zero to
// eleven. Then a *tone row* is a permutation of the integers [0, 11]. Let a
// *tone interval row* be a tone row where the difference between two adjacent
// elements is distinct (where the first and last are not considered adjacent).
//
// For example, the following tone row:
//
//     0 1 3 6 10 11 2 6 4 8 5 9 7
//
// is *not* a tone interval row, because the difference between the adjacent
// elements 1 and 3 is the same as the difference between the adjacent elements
// 9 and 7, for example.
//
// However, the following tone row:
//
//     0 11 1 10 2 9 3 8 4 7 5 6
//
// is a tone interval row. Here is the corresponding sequence of adjacent
// differences:
//
//     11 10 9 8 7 6 5 4 3 2 1
//
// As you can see, they are all distinct.
//
// According to the output of this program, there are 1328 tone interval rows.

#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <iostream>

enum { N = 12 };

bool intervalsDistinct(const int (&notes)[N])
    // Return whether the specified sequence of notes contains no duplicated
    // intervals.
{
    bool usedInterval[N] = {};
    for (const int *it = notes + 1; it != notes + N; ++it) {
        const int interval = std::abs(*it - *(it - 1));
        if (usedInterval[interval])
            return false;
        else
            usedInterval[interval] = true;
    }

    return true;
}

std::ostream& print(std::ostream& output, const int (&notes)[N])
{
    for (const int *it = notes; it != notes + N; ++it)
        output << std::setw(2) << *it << ' ';

    return output;
}

int main()
{
    int current[N];
    for (int i = 0; i < N; ++i)
        current[i] = i;

    // For each permutation of the twelve notes, print the permutation if it
    // contains no duplicate intervals.
    do {
        if (intervalsDistinct(current))
            print(std::cout, current) << '\n';
    } while (std::next_permutation(current, current + N));
}