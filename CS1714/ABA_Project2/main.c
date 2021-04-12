#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "route-records.h"

int main( int argc, char *argv[] )
{
    /* 1. Declare variables here */
    FILE *fileIn;
    RouteRecord* records = NULL;
    SearchType st = 0;
    int x, unqRoutes;
    char userSelection[10];
    char key1[50], key2[50];

    /* 2. Check command line arguments here. If a command line argument (for the file name) is missing, 
    print out the following: ERROR: Missing file name and end the program */
    /* 3. Attempt to open the file. Print out Opening <filename>... before you call fopen(). */
    if(argc < 2)
    {
        printf("ERROR: Missing file name\n");
        return 1;
    }
    else if(argc >= 2)
    {
        printf("Opening %s\n", argv[1]);
        fileIn = fopen(argv[1], "r");
    }

    /* 4. Check to see if the file opens. If it does not open, 
    print out ERROR: Could not open file and end the program. */
    if(fileIn == NULL) 
    {
        printf("ERROR: Could not open file\n");
        return 1;
    }

    /* 5. Do the following to load the records into an array of RouteRecords
    	
    		5.1 Call createRecords(), which will read through the file once to find the total number of lines/records in the file. 
            Use this count, to dynamically allocate memory for an array of RouteRecords. 
            It returns a pointer to that array. Don't forget to rewind the file pointer.
    		
    		5.2 Call fillRecords() to go through the CSV file again to fill in the values. 
            It will then return the actual number of items the array has. 
            Recall that not all records in the original CSV file will be entered into the array. 
            Print the number of unique routes operated by different airlines: Unique routes operated by airlines: ???
    		
    		5.3 Close the the file.
    */

    records = createRecords(fileIn);
    unqRoutes = fillRecords(records,fileIn);
    

    
    /* 6. Create an infinite loop that will do the following:
    
    		6.1 Call printMenu()
    		
    		6.2 Ask the user to input a value for the menu
    		
    		6.3 Handle the case in which a non-integer value is entered
    		
    		6.4 Create a switch/case statement to handle all the menu options
    		
	    		6.4.1 Each option requires the user to enter a search key
	    		
	    		6.4.2 Quit needs to free the array
    
    */


    while(x != 5)
    {
        printMenu();
        scanf("%s", userSelection);
        x = atoi(userSelection);
        if(x == 0)
        {
            printf("Invalid input.");
        }
        else if(x < 1 || x > 5)
        {
            printf("Invalid choice.");
        }
        else
        {
            switch(x)
            {
                case 1:
                    st = x;
                    printf("Enter origin: ");
                    scanf("%s", key1);
                    printf("Enter destination: ");
                    scanf("%s", key2);
                    printf("\nSearching by route...\n");
                    SearchRecords(records, unqRoutes, key1, key2, 1);
                    break;
                case 2:
                    st = x;
                    fflush(stdin);
                    scanf("Enter origin: %s", key1);
                    printf("Searching by origin...\n");
                    SearchRecords(records, unqRoutes, key1, key2, 2);
                    break;
                case 3:
                    st = x;
                    scanf("Enter destination: %s", key1);
                    printf("Searching by destination...\n");
                    SearchRecords(records, unqRoutes, key1, key2, 3);
                    break;
                case 4:
                    st = x;
                    scanf("Enter airline: %s", key1);
                    printf("Searching by airline...");
                    SearchRecords(records, unqRoutes, key1, key2, 4);
                    break;
                case 5:
                    printf("Good-bye!\n");
                    free(records);
                    exit(1);
                default:
                    break;
            }
        }
    }
    return 0;
}