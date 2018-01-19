#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<int>> dp;
int n;
int change(int i,int t,vector<int> c){
    if(i>=n||t<0)
        return 0;
    if(t==0)
        return 1;
	//for ith coin we have 2 choices: 
		//1)either take it in the solution then our total change to total-coin[i] and again we recurse for ith coin and total-coin[i].
		//2)or simply discard in the solution then recurse for i+1 remaining coin(simply saying ith coin denomination not in solution) with same total. 
    if(dp[i][t]==-1)
        dp[i][t]=(change(i,t-c[i],c)+change(i+1,t,c));
    return dp[i][t];
}
int main() {
    int total;
    cin>>total>>n;
    vector<int> c(n);
    dp.resize(n+1,vector<int>(total+1,-1));
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    cout<<change(0,total,c)<<endl;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

