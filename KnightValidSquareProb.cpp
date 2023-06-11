// N*N chessBoard, what is the probability of knight 
// on valid chess square after k moves]
#include <bits/stdc++.h>
using namespace std;
vector<int> X_dir = {-1,-2,-2,-1,1,2,2,1};
vector<int> Y_dir = {-2,-1,1,2,2,1,-1,-2};

float solve(int x,int y,int k, vector<vector<vector<float>>> &dp,int n){
	float prob = 1;

	//base case
	if(k==0)
		return 1;
	if(dp[x][y][k]!=-1){
		return dp[x][y][k];
	}

	for(int i=0;i<8;i++){
		int x_new = x+X_dir[i];
		int y_new = x+Y_dir[i];
		if(x_new>=0 && x_new<n && y_new>=0 && y_new<n){
			prob = prob * (float)(1/8) * solve(x_new,y_new,k-1,dp,n);
		}
	}
	dp[x][y][k] = prob; 
	return prob;
}


int main(){
	int n,k;
	cin>>n>>k;
	vector<vector<vector<float>>> dp(n+1,vector<vector<float>>(n,vector<float>(k+1,-1)));
	cout<<"ANS:"<<solve(0,0,k,dp,n)<<endl;
	return 0;
}