# Daniel Ferrer-Sosa (tfe646)

import sys

def ConquerTheProblem(A):
    if len(A) <= 1:
        return -1

    # get mid point of A[]
    mid = len(A) // 2  

    # split A[] into sub arrays
    L = A[:mid]
    R = A[mid:]

    # divide using recursion
    Lprofit = ConquerTheProblem(L)
    Rprofit = ConquerTheProblem(R)
    maxProfit = max(R) - min(L)

    # return value of max delta
    return max(max(Lprofit, Rprofit), maxProfit)

def main():
    # take file name as arg
    fname = str(sys.argv[1])

    # open file, read ctx, close file
    f = open(fname, "r")
    ctx = f.readlines()
    f.close()

    A= []
    count = 0

    # populate A[] with ctx from file
    for line in ctx:
        A.append(float(line))
        count+=1
    
    # CONQUER !
    if ConquerTheProblem(A) == -1:
        print("There is no feasible solution!")
    else:
        print("{}: The optimal solution for {} is {:.2f}.".format(fname, fname, ConquerTheProblem(A)))

if __name__ == '__main__':
    main()
    
