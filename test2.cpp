#include <bits/stdc++.h>
using namespace std;
int houseColor(vector<vector<int>> &house){
	int n = house.size();
	vector<vector<int>> dp(n, vector<int>(3,INT_MAX/2));
	//initialize
	for(int i=0;i<3;i++){
		dp[0][i] = house[0][i];
	}

	for(int i = 1;i<n;i++){
		for(int j =0;j<3;j++){
			for(int k =0;k<3;k++){
				if(k!=j)
					dp[i][j] = min(dp[i][j],house[i][j]+dp[i-1][k]);
			}
		}
	}
	int ans = INT_MAX/2;
	for(int i=0;i<3;i++){
		ans = min(ans,dp[n-1][i]);
	}
	return ans;
}

int main(){
	int n;
	cin>>n;
	vector<vector<int>> house(n,vector<int>(3));
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++)
			cin>>house[i][j];
	}
	int ans = houseColor(house);
	cout<<"ANS:"<<ans<<endl;
	return 0;
}