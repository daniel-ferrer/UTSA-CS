#include "BinarySearchTree.h"


int main()
{
  FILE *fptr = fopen("smallInput.txt", "r");
  // FILE *fptr = fopen("largeInput.txt", "r");

  char cmd[8];
  Element account;


  if(fptr == NULL) {
    perror("Error opening file");
    return -1;
  }

  BinarySearchTree myTree = newBinarySearchTree();

  while(fscanf(fptr, "%s", cmd) == 1) {

    if(strcmp(cmd, "CREATE") == 0) {
      fscanf(fptr, "%d", &account.accountNumber);
      if(insert(myTree, account)) {
        printf("%d %lf\n", account.accountNumber, account.accountBalance);
      }
      else {
        printf("Account %d not created\n", account.accountNumber);
      }
    }

    else if(strcmp(cmd, "SALE") == 0) {
      int tempAccNum;
      double tempBal;
      fscanf(fptr, "%d %lf", &tempAccNum, &tempBal);
      printf("Test\n");
      if(search(myTree, tempAccNum) == NULL) {
        printf("Account %d not found\n", tempAccNum);
      }
      else {
        printf("Account %d found\n", tempAccNum);
        account.accountBalance +=  tempBal;
      }
    }

    else if(strcmp(cmd, "PRINT") == 0) {
      char printType[8];
      fscanf(fptr, "%s", printType);
      if(strcmp(printType, "PREORDER") == 0) {
        printf("Printing preorder\n");
        printPreOrder(myTree);
      }
      else if(strcmp(printType, "INORDER") == 0) {
        printf("Printing inorder\n");
        printInOrder(myTree);
      }
    }
  }

  freeBinarySearchTree(myTree);

  return 0;
}
