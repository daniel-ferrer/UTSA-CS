import sys

def main():
    firstname = input("Enter your first name: ")
    birthdate = input("Enter your birthdate: ")

    try:
        with open(firstname + ".txt", "w") as f:
            f.write(birthdate)
    except IOError:
        sys.exit(1)

if __name__ == '__main__':
    main()