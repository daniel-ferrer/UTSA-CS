import re

def hasThreeQuestions(expression):
    match = re.search("(.+\?+){3}", expression.lower())

    print(expression)

    if match is None:
        print("no match!\n")
    else:
        print("matched 3 questions!\n")


def main():
    hasThreeQuestions("This is a string you should not match. Hello??")
    hasThreeQuestions("This is a string you should match. Hello?? Anybody home? Are you here?")
    hasThreeQuestions("Hello? What time is it? Anybody home? This is a string you should match.")
    hasThreeQuestions("Hello? This is a string you should not match. Anybody Home?")


if __name__ == '__main__':
    main()