//https://leetcode.com/problems/path-sum/
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
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
            return false;
        bool lres = false;
        bool rres = false;
        int tsum = targetSum - (root->val);
        //base case
        if(root->left ==NULL && root->right ==NULL){
            if(tsum ==0){
                return true;
            } else {
                return false;
            }
        }
        if(root->left!=NULL){
            lres = hasPathSum(root->left, tsum);
        }
        if(root->right != NULL){
            rres = hasPathSum(root->right, tsum);
        }
        return (lres || rres);
    }
};