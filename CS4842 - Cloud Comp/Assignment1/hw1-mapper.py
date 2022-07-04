#!/usr/bin/env python
from csv import reader
import sys


for line in reader(sys.stdin):
    boros, crimes = (line[13].strip(), line[7].strip())
    if not boros or not crimes or boros == "BORO_NM":
         continue
    
    print(f'{boros}\t{1}\t{crimes}')
