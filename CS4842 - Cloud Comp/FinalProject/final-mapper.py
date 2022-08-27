#!/usr/bin/env python
import sys

from csv import reader
from numpy import NaN

for line in reader(sys.stdin):

     sentiment = line[0].strip()
     neg_reason = line[1].strip()
     airline = line[2].strip()
     text = line[3].strip()
     
     if ( 
          not sentiment or sentiment == 'airline_sentiment' or 
          neg_reason == 'negativereason' or 
          not airline or airline == 'airline' or  
          not text or text == 'text'
     ): continue
     
     if not neg_reason:
          neg_reason = NaN
          
     text = text.replace('@', '', -1)
     text = text.replace('\n', '', -1)
     text = text.replace('\r', '', -1)
     
     print(
          f'{sentiment}\t'
          f'{neg_reason}\t'
          f'{airline}\t'
          f'{text}'
          )
