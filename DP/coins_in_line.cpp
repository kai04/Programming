//https://www.interviewbit.com/problems/coins-in-a-line/

int Solution::maxcoin(vector<int> &A) {
    int n = A.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    int sum =0;
    for(int nums:A){
        sum+=nums;
    }
    
    for(int L=n-1;L>=0;L--){
        for(int R=L;R<n;R++){
            if(L==R){
                dp[L][R] = A[L];
            }
            else{
                dp[L][R] = max((A[L]-dp[L+1][R]),(A[R]-dp[L][R-1]));
            }
        }
    }
    int ans =(sum+dp[0][n-1])/2;
    return ans;
    
}

