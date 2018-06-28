tone-interval-row
=================
Trevor is getting atonal.

Here are a few implementations of a program that prints out all of the "tone
interval rows," which Trevor defines as (12-tone) tone rows that don't have
any repeating intervals.

On my machine, an optimized build of [search.cpp](search.cpp) is the fastest,
running in about a half of a second. [search-naive.cpp](search-naive.cpp) is
about ten times slower, and [search.rkt](search.rkt) is even three times slower
than that.

[search-naive.py](search-naive.py), whose algorithm is similar to
[search-naive.cpp](search-naive.cpp), seems to run forever.

[Trevor's code](trevor.py) runs quickly.