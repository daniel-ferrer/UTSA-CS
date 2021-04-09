#include "BinarySearchTree.h"


int main()
{
  FILE *fptr = fopen("largeInput.txt", "r");

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
      insert(myTree, account);
    }

    else if(strcmp(cmd, "SALE") == 0) {
      int tempAccNum;
      double tempBal;
      NodeT* tempNode;
      fscanf(fptr, "%d %lf", &tempAccNum, &tempBal);
      tempNode = search(myTree, tempAccNum);
      if(tempNode != NULL) {
         tempNode->element.accountBalance +=  tempBal;
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
    else {
      freeBinarySearchTree(myTree);
      break;
    }
  }
  return 0;
}
