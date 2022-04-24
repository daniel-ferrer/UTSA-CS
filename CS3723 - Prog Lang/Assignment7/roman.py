import sys
from curses.ascii import isalnum

def roman(num):
    # chk if we recieved an integer
    isInteger = False
    if isinstance(num, int):
        isInteger = True

    # did not recieve an integer
    # chk if chars in string are numerical
    if not isInteger:
        valid = True    
        for c in num:
            if not isalnum(c):
                valid = False

        if not valid:
            return "Error"

        num = int(num)
    
    if not 0 < num <= 3999:
        return "Error"

    dict = {
            3000 : "MMM", 2000 : "MM" , 1000 : "M",
            900 : "CM", 800 : "DCCC" , 700 : "DCC", 600 : "DC", 500 : "D", 400 : "CD", 300 : "CCC", 200 : "CC", 100 : "C",
            90 : "XC", 80 : "LXXX" , 70 : "LXX", 60 : "LX", 50 : "L", 40 : "XL", 30 : "XXX", 20 : "XX", 10 : "X",
            9 : "IX", 8 : " VIII", 7 : "VII", 6 : "VI", 5 : "V", 4 : "IV", 3 : "III", 2 : "II", 1 : "I"
            }

    roman_numeral = ""

    for k, v in dict.items():
        if(k <= num):
            roman_numeral += v
            num -= k

    return roman_numeral

if __name__ == "__main__":
    for num in sys.argv[1:]:
        print(f"{num} is {roman(num)}")
