import sys

def main():
    # take file name as arg
    fname = str(sys.argv[1])

    # open file, read ctx, close file
    f = open(fname, "r")

    count = 1
    for line in f:
        if count % 2 == 0:
            print(line)
        count+=1

    f.close()

if __name__ == '__main__':
    main()