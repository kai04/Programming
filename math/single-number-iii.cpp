//https://leetcode.com/problems/single-number-iii/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        int xor1 = nums[0];
        for(int i=1;i<n;i++){
            xor1 = xor1 ^ nums[i];
        }
        int ix = -1;
        bitset<32> b(xor1);
        for(int i=0;i<32;i++){
            if(b.test(i)){
                ix = i;
                break;
            }
        }
        int s_0 = 0,s_1=0;
        for(int i=0;i<n;i++){
            bitset<32> b_t(nums[i]);
            if(b_t.test(ix)){
                s_1 = s_1 ^ nums[i];
            } else {
                s_0 = s_0 ^ nums[i];
            }
        }
        vector<int> ans;
        ans.push_back(s_0);
        ans.push_back(s_1);
        return ans;
    }
};