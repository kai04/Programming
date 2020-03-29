//https://leetcode.com/problems/house-robber-ii/
class Solution {
public:
    int sol(vector<int>& nums,int last,int i,vector<vector<int>> &dp,int start,int end){
        //base case
        if(i>end || i<start)
            return 0;
        if(dp[i][last]!=-1)
            return dp[i][last];
        
        if(last==0){
            dp[i][last]=max(dp[i][last],nums[i]+sol(nums,1,i+1,dp,start,end));
            dp[i][last]=max(dp[i][last],sol(nums,0,i+1,dp,start,end));
        }
        else{
            dp[i][last]=max(dp[i][last],sol(nums,0,i+1,dp,start,end));
        }
        return dp[i][last];
    }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        if(n==2){
            return max(nums[0],nums[1]);
        }
        vector<vector<int>> dp1(n,vector<int> (2,-1));
        vector<vector<int>> dp2(n,vector<int> (2,-1));
        vector<vector<int>> dp3(n,vector<int> (2,-1));
        // first element taken last no not taken 
         int ans1 = sol(nums,0,0,dp1,0,n-2);
        // first element not taken last no taken 
         int ans2 = sol(nums,0,1,dp2,1,n-1);
        // first element not taken last no not taken 
         int ans3 = sol(nums,0,1,dp3,1,n-2);
        // cout<<"ans1:"<<ans1<<" ans2:"<<ans2<<" ans3:"<<ans3<<endl;
        int ans = INT_MIN;
        ans =max(ans,ans1);
        ans =max(ans,ans2);
        ans =max(ans,ans3);
        return ans;
    }
};
