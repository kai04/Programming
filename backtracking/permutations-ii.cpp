//https://leetcode.com/problems/permutations-ii/
class Solution {
public:
    void helper(vector<int>& nums, vector<int> curr, vector<vector<int>> &res){
        if(curr.size()==nums.size()){
            vector<int> x;
            for(int c: curr){
                x.push_back(nums[c]);
            }
            res.push_back(x);
            return;
        }
        unordered_map<int, bool> y;
        for(int i=0;i<nums.size();i++){
            if(find(curr.begin(), curr.end(), i)==curr.end()){
                if(y.find(nums[i])==y.end()){
                    curr.push_back(i);
                    helper(nums, curr, res);
                    curr.pop_back();
                    y[nums[i]] = true;    
                }
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> curr = {};
        vector<vector<int>> res;
        helper(nums, curr, res);
        return res;
    }
};