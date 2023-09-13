//https://leetcode.com/problems/combinations/description/
class Solution {
public:
    void helper(int n, int k, vector<int> curr, vector<vector<int>> &res){
        //base case
        
        if(k==0){
            res.push_back(curr);
            return;
        }
        if(n==k){
            for(int i=1;i<=n;i++){
                curr.push_back(i);
            }
            res.push_back(curr);
            return;
        }
        if(n==0){
            return;
        }
        curr.push_back(n);
        helper(n-1, k-1,curr, res);
        curr.pop_back();
        helper(n-1, k,curr, res);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> curr;
        helper(n,k,curr,res);
        return res;
    }
};