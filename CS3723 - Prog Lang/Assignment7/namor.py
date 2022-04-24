import sys

def namor(roman):

    maxRepeat = 0
    repeatingLen = 1
    last = ''

    # validating roman numeral
    for c in roman:
        if c == last:
            repeatingLen += 1
            if repeatingLen > maxRepeat:
                maxRepeat = repeatingLen
        else:
            repeatingLen = 1

        last = c

    if maxRepeat > 3:
        return 0

    # we have a valid numeral here

    dicts = [
                {3000 : "MMM", 2000 : "MM" , 1000 : "M"},
                {900 : "CM", 800 : "DCCC" , 700 : "DCC", 600 : "DC", 500 : "D", 400 : "CD", 300 : "CCC", 200 : "CC", 100 : "C"},
                {90 : "XC", 80 : "LXXX" , 70 : "LXX", 60 : "LX", 50 : "L", 40 : "XL", 30 : "XXX", 20 : "XX", 10 : "X"},
                {9 : "IX", 8 : " VIII", 7 : "VII", 6 : "VI", 5 : "V", 4 : "IV", 3 : "III", 2 : "II", 1 : "I"}
            ]

    num = 0

    for dict in dicts:
        for k, v in dict.items(): # despite the advice of not using dictionaries, we are using dicts
            if v in roman:
                if not roman.startswith(v): # great tip professor, thnx
                    continue
                
                # add key of value to sum of numeral
                num += k
                roman = roman[len(v):]
                break

    return num

if __name__ == "__main__":
    for num in sys.argv[1:]:
        print(f"{num} is {namor(num)}")
