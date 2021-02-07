//https://leetcode.com/problems/delete-node-in-a-bst/
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
    int find_inorder_predescor(TreeNode* root){
        TreeNode* curr = root->left;
        while(curr->right!=nullptr){
            curr = curr->right;
        }
        return curr->val;
    }
    
    int find_inorder_successor(TreeNode* root){
        TreeNode* curr = root->right;
        while(curr->left!=nullptr){
            curr = curr->left;
        }
        return curr->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr)
            return root;
        if(root->val>key){
            root->left = deleteNode(root->left, key);
        }   
        else if(root->val<key){
            root->right = deleteNode(root->right, key);
        }
        else{
            //check leaf
            if(root->left==nullptr && root->right==nullptr){
                return root = nullptr;
            }
            else if(root->left!=nullptr){
                //find inorder predecsor in left subtree
                root->val = find_inorder_predescor(root);
                root->left = deleteNode(root->left,root->val);
            }
            else if(root->right!=nullptr){
                //find inorder successor in right subtree
                root->val = find_inorder_successor(root);
                root->right = deleteNode(root->right,root->val);
            }
        }
        return root;
    }
};