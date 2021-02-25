#include "Stack.h"

#define MAX_LINE_LENGTH 50


int convertToPostfix(char *infixString, char *postfixString);
int evaluatePostfix(char *postfixString);


int main()
{
	FILE *inputFile;
	inputFile = fopen("p1Input.txt", "r");
	if(inputFile == NULL){

		perror("Error opening file");
		return -1;
	}


	//This string will hold the infix equations that are read from inputFile, one at a time.
	char infixString[MAX_LINE_LENGTH];


	//Use fgets to read the next line from the inputFile.
	//Store the line into infixString.
	//The while loop repeats until there are no more lines in the file.
	while(fgets(infixString, MAX_LINE_LENGTH, inputFile)!=NULL){

		//If the line is blank, skip it.
		if(infixString[0] == '\n')
		continue;

		printf("Current infix string: %s",infixString);

		//postfixString is a string to store the equation from szInfixString converted into postfix.
		char postfixString[MAX_LINE_LENGTH];

		//Call the convertToPostfix function (that you are to implement below main).
		int returnMessage = convertToPostfix(infixString,postfixString);


		//convertToPostfix should return an integer letting us know if the infix string was in a valid format.
		//If the format is valid (we returned 0), then we call the evalutaePostfix function (that you are to implement below), and print the result of the evalution.
		//If the format is not valid (we returned something other than 0), then we print the corresponding error message.
		switch(returnMessage)
		{

			case 0: //0 means the infix string had no errors.  Go ahead and evaluate the postfix string.
			printf("Postfix string: %s\n",postfixString);
			int result = evaluatePostfix(postfixString);
			printf("It evaluates to %d.\n",result);
			break;
			case 1:  //1 means the infix string is missing a left parenthesis.
			printf("WARNING: Missing left parenthesis.\n");
			break;
			case 2: //2 means the infix string is missing a right parenthesis.
			printf("WARNING: Missing right parenthesis.\n");
			break;
			case 3: // 3 means missing operator.
			printf("WARNING: Missing operator.\n");
			break;
			case 4: //4 means missing operand.
			printf("WARNING: Missing operand.\n");
			break;
			default:
			printf("WARNING: %d.\n", returnMessage);


		}


		printf("\n\n");
	}

	fclose(inputFile);

	return 0;
}


/*******
int convertToPostfix(char *infixString, char *postfixString)

Input:
infixString is a character array of length <= MAX_LINE_LENGTH that contains an equation in infix format.
postfixString is a currently empty character array of length <= MAX_LINE_LENGTH that we should fill with a postfix representation of infixString.

Output:
We return an integer based on any errors found in infixString.
If there are no errors, return 0.
If there is a missing (, return 1.
If there is a missing ), return 2.
If there is a missing operator, return 3 (for extra credit).
If there is a missing operand, return 4 (for extra credit).
*********/
int convertToPostfix(char *infixString, char *postfixString)
{
	int i, err;
	int j = 0;
	Element e, e2;
	char chIn = infixString[i];
	Stack myStack = newStack(MAX_LINE_LENGTH);

	for(i = 0; chIn != '\0' && chIn != '\n'; i++) // looping through expression given
	{
		err = 0; // init err counter to 0
		if(chIn == '/' || chIn == '*' || chIn == '-' || chIn == '+') // if infixString[i] is an operator
		{
			if(isEmpty(myStack)) //if stack is empty
			{
				e.operation = chIn;
				push(myStack, e);
			}
			else // if stack is not empty
			{
				if(chIn == '*' || chIn == '/')
				{
					while(!isEmpty(myStack))
					{
						e = topElement(myStack);
						if(e.operation == '/' || e.operation == '*')
						{
							e = pop(myStack);
							postfixString[j] = e.operation;
							j++;
						}
					}
					e2.operation = chIn;
					push(e, e2);
				}
				if(chIn == '-' || chIn == '+')
				{
					while(!isEmpty(myStack))
					{
						e = topElement(myStack);
						if(e.operation != '(')
						{
							e = pop(myStack);
							postfixString[j] = e.operation;
							j++
						}
						else
						{
							break;
						}
					}

					e2.operation = chIn;
					push(e, e2);
				}
			}
		}
		else if(chIn == '(')
		{
			e.operation = chIn;
			push(myStack, e);
		}
		else if(chIn == ')')
		{
			e = topElement(myStack);

			while(e.operation != '(')
			{
				e = pop(myStack);

				if(isEmpty(myStack))
				{
					freeStack(myStack);

					err = 1;
					return err;
				}
				postfixString[j] = e.operation;
				j++
				e = topElement(myStack);
			}
			e = pop(myStack);

			if(e.operation != '(')
			{
				freeStack(myStack);
				err = 1;
				return err;
			}
		}
		else
		{
			postfixString[j] == chIn;
			j++;
		}
		chIn = infixString[i];
	}

	if(!isEmpty(myStack))
	{
		do {
			e = topElement(myStack);

			if(e.operation == '(')
			{
				freeStack(myStack);
				err = 2;
				return err;
			}
			else if(e.operation == '/' || e.operation == '*' || e.operation == '-' || e.operation == '+')
			{
				e = pop(myStack);
				postfixString[j] = e.operation;
			}

		} while(!isEmpty(myStack));
	}

	postfixString[j] = '\0';
	freeStack(myStack);
	return 0;

}





/************
evaluatePostfix(char *postfixString)

Input:
postfixString is a string of length <= MAX_LINE_LENGTH that contains an equation in postfix representation.
If your convertToPostfix() function is correct, this string should be in a valid postfix format.

Output:
Return an integer representing what the postfix equation evaluated to.
************/
int evaluatePostfix(char *postfixString){



}
