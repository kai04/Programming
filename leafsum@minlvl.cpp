/*https://practice.geeksforgeeks.org/problems/sum-of-leaf-nodes-at-min-level/1 */

/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


//User function Template for C++
/*
Structure of the Node of the tree is 
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};*/
// Your task is to complete this function
// function shoudl return the required sum
#include<bits/stdc++.h>
void searchm(Node* root,int x,priority_queue<pair<int,int>> &pq){
    if(root==NULL)
        return;
    else if(root->left==NULL && root->right==NULL){
        pq.push(make_pair(x,root->data));
    }
    else if(root->left==NULL)
    {
        searchm(root->right,x-1,pq);
    }
    else if(root->right==NULL){
        searchm(root->left,x-1,pq);
    }
    else{
        searchm(root->left,x-1,pq);
        searchm(root->right,x-1,pq);
    }
    
}
int minLeafSum(Node* root)
{
    if(root==NULL)
        return 0;
    priority_queue<pair<int,int>> pq;
    searchm(root,0,pq);
    int sum=0;
    pair<int,int> x = pq.top();
    while(!pq.empty()){
        pair<int,int> y =pq.top();
        pq.pop();
        if(y.first==x.first){
            sum+=y.second;
        }
        else{
            break;
        }
    }
    
        return sum;
    
	// Code here
}
