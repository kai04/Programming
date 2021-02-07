//https://www.interviewbit.com/problems/max-sum-path-in-binary-tree/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 int max_sum;
 static int pathsum(TreeNode* A){
     //base case
     if(A==NULL)
        return 0;
    int left = max(0,pathsum(A->left));
    int right = max(0,pathsum(A->right));
    int path = (left+right+A->val);
    max_sum = max(max_sum,path);
    int ret = (max(left,right)+A->val);
    // cout<<"Node:"<<A->val<<" left:"<<left<<" right:"<<right<<" path:"<<path<<" ret:"<<ret<<endl;
    return ret;
 }
int Solution::maxPathSum(TreeNode* A) {
    max_sum = INT_MIN;
    int ans = pathsum(A);
    ans = max(ans,max_sum);
    return ans;
}
