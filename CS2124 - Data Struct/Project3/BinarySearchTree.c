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
   if(tree->root->element.accountNumber == searchValue) {
     return tree->root;
   }
   else {
     NodeT* tempNode = tree->root;
     while(tempNode->element.accountNumber != searchValue) {
     
       if(searchValue < tempNode->element.accountNumber) {
         if(tempNode->left->element.accountNumber == searchValue) {
           return tempNode->left;
         }
         else {
           tempNode = tempNode->left; 
         }
       }
       else {
         if(tempNode->right->element.accountNumber == searchValue) {
           return tempNode->right;
         }
         else {
           tempNode = tempNode->right;
         }
       }
     }
     return NULL;
   }
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
     NodeT* tempNode = tree->root;
     while(tempNode != NULL) {
       if(tempNode->element.accountNumber == value.accountNumber) {
         return FALSE; 
       }
       else if(value.accountNumber < tempNode->element.accountNumber){
         if(tempNode->left == NULL) {
           tempNode->left = node;
           return TRUE;
         }
         else {
           tempNode = tempNode->left;
         }
       }
       else {
         if(tempNode->right == NULL) {
           tempNode->right = node;
           return TRUE;
         }
         else {
           tempNode = tempNode->right;
         }
       }
     }
     return FALSE;
   }
 }


 //Print the key values of all nodes in the subtree rooted at p in increasing order.  I recommend writing a secondary function to recursively traverse the nodes.
 void printInOrder(BinarySearchTree tree) {
   if(tree->root == NULL)
   {
     return;
   }
   NodesInOrder(tree->root);
 }
 
 //InOrder Helper Function
 void NodesInOrder(NodeT* root) {
   if(root == NULL) {
     return;
   }
  
   NodesInOrder(root->left);
   printf("%d %0.2f\n", root->element.accountNumber, root->element.accountBalance);
   NodesInOrder(root->right);
   
 }

 //Print the key values of all nodes in the subtree rooted at p according to a preorder traversal.  I recommend writing a secondary function to recursively traverse the nodes.
 void printPreOrder(BinarySearchTree tree) {
   if(tree->root == NULL)
   {
     return;
   }
   NodesPreOrder(tree->root);
 }
 
 //PreOrder Helper Function
 void NodesPreOrder(NodeT* root) {
   if(root != NULL) {
     printf("%d %0.2f\n", root->element.accountNumber, root->element.accountBalance);
     NodesPreOrder(root->left);
     NodesPreOrder(root->right);
   }
   else {
     return;
   }

   
 }
