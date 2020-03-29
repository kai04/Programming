
//https://www.interviewbit.com/problems/max-sum-without-adjacent-elements/
int Solution::adjacent(vector<vector<int> > &A) {
    int n=A[0].size();
    vector<int> dp(n+1,0);
    dp[1] = max(A[0][0],A[1][0]);
    for(int i=2;i<=n;i++){
        dp[i] = max(dp[i],(dp[i-2]+A[0][i-1]));
        dp[i] = max(dp[i],(dp[i-2]+A[1][i-1]));
        dp[i] = max(dp[i],dp[i-1]);
    }
    return dp[n];
}

