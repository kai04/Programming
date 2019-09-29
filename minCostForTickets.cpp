/*
https://leetcode.com/problems/minimum-cost-for-tickets/
Input: days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
Output: 17
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> days;
    vector<int> costs;
    Solution(int n){
        days.resize(n);
        costs.resize(3);
    }
    int solve(int index,int lastPassValidDay,vector<int>& days,vector<int>& costs,vector<vector<int>> &dp){
        //base case
        int n = days.size();
        if(index==n-1){
            if(lastPassValidDay>=days[index]){
                return 0;
            }
            else{
                int ret = min(costs[0],costs[1]);
                ret = min(ret,costs[2]);
                dp[index][lastPassValidDay] = ret;
                return ret;
            }
        }
        //memoization
        if(dp[index][lastPassValidDay]!=(INT_MAX)/2){
            return dp[index][lastPassValidDay];
        }
        
        int res = INT_MAX/2;
        if(days[index]>lastPassValidDay){
            res = min(res,solve(index+1,(days[index]+1)-1,days,costs,dp)+costs[0]);
            res = min(res,solve(index+1,(days[index]+7)-1,days,costs,dp)+costs[1]);
            res = min(res,solve(index+1,(days[index]+30)-1,days,costs,dp)+costs[2]);
        }
        else{
            res = min(res,solve(index+1,lastPassValidDay,days,costs,dp));
        }
        dp[index][lastPassValidDay] = res;
        return res;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<vector<int>> dp(n,vector<int>(400,INT_MAX/2));
        return solve(0,0,days,costs,dp);
    }
};

int main(){
    int n;
    cin>>n;
    Solution s(n);
    
    for(int i=0;i<n;i++){
        cin>>s.days[i];
    }
    for(int i=0;i<3;i++){
        cin>>s.costs[i];
    }
    //
    int res =  s.mincostTickets(s.days,s.costs);
    cout<<res<ndl;
}