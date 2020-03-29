//https://leetcode.com/problems/binary-tree-maximum-path-sum/
//https://www.geeksforgeeks.org/find-maximum-path-sum-in-a-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
static int ans =  INT_MIN;
class Solution {
public:
    int maxSum(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int maxPathSum = INT_MIN;
        int l = maxSum(root->left);
        int r = maxSum(root->right);
        int maxSingle = max(l,r)+root->val;
        maxSingle = max(maxSingle,root->val);
        maxPathSum = max(maxPathSum,maxSingle);
        int maxBoth = l+r+root->val;
        maxPathSum = max(maxPathSum,maxBoth);
        ans = max(ans,maxPathSum);
        return maxSingle;
    }
    int maxPathSum(TreeNode* root) {
        ans =  INT_MIN;
        int res = maxSum(root);
        return ans;
    }
};
