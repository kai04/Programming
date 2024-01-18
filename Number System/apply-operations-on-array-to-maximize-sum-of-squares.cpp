//https://leetcode.com/contest/weekly-contest-366/problems/apply-operations-on-array-to-maximize-sum-of-squares/
const int mod = 1e9 + 7;
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<bitset<32>> cand(k);
        vector<int> cnt(32,0);
        for(int i=0;i<n;i++){
            bitset<32> q(nums[i]);
            for(int j=0;j<32;j++){
                if(q.test(j)){
                    cnt[j]++;
                }
            }
        }
        
        for(int i=0;i<32;i++){
            int t = 0;
            while(cnt[i]>0 && t<k){
                cand[t].set(i);
                t++;
                cnt[i]--;
            }
        }
        
        
        int ans = 0;
        for(int i=0;i<k;i++){
            long x = cand[i].to_ulong();
            long long y =  (x*x)%mod;
            ans =  (ans + y)%mod;
        }
        return ans;
    }
};