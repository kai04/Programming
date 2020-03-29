//https://leetcode.com/problems/burst-balloons/description/
#include <cmath>
#include <cstdio>
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<int> p(n+2);
        p[0]=1;
        p[n+1]=1;
        for(int i=1;i<=n;i++){
            p[i]=nums[i-1];
        }
        n=p.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,INT_MIN/2));
        for(int i=0;i<n;i++){
            // cin>>p[i];
            dp[i][i]=0;
        }
        
        // vector<vector<int>> dp(n,vector<int>(n,INT_MAX/2));
        // cout<<matChainMul(1,n-1,p,dp)<<endl;
        for(int l=1;l<=n-1;l++){
            for(int i=1;i<n;i++){
                int j=i+l;
                if(i<j && j<n && i+1< n){
                    for(int k=i;k<j;k++){
                        // cout<<"i:"<<i<<" j:"<<j<<" k:"<<k<<endl;
                        dp[i][j]=max(dp[i][j],(dp[i][k]+dp[k+1][j]+(p[i-1]*p[k]*p[j])));
                    }
                }
            }
        }
        return dp[1][n-1];
    }
  
    
};

