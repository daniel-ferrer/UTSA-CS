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
 //fgets(infixString, MAX_LINE_LENGTH, inputFile)!=NULL
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


/*******sd
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
  deblank(infixString);
	int i = 0, j = 0, err = 0;
	char ch = infixString[i];
	Stack myStack = newStack(MAX_LINE_LENGTH);
 
	while(ch != '\0' && ch != '\n')
 	{
    Element ele, ele2;
		if(isOperator(ch) == 1) // if ch scanned is an operator
    {
      if(isEmpty(myStack) == 1) // if stack is empty
      {
        ele.operation = ch;
        push(myStack, ele); // push ele to stack
      }
      else
      {
        if(checkPrecendence(ch) == 2) // check operator precendence for '*' or '/'
        {
          while(isEmpty(myStack) == 0) // while stack is not empty
          {
            ele = topElement(myStack);
            if(checkPrecendence(ele.operation) == 2) // check operator precendence for '*' or '/'
            {
              ele = pop(myStack);
              postfixString[j] = ele.operation;
              j++;
            }
            else
              break;
          }
          ele2.operation = ch;
          push(myStack, ele2);
        }
        if(checkPrecendence(ch) == 1) // check operator precendence for '+' or '-'
        {
          while(isEmpty(myStack) == 0)
          {
            ele = topElement(myStack);
            if(ele.operation != '(')
            {
              ele = pop(myStack);
              postfixString[j] = ele.operation;
              j++;
            }
            else
              break;
          }
          ele2.operation = ch;
          push(myStack, ele2);
        } 
      }
    }
    else if(ch == '(') //if open paren is found push onto stack
    {
      ele.operation = ch;
      push(myStack, ele); 
    }
    else if(ch == ')') // if close paren is found
    { 
      if(isEmpty(myStack) == 1) //push onto stack if its empty
      {
        ele.operation = ch;
        push(myStack, ele);
      }
      else // else look for open paren in stack
      {
        ele = topElement(myStack);
        while(ele.operation != '(')
        {
          ele = pop(myStack); // pop ele in stack until open paren is found
          if(isEmpty(myStack) == 1) //if stack is empty and no open paren is found
          {
            freeStack(myStack);
            err = 1;
            return err; //return err no open paren
          }
          postfixString[j] = ele.operation;
          j++;
          ele = topElement(myStack);
        }
        ele = pop(myStack);
        if(ele.operation != '(')
        {
          freeStack(myStack);
          err = 1;
          return err; //return err no open paren
        }
      }
    }
    else // isalpha(ch) == true
    {
        postfixString[j] = ch;
        j++;
    }
    i++; // iterate next idx
    ch = infixString[i];
    
  } // end while
  
  if(isEmpty(myStack) == 0) // if stack is not empty
  {
    while(isEmpty(myStack) == 0) // while stack is not empty
    { 
      Element ele;
      ele = topElement(myStack);
      if(ele.operation == '(') //if top element is open paren
      {
        freeStack(myStack);
        err = 2; // there will be no close paren in stack, return err 2
        return err;
      }
      else if(isOperator(ele.operation) == 1) // if operator is found
      {
        ele = pop(myStack);
        postfixString[j] = ele.operation; // pop and append to postfixString
        j++;
      }
    }
  }
  postfixString[j] = '\0'; // terminate postfixString
  freeStack(myStack);
  return 0;
} // end func

/************
evaluatePostfix(char *postfixString)

Input:
postfixString is a string of length <= MAX_LINE_LENGTH that contains an equation in postfix representation.
If your convertToPostfix() function is correct, this string should be in a valid postfix format.

Output:
Return an integer representing what the postfix equation evaluated to.
************/
int evaluatePostfix(char *postfixString)
{
  int ans = 0, i = 0;
  char ch = postfixString[i];
  Stack myStack = newStack(MAX_LINE_LENGTH);
  Element op1, op2, temp;
  
  while(ch != '\0' && ch != '\n')
  {
    if(isdigit(ch)) //move operands to stack
    {
      temp.operand = ch - '0'; //thanks prof Gibson for this line of code
      push(myStack, temp);
    }
    else if(isOperator(ch) == 1) //pop 2 operands and perform operation based on operator
    {
      op1 = pop(myStack);
      op2 = pop(myStack);
      
      switch(ch)
      {
        case '*':
          ans = op1.operand * op2.operand;
          break;
        case '/':
          ans = op2.operand / op1.operand;
          break;
        case '+':
          ans = op1.operand + op2.operand;
          break;
        case '-':
          ans = op2.operand - op1.operand;
          break;
      }
      temp.operand = ans;
      push(myStack, temp);
    }
    i++;
    ch = postfixString[i];
  }
  freeStack(myStack);
  return ans;
}
