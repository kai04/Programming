//https://www.hackerrank.com/challenges/tree-top-view/problem

#include<bits/stdc++.h>
using namespace std;
/*
struct node
{
    int data;
    node* left;
    node* right;
};

*/



map<int,int> mymap1;
map<node*,int> ind_map;

queue<node*> q1;
void levelOrder(node * root) {
q1.push(root);
    while(!q1.empty()){
         int y = (q1.front())->data;
        int x = ind_map[(q1.front())];
        // cout<<"node:"<<y<<" key:"<<x<<endl;
        map<int,int>::iterator it=mymap1.find(x);
        if(it==mymap1.end()){
            mymap1[x]=(q1.front())->data;
        }
        if((q1.front())->left!=NULL)
            q1.push((q1.front())->left);
        if((q1.front())->right!=NULL)
            q1.push((q1.front())->right);
        q1.pop();
    } 
}


void inorder(node * root,int x){
    ind_map[root]=x;
    if(root->left!=NULL){
        inorder(root->left,x-1);
    }
    if(root->right!=NULL){
        inorder(root->right,x+1);
    }
}

void topView(node * root) {
    inorder(root,0);
    levelOrder(root);
    for(auto it:mymap1){
      cout<<it.second<<" ";
    }  
    cout<<endl;
    
  
}

