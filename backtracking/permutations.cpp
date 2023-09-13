//https://leetcode.com/problems/permutations/
class Solution {
public:
    void helper(vector<int> curr, vector<vector<int>> &res, vector<int> &nums){
        if(curr.size()==nums.size()){
            res.push_back(curr);
            return;
        }
        for(int x:nums){
            if(find(curr.begin(), curr.end(), x)==curr.end()){
                curr.push_back(x);
                helper(curr, res, nums);
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        /*
            3! = 6
            p([1,2,3]) = (1 + p([2,3])) + (2 + p([1,3])) + (3+ p([1,2]))
            p([1,2]) = (1 + p([2])) + (2+p([1]))
            p([1]) = [1]
            p([2]) = [2]
        */
        vector<int> curr = {};
        vector<vector<int>> res;
        helper(curr, res, nums);
        return res;
    }
};