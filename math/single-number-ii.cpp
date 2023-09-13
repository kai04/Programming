//https://leetcode.com/problems/single-number-ii
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt0(32,0),cnt1(32,0);
        for(int i=0;i<n;i++){
            // string s = to_string(nums[i]);
            bitset<32> b(nums[i]);
            for(int j=0;j<32;j++){
                if(b.test(j)){
                    cnt1[j]++;
                } else{
                    cnt0[j]++;
                }
            }
        }
    
        string y(32,'0');
        for(int i=0;i<32;i++){
            if(cnt0[i]%3==1){
                y[i] = '0';
            } else if(cnt1[i]%3==1){
                y[i] = '1';
            }
        }
        reverse(y.begin(),y.end());
        bitset<32> b1{y};
        int ret = b1.to_ulong();
        return ret;
    }
};