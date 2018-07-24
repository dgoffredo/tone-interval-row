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
#include <iterator>
#include <ostream>

enum { N = 12 };

std::ostream& print(std::ostream& output, const int *begin, const int *end)
{
    for (const int *it = begin; it != end; ++it)
        output << std::setw(2) << *it << ' ';

    return output;
}

void printToneIntervalRows(std::ostream&   output,
                           int            *notesBegin, 
                           int            *notesEnd,
                           int            *intervalsBegin,
                           int            *intervalsEnd)
{
    switch (std::distance(notesBegin, notesEnd))
    {
      case N:
        print(output, notesBegin, notesEnd) << '\n';
        break;
      case 0:
        for (int n = 0; n < N; ++n)
        {
          *notesEnd = n;
          printToneIntervalRows(output,
                                notesBegin, notesEnd + 1,
                                intervalsBegin, intervalsEnd);
        }
        break;
      default:
        for (int n = 0; n < N; ++n)
        {
            if (std::find(notesBegin, notesEnd, n) != notesEnd)
                continue;
    
            const int interval = std::abs(n - *(notesEnd - 1));
            if (std::find(intervalsBegin, intervalsEnd, interval) != 
                                                                  intervalsEnd)
                continue;
    
            *notesEnd = n;
            *intervalsEnd = interval;
            printToneIntervalRows(output, 
                                  notesBegin, notesEnd + 1,
                                  intervalsBegin, intervalsEnd + 1);
        }
    }
}

void printToneIntervalRows(std::ostream& output)
{
    int notes[N];
    int intervals[N];

    printToneIntervalRows(output, notes, notes, intervals, intervals);
}

int main() 
{ 
    printToneIntervalRows(std::cout); 
}
