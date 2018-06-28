p = 12

notes = [x for x in range(2, p+1)]      #the notes different from 1
intervals = [x for x in range(1, p)]    #allowable intervals

def find_intervals(row):                    #given a tone row, computes the intervals
    ints = [(row[i] - row[i-1])%p for i in range(1, len(row))]
    return ints


def unique_intervals(row):              #given a tone row, decides if the intervals are non-repeating
    L=find_intervals(row)
    if any(L.count(i)>1 for i in L):
        return False
    else:
        return True

def next_note(set_of_rows):             #given a set of incomplete tone rows, generates a set of the next additions
    temp_tone_rows = []
    for r in set_of_rows:
        for n in notes:
            if n not in r:
                tr=r[0:]+[n]
                temp_tone_rows.append(tr)
    return temp_tone_rows

def choose_good(set_of_rows):       #from a list of tone rows, picks out the ones that do not repeat intervals
    temp_tone_interval_rows = []
    for r in set_of_rows:
        if unique_intervals(r) is True:
            temp_tone_interval_rows.append(r)
    return temp_tone_interval_rows

def collapse_row(row):
    while len(row) > 1:
        row = [(row[i] + row[i + 1])%p for i in range(0, len(row)-1, 2)]
    return row[0]

tone_interval_rows=[[1]]

while len(tone_interval_rows[0]) < p:   #alternately generates the next set of rows, and discards ones that repeat intervals
    tone_interval_rows = choose_good(next_note(tone_interval_rows))

for i in tone_interval_rows:
    print(collapse_row(i))