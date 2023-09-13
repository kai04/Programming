//https://leetcode.com/problems/subsets/description/
class Solution {
public:
/*
[1,2,3]
=3c0{[]} + 3c1{[1],[2],[3]} + 3c2{[1,2],[2,3],[1,3]} + 3c3{[1,2,3]}
=3c0+3c1+3c2+3c3 = 2^3 = 8

n*2^n = 10*2^10 = 10000
f(0,[],[[]]) = f(1,[],[[],[0]]) + f(1,[0],[[],[0]]) = f(2, [],[[],[0],[1]]) + f(2, [1],[[],[0],[1]]) +
f(2,[0,1],[[],[0],[1],[0,1]])
*/
    void helper(int i,vector<int>& nums, vector<int> currSet, vector<vector<int>> &allSet){
        int n = nums.size();
        //base case
        if(i>=n){
            return;
        }
        //choose
        currSet.push_back(nums[i]);
        allSet.push_back(currSet);
        helper(i+1,nums, currSet, allSet);

        //unchoose
        currSet.pop_back();
        helper(i+1,nums, currSet, allSet);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> myset;
        ans.push_back(myset);
        helper(0, nums, myset,ans);
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(),ans.end()), ans.end());
        return ans;
    }
};