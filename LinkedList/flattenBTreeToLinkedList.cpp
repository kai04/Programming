//https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
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
    void preorder(TreeNode* root, vector<TreeNode*> &data){
        // preorder OLR
        if(root==NULL)
            return;
        data.push_back(root);
        preorder(root->left,data);
        preorder(root->right,data);
    }
    void flatten(TreeNode* root) {
        vector<TreeNode*> preOrder;
        preorder(root,preOrder);
        TreeNode* prev;
        for(int i = 0;i<preOrder.size();i++){
            if(i==0){
                preOrder[i]->left = NULL;
                preOrder[i]->right = NULL;
            } else{
                preOrder[i]->left = NULL;
                preOrder[i]->right = NULL;
                preOrder[i-1]->right = preOrder[i];
            }
        }
        
    }
};