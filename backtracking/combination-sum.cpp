//https://leetcode.com/problems/combination-sum/description/
class Solution {
public:
    void helpers(int i, vector<int> &a, int n, int t,vector<int> res, vector<vector<int>> &ans){
        //base cases
        if(i>=n||t<0){
            return;
        }
        if(t==0){
            ans.push_back(res);
            return;
        }
        bool taken  = false;
        if(a[i]<=t){
            res.push_back(a[i]);
            helpers(i,a,n,t-a[i],res, ans);
            taken = true;
        }
        //ignore ith element
        if(taken)
            res.pop_back();
        helpers(i+1,a,n,t,res,ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        int n = candidates.size();
        vector<int> ans;
        helpers(0,candidates,n,target,ans,res);
        return res;
    }
};