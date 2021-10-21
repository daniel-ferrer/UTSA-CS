import sys

def main():
    firstname = input("Enter your first name: ")
    birthdate = input("Enter your birthdate: ")

    f = open(firstname + ".txt", "w")
    f.write(birthdate)
    f.close()

if __name__ == '__main__':
    main()