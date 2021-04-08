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
        printf("Created new account %d", account.accountNumber);
      }
      else {
        printf("Account %d not created", account.accountNumber);
      }
    }

    else if(strcmp(cmd, "SALE") == 0) {
      double tempBal;
      fscanf(fptr, "%d %f", &account.accountNumber, &tempBal);
      if(search(myTree-, account.accountNumber) == NULL) {
        printf("Account %d not found", account.accountNumber);
      }
      else {
        printf("Account %d found", account.accountNumber);
        account.accountBalance +=  tempBal;
      }
    }

    else if(strcmp(cmd, "PRINT") == 0) {
      char printType[8];
      fscanf(fptr, "%s", printType);
      if(strcmp(printType, "PREORDER") == 0) {
        printPreOrder(myTree);
      }
      else if(strcmp(printType, "INORDER") == 0) {
        printInOrder(myTree);
      }
    }
  }

  freeBinarySearchTree(myTree);

  return 0;
}
