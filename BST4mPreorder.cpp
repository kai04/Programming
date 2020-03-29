 // Definition for a binary tree node.
//https://leetcode.com/contest/weekly-contest-127/problems/construct-binary-search-tree-from-preorder-traversal/
 #include<bits/stdc++.h>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

queue<TreeNode*> q1;
void levelOrder(TreeNode *root) {
q1.push(root);
    while(!q1.empty()){
        int x = (q1.front())->val;
        cout<<x<<" ";
        if((q1.front())->left!=NULL)
            q1.push((q1.front())->left);
        else
            cout<<"NULL"<<" ";
        if((q1.front())->right!=NULL)
            q1.push((q1.front())->right);
        else
            cout<<"NULL"<<" ";
        q1.pop();
    } 
}
 
vector<vector<int>> splitList(vector<int> x,int y){
    vector<vector<int>> ret(2);
    for(int i=1;i<x.size();i++){
        if(x[i]<y){
           ret[0].push_back(x[i]); 
        }
        else{
            ret[1].push_back(x[i]);
        }
    }
    return ret;
} 

static TreeNode* bstFromPreorderUtils(vector<int> preorder){
    if(preorder.size()==0){
        return NULL;
    }
    int x = preorder[0]; 
    TreeNode *node = new TreeNode(x);
    vector<vector<int>> p = splitList(preorder,x);
    node->left = (TreeNode*) bstFromPreorderUtils(p[0]);
    node->right = (TreeNode*)bstFromPreorderUtils(p[1]);
    return node;
}
/*class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode  *root = bstFromPreorderUtils(preorder);
        return root;
    }
};*/

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    TreeNode *root = bstFromPreorderUtils(a);
    levelOrder(root);
    return 0;
}