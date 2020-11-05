#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//following function prints all the possible paawords
void printPasswords(int m, char** arr,int n, char* ans)
{
   //if max allowed length of string is 0, return
   if(n==0)
   {
       return;
   }
   //print all the possible strings by adding a single character to existing ans string
   int i;
   for(i=0;i<m;i++)
   {
       //temp stores the answer fater adding a character at the end of ans and prints it
       char* temp = (char*)malloc(sizeof(ans));
       strcpy(temp,ans);
       strcat(temp,arr[i]);
       printf("%s\n",temp);
   }
   //calling recursion on all possible strings that can be generated
   for(i=0;i<m;i++)
   {
       char* temp = (char*)malloc(sizeof(ans));
       strcpy(temp,ans);
       strcat(temp,arr[i]);
       printPasswords(m,arr,n-1,temp);
   }
}
//driver function
int main(int argc, char *argv[])
{
   //assigns value of m
   int m = atoi(argv[1]);
   //assigns value on n
   int n = atoi(argv[argc-1]);
   //string array to store the characters passed as arguments
   char** arr =(char **)malloc(m*sizeof(char*));
   //initialising the answer string
   char* ans =(char*)malloc((n+1)*sizeof(char));
   ans = "";
   //initializing arr array
   int i;
   for(i=0;i<m;i++)
   {
       arr[i] = argv[i+2];
   }
   //calling print printPasswords
   printPasswords(m,arr,n,ans);
   return 0;
}