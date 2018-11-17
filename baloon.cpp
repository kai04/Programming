//https://leetcode.com/problems/burst-balloons/description/
#include <cmath>
#include <cstdio>
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int p;
    cin>>p;
    int a[p+2];
    a[0]=1;
    a[p+1]=1;
    for(int i=1;i<=p;i++){
        cin>>a[i];
    }
    int n=p+2;
    int dp[n][n]={};
    
    for(int k=2;k<n;k++){
        for(int left=0;left<n-k;left++){
            int right = left+k;
            for(int i=left+1;i<right;i++){
                dp[left][right]=max(dp[left][right],((a[left]*a[i]*a[right])+dp[left][i]+dp[i][right]));
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
    /*for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

