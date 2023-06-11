//https://leetcode.com/problems/balance-a-binary-search-tree/
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
    void inorderTraversal(TreeNode* root, vector<int> &inorder){
        if(root==NULL)
            return;
        inorderTraversal(root->left,inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right,inorder);
        
    }
    TreeNode* balanceBSTHelper(int s, int e, vector<int> &inorder){
        //base cases
        if(s>e){
            return NULL;
        }
        if(s==e){
            return new TreeNode(inorder[s]);
        }
        int n = inorder.size();
        int m = s+ (e-s)/2;
        TreeNode* leftSubtree = balanceBSTHelper(s,m-1,inorder);
        TreeNode* rightSubtree = balanceBSTHelper(m+1,e,inorder);
        return new TreeNode(inorder[m], leftSubtree, rightSubtree);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        inorderTraversal(root,inorder);
        // for(auto it:inorder)
        //     cout<<it<<" ";
        // cout<<endl;
        int n = inorder.size();
        return balanceBSTHelper(0, n-1, inorder);
    }
};
