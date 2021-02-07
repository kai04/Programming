//https://leetcode.com/problems/house-robber-iii/submissions/
#include<bits/stdc++.h>
using namespace std;


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root,map<TreeNode*,int> &dp){
        if(root==NULL){
            return 0;
        }
        //memoization
        if(dp.find(root)!=dp.end()){
            return dp[root];
        }
        //include
        int left_res = 0;
        if(root->left!=NULL){
            left_res = solve(root->left->left,dp) + solve(root->left->right,dp);
        }
        int right_res = 0;
        if(root->right!=NULL){
            right_res = solve(root->right->left,dp) + solve(root->right->right,dp);
        }
        int include_res = root->val + left_res + right_res;
        // not inlude
        int not_include_res = solve(root->right,dp) + solve(root->left,dp);
        
        dp[root] = max(include_res,not_include_res); 
        return dp[root];
    }
    int rob(TreeNode* root) {
        map<TreeNode*,int> dp;
        int res = solve(root,dp);
        return res;
    }
};
