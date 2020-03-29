//https://www.geeksforgeeks.org/check-if-a-given-binary-tree-is-sumtree/
#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
bool isSumTree(struct Node* node);
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
  struct Node* node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
/* Computes the number of nodes in a tree. */
int height(struct Node* node)
{
  if (node==NULL)
    return 0;
  else
    return 1 + max(height(node->left), height(node->right));
}


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
// Should return true if tree is Sum Tree, else false
int preorder(Node* root,bool &flag){
    if(!flag){
        return -1;
    }
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return root->data;
    }
    int x=0,y=0;
    if(root->left!=NULL)
        x = preorder(root->left,flag);
    if(root->right!=NULL)
        y = preorder(root->right,flag);
    if(x+y!=root->data){
        flag = false;
    }
    return (root->data+x+y);
    
}
bool isSumTree(Node* root)
{
    bool flag =true;
    int res = preorder(root,flag);
    return flag;
    
     // Your code here
}