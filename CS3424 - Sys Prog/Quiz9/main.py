import sys

def main(args):
    text = args[1:]
    text.sort()
    
    line = ""
    for word in text:
        line += word + " "
    print(line)

if __name__ == '__main__':
    main(sys.argv)