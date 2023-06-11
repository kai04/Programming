/**
https://leetcode.com/problems/sum-root-to-leaf-numbers/description/
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
class Solution {
public:
    void helpers(TreeNode* root, int pathsum, int &ans){
        //base case
        if(root->left==nullptr && root->right==nullptr){
            ans = ans + (pathsum*10 +root->val);
            return; 
        }
        if(root->left!=nullptr ){
           helpers(root->left, (pathsum*10 + root->val), ans);
        }

        if(root->right!=nullptr){
           helpers(root->right, (pathsum*10 + root->val), ans);
        }
        
    }

    int sumNumbers(TreeNode* root) {
        /*
        p(4,0,0)->p(9,4,0) -> p(5,49,0) -> p(1,49,495) -> p(0,4,992) = 1032

        */
        int ans =0;
        if(root==nullptr) return ans;
        helpers(root, 0, ans);
        return ans;
    }
};