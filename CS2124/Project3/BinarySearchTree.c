#include "BinarySearchTree.h"

/******
 * In this file, provide all of the definitions of the queue functions as described in BinarySearchTree.h.
 *
 * ****/

 BinarySearchTree newBinarySearchTree() {
   BinarySearchTreeImp* myBST = (BinarySearchTree)malloc(sizeof(BinarySearchTreeImp));
   myBST->root = NULL;
   return myBST;
 }


 //Free the BinarySearchTree and any nodes that still exist in the tree.  I recommend creating another "helper" function to recursively free all the nodes in the tree using a postorder traversal as discussed in class.
 void freeBinarySearchTree(BinarySearchTree tree) {
   if(tree->root == NULL) {
     return NULL;
   }
   freeBinarySearchTree(tree->root->left);
   freeBinarySearchTree(tree->root->right);
   free(tree->root);
   return NULL;
 }


 //Allocate a new node and store "value" as the Element in the node.  Return the address of the node.
 NodeT *allocateNode(Element value) {
   NodeT* myNode = (NodeT*)malloc(sizeof(NodeT));
   myNode->element = value;
   myNode->left = NULL;
   myNode->right = NULL;
   return myNode;
 }

 //Given a BinarySearchTree and a searchValue, return a pointer to the node in the tree that contains searchValue if you find it or return NULL if it does not exist.
 // I recommend writing a secondary function to recursively search the tree.
 NodeT *search(BinarySearchTree tree, int searchValue) {
   if (tree->root == NULL || tree->root->element->accountNumber == searchValue) {
     return tree->root;
   }
   else if(searchValue < tree->root->element->accountNumber) {
     return search(tree->root->left, searchValue);
   }
   else {
     return search(tree->root->right, searchValue);
   }
   return NULL;
 }

 //Create a node to store the given Element and add it as a leaf in the BinarySearchTree.  Do not worry about balancing the tree for this project.
 //Return true if the insert worked successfully, and return false if the node already existed in the tree.  I recommend writing a secondary function to recursively
 //search for where to insert the node as discussed in class.
 int insert(BinarySearchTree tree, Element value) {
   NodeT* node = allocateNode(value);
   if(tree->root == NULL) {
     tree->root = node;
     value.accountBalance = 0;
     return TRUE;
   }
   else {
     NodeT* tempRoot = tree->root;
     while(tempRoot != NULL) {
       if(tempRoot->element.accountNumber == value.accountNumber) {
         return FALSE; //account already exists
       }
       else if(value.accountNumber < tempRoot->element.accountNumber){
         if(tempRoot->left == NULL) {
           tempRoot->left = node;
           return TRUE;
         }
         else {
           tempRoot = tempRoot->left;
         }
       }
       else {
         if(tempRoot->right == NULL) {
           tempRoot->right = node;
           return TRUE;
         }
         else {
           tempRoot = tempRoot->right;
         }
       }
     }
     return FALSE;
   }

   // else if(value->accountNumber == tree->root->element->accountNumber) {
   //   return FALSE;
   // }
   // else {
   //   if(value->accountNumber < tree->root->element->accountNumber) {
   //     insert(tree->root->left, value);
   //   }
   //   else {
   //     insert(tree->root->right, value);
   //   }
   // }

 }


 //Print the key values of all nodes in the subtree rooted at p in increasing order.  I recommend writing a secondary function to recursively traverse the nodes.
 void printInOrder(BinarySearchTree tree) {
   if(tree->root == NULL)
   {
     return -1;
   }
   printInOrder(tree->root->left);
   printf("%d %f\n", tree->root->element->accountNumber, tree->root->element->accountBalance);
   printInOrder(tree->root->right);
 }

 //Print the key values of all nodes in the subtree rooted at p according to a preorder traversal.  I recommend writing a secondary function to recursively traverse the nodes.
 void printPreOrder(BinarySearchTree tree) {
   if(tree->root == NULL)
   {
     return -1;
   }
   printf("%d %f\n", tree->root->element->accountNumber, tree->root->element->accountBalance);
   printPreOrder(tree->root->left);
   printPreOrder(tree->root->right);
 }
