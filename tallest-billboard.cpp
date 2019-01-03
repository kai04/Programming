//https://leetcode.com/problems/tallest-billboard/
//Find two subset from array such that there sum is equal and there are elements are non overlapping,return the maximum sum of such two set 
#include <bits/stdc++.h>
using namespace std;
    int solve(int i,int s,vector<vector<int>> &dp,vector<int> rods,int maxsum){
        //base case
        // i reaches end of array and s = 0[no difference b/w set1 and set2] then return 0[positive sum of set1 is 0 ] if 0 if sum is 0(here origin is shifted thats why maxum)
        if(i==rods.size()){
            if(s==maxsum){
                return 0;
            }
            else return INT_MIN;
        }
        //logic is partion arr in 2 subset(set 1[positive val],set 2[negative val]) s.t there differnce should be 0
        // if a[i] is added in set 1 then +a[i] is inserted in set 1 whereas if a[i] is choosen to be inserted in set2 then -a[i] is inserted 
        // dp[i][s]:it denotes max positive sum (set 1) that can be achived from [i,n) s.t 
        //          there current sum (pos elt sum + negative elt sum + 0[if elts not choosen]) is s
        //          s can be also viewed as current differnce of two sets  
        //memoization
        if(dp[i][s]!=-1)
            return dp[i][s];
        //recursion
        // three choice for a[i]:
        /*
            1) a[i] added in set1 then dp[i][s]=a[i]+dp[i+1][s+a[i]]
            2) a[i] added in set2 then dp[i][s]=dp[i+1][s-a[i]]
            3  a[i] is not included in neither sets then dp[i][s]= dp[i+1][s]
        */
        //Note: maxsum is present to shift origin(because s can be negative value but index can never be negative)
        dp[i][s]=max(dp[i][s],maxsum+rods[i]+solve(i+1,s+rods[i],dp,rods,maxsum));
        dp[i][s]=max(dp[i][s],maxsum+solve(i+1,s-rods[i],dp,rods,maxsum));
        dp[i][s]=max(dp[i][s],maxsum+solve(i+1,s,dp,rods,maxsum));
        //reshift origin
        dp[i][s]=dp[i][s]-maxsum;        
        return dp[i][s];
    }
    int tallestBillboard(vector<int>& rods) {
        int n=rods.size();
        int maxsum=0;
        for(int i=0;i<rods.size();i++){
            maxsum+=rods[i];
        }
        vector<vector<int>> dp(n+1,vector<int>(2*maxsum+1,-1));
        return solve(0,maxsum,dp,rods,maxsum);
        
    }

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin>>v[i];
        /* code */
    }
    // Solution obj;
    // cout<<obj.tallestBillboard<<endl; 
    cout<<tallestBillboard(v)<<endl;
    /* code */
    return 0;
}
