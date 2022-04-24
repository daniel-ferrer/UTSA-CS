from namor import namor
from roman import roman

for k in range(4001):
    string_val = roman(k)
    error_count = 0
    
    if namor(string_val) != k:
        print(f"Converted {k} to {roman(k)} back to {namor(string_val)}, which is wrong.")
        error_count += 1

print(f"Checked values from 0 to 4000. Errors = {error_count}.")
