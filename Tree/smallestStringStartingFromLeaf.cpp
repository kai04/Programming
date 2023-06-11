/**
https://leetcode.com/problems/smallest-string-starting-from-leaf/description/
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
    void helper(TreeNode* root, string pathstr, vector<string> &allstr){
        //base case
        if(root->left==nullptr && root->right==nullptr){
            string temp = string(1,('a'+root->val)) + pathstr;
            // cout<<temp<<endl;
            allstr.push_back(temp);
        }
        if(root->left!=nullptr){
            helper(root->left, string(1,('a'+root->val)) + pathstr,allstr);
        }
        if(root->right!=nullptr){
            helper(root->right, string(1,('a'+root->val)) + pathstr ,allstr);
        }
    }
    string smallestFromLeaf(TreeNode* root) {
        vector<string> a;
        helper(root,"",a);
        sort(a.begin(),a.end());
        return a[0];
    }
};