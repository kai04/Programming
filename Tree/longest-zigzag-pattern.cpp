//https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/description/?envType=study-plan-v2&envId=leetcode-75
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
    vector<int> solve(TreeNode* node, int &ans){
        vector<int> ret(2,-1);
        if(node==NULL){
            return ret;
        }
        // if(node->left!=nullptr){
            vector<int> leftNode = solve(node->left, ans);
            ret[0] = 1+leftNode[1];
        // }
        // if(node->right!=nullptr){
            vector<int> rightNode = solve(node->right, ans);
            ret[1] = 1+rightNode[0];
        // }
        int t = max(ret[0],ret[1]);
        ans = max(t,ans);
        // cout<<"ADDR:"<<node<<" LEFT ->["<<leftNode[0]<<","<<leftNode[1]<<"] RIGHT ->["<<rightNode[0]<<","<<rightNode[1]<<"] CURRENT ->["<<ret[0]<<","<<ret[1]<<"]"<<" ANS:"<<ans<<endl;
        return ret;
    }
    void inorder(TreeNode* root,vector<TreeNode*> &v){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            if(curr!=nullptr){
                cout<<curr<<" ";
            }else{
                cout<<"NULL ";
            }
            if(curr!=nullptr){
                q.push(curr->left);
                q.push(curr->right);
            }
            q.pop();
        }
        cout<<endl;
    }
    int longestZigZag(TreeNode* root) {
        vector<TreeNode*> x;
        // inorder(root,x);
        int ans =0;
        vector<int> v = solve(root,ans);
        return ans;
    }
};