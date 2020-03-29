//https://leetcode.com/problems/unique-binary-search-trees-ii/submissions/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
using namespace std;
static bool compare(TreeNode *node1,TreeNode *node2){
    if (node1 == NULL && node2 == NULL)  
        return true;  
  
    /* 2. both non-empty -> compare them */
    if (node1 != NULL && node2 != NULL)  
    {  
        return
        (  
            node1->val == node2->val &&  
            compare(node1->left, node2->left) &&  
            compare(node1->right, node2->right)  
        );  
    }  
      
    /* 3. one empty, one not -> false */
    return false;
} 
class Solution {
public:
    vector<TreeNode*> generateSubtrees(int start,int end) {
        vector<TreeNode*> ret;
        //base case 
        if(start>end){
            ret.push_back(NULL);
        }
        if(start==end){
            ret.push_back(new TreeNode(start));
        }
        
        for(int s =start;s<=end;s++){
            vector<TreeNode*> leftSubTreeList =  generateSubtrees(start,s-1);
            vector<TreeNode*> rightSubTreeList =  generateSubtrees(s+1,end);
            for(int i=0;i<leftSubTreeList.size();i++){
                for(int j=0;j<rightSubTreeList.size();j++){
                    // s is root of this subtree
                    TreeNode *node = new TreeNode(s);
                    node->left = leftSubTreeList[i];
                    node->right = rightSubTreeList[j];
                    ret.push_back(node);
                }
            }
        }
        return ret;
        
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n==0){
            return vector<TreeNode*>();
        }
            
        vector<TreeNode*> v =  generateSubtrees(1,n);
        vector<TreeNode*>::iterator ip; 
        ip = unique(v.begin(), v.end(),compare); 
        v.resize(distance(v.begin(), ip));
        return v;
    }
};