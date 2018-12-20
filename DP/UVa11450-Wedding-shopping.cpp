/*
UVa 11450 Wedding shopping
testcase 1:
12 3
3
6 4 8
2
5 10
4
1 5 3 5
----------------------
testcase 2
25 3
3
6 4 8
2 
10 6
4
7 3 1 5
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9 + 7;

int solve(int t,int m,vector<vector<int>> &input,vector<vector<int>> &dp,int M){
	// cout<<"t:"<<t<<" m:"<<m<<endl;
	//base case
	if(t==0){
		if(m==M){
			return -1;
		}
		if(m>=0){
			return M-m;
		}
		else{
			return INT_MIN;
		}
	}
	//memoization
	if(dp[t][m]!=-1){
		return dp[t][m];
	}
	// cout<<"here:"<<endl;
	//recursion
	// vector<int> v=input[t-1];
	for(int i=0;i<input[t-1].size();i++){
		if(input[t-1][i]<=m)
			dp[t][m]=max(dp[t][m],solve(t-1,m-input[t-1][i],input,dp,M));
	}
	return dp[t][m];

}

int main(){
	int m,c;
	cin>>m>>c;
	vector<vector<int>> input;
	for(int i=0;i<c;i++){
		int x;
		cin>>x;
		vector<int> v(x);
		for(int j=0;j<x;j++){
			cin>>v[j];
		}
		input.push_back(v);
	}
	vector<vector<int>> dp(c+1,vector<int>(m+1,-1));
	cout<<solve(c,m,input,dp,m)<<endl;
	return 0;
}
