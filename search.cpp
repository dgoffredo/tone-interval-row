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