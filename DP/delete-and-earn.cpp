//https://leetcode.com/problems/delete-and-earn/submissions/
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n==0)
            return 0;
        vector<int> dp(n,-1);
        map<int,int> cnt;
        int p=0;
        while(p<n && nums[p]==nums[0]){
            cnt[nums[0]]++;
            dp[p] = cnt[nums[0]]*nums[0];
            p++;
        }
        
        for(int i=p;i<n;i++){
            cnt[nums[i]]++;
            int prev = nums[i]-1;
            int y = 0;
            if(cnt.find(prev)!=cnt.end()){
                int j = i - cnt[nums[i]];
                //nums[i] not taken
                if(j>=0){
                    dp[i] = dp[j];
                }
                //nums[i] taken
                int x = cnt[nums[i]]*nums[i];
                int k = i-(cnt[nums[i]] + cnt[nums[i]-1]);
                if(k>=0){
                    dp[i] = max(dp[i],x+dp[k]);
                }
                else{
                    dp[i] = max(dp[i],x);
                }
                // cout<<"i:"<<i<<" j:"<<j<<" k:"<<k<<" x:"<<x<<" dp[i]:"<<dp[i]<<endl;
            }
            else{
                int j = i - cnt[nums[i]];
                int x = cnt[nums[i]]*nums[i];
                //nums[i] taken
                if(j>=0){
                    dp[i] = dp[j]+x;
                }
                // cout<<"i:"<<i<<" j:"<<j<<" x:"<<x<<" dp[i]:"<<dp[i]<<endl;
            }
        }
        /*for(auto it:dp)
            cout<<it<<" ";
            cout<<endl;*/
        return dp[n-1];
    }
};