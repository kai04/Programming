//https://www.codingninjas.com/studio/problems/number-of-longest-increasing-subsequence_3751627
int findNumberOfLIS(vector<int> &arr)
{
    // Write your code here.
    int n = arr.size();
    int ans = 0,ret=0;
    vector<int> dp(n,1);
    vector<int> cnt(n,1);
    for(int i=1;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(arr[j]<arr[i] && dp[j]+1>dp[i]){
                dp[i] = dp[j] + 1;
                cnt[i] = cnt[j];
            } else if(arr[j]<arr[i] && dp[j]+1==dp[i]){
                cnt[i] += cnt[j];
            }
        }
        ans = max(ans, dp[i]);
    }
    for(int i=0;i<n;i++){
        if(dp[i]==ans){
            ret+=cnt[i];
        }
    }   
    return ret;
}