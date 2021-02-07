//https://leetcode.com/problems/path-sum-iii/
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
static int ans;
static void print_map(unordered_map<int,int> &m){
    for(auto it:m){
        cout<<it.first<<" -> "<<it.second<<endl;
    }
    cout<<"-------------------------"<<endl;
}
static void inorder(int curr_sum,TreeNode* root,unordered_map<int,int> m,int s){
    if(root==nullptr){
        return ;
    }
    int temp = root->val;
    unordered_map<int,int> m1 = m;
    int y = temp+curr_sum;
    

    // cout<<"CURR NODE:"<<temp<<" SUM:"<<y<<endl;
    
        int z = y-s;
        if(m1.find(z)!=m1.end()){
            ans+=m1[z];
            // cout<<"ANS1:"<<ans<<endl;
        }
    if(y==s){
        ans++;
        // cout<<"ANS2:"<<ans<<endl;
    }
    m1[y]++;
    // print_map(m1);
    inorder(y,root->left,m1,s);
    inorder(y,root->right,m1,s);
}
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        ans = 0;
        unordered_map<int,int> m;
        inorder(0,root,m,sum);
        return ans;
    }
};