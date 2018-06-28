#!/usr/bin/env python3.6

import itertools

N = 12

def intervals(row):
    return (abs(left - right) for left, right in zip(row[:-1], row[1:]))

def intervals_distinct(row):
    return len(set(intervals(row))) == len(row) - 1

for row in itertools.permutations(range(N)):
    if intervals_distinct(row):
        print(' '.join('{:2}'.format(n) for n in row))