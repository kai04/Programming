//https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

static void inorder(TreeNode* root,int lvl,map<int,vector<pair<int,int>>> &m,int ht){
    if(root==nullptr){
        return;
    }
    m[lvl].push_back(make_pair(ht,root->val));
    inorder(root->left,lvl-1,m,ht+1);
    inorder(root->right,lvl+1,m,ht+1);
}

static bool mysort(pair<int,int> p1,pair<int,int> p2){
    if(p1.first<p2.first){
        return true;
    } else if(p1.first==p2.first){
        if(p1.second<p2.second){
            return true;
        }
        else{
            return false;
        }
    }
    return false;
}
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
       map<int,vector<pair<int,int>>> m;
        inorder(root,0,m,0);
        vector<vector<int>> ans;
        for(auto it:m){
            vector<pair<int,int>> temp = it.second;
            sort(temp.begin(),temp.end(),mysort);
            vector<int> temp1;
            for(auto it1:temp)
                temp1.push_back(it1.second);
            ans.push_back(temp1);
        }
        return ans;
    }
};
