#!/usr/bin/env python
import sys
from operator import itemgetter

word_and_count = {}
words_and_crimes = []

for line in sys.stdin:
    line.strip()
    word, count, crime_type = line.split('\t', 2)
    words_and_crimes.append((word, crime_type))
    try:
        count = int(count)
        word_and_count[word] = word_and_count.get(word, 0) + count 
    except ValueError:
        pass

sort_word_and_count = sorted(word_and_count.items(), key=itemgetter(0))

ret =  ""
for w, c in words_and_crimes:
    if w == sort_word_and_count[0][0]:
        if c not in ret:
            ret += c + ','

print(f'Most crimes were reported in {sort_word_and_count[0][0]}')
print(f'Total number of crimes reported in {sort_word_and_count[0][0]} is {sort_word_and_count[0][1]}')
print(f'Crimes Types reported in {sort_word_and_count[0][0]} are {ret}')
