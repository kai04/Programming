//https://leetcode.com/problems/number-of-longest-increasing-subsequence/
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
     int n=nums.size();
        if(n<=1)
            return n;
        vector<int> dp(n+1,1);
        vector<int> length(n,1);
        dp[0]=1;
        for(int j=1;j<n;j++){
            for(int i=0;i<j;i++){
                if(nums[i]<nums[j]){
                    if(length[i]>=length[j]){
                        length[j]=length[i]+1;
                        // length[i]=length[j];
                        dp[j]=dp[i];
                    }
                    else if(length[i]+1==length[j]){
                        dp[j]+=dp[i];
                        
                    }
                    
                }
            }
        }
        int longest=*max_element(length.begin(),length.end());
        int ans=0;
        for(int i=0;i<length.size();i++){
            if(length[i]==longest){
                ans+=dp[i];
            }
        }
      
        return ans;
    }
};
