//https://www.geeksforgeeks.org/bell-numbers-number-of-ways-to-partition-a-set/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	/* code */
	int n;
	cin>>n;
	vector<vector<int> > dp(n,vector<int>(n,0));
	//initialize
	dp[0][0]=1;
	dp[1][0]=1;

	for(int i=1;i<n;i++){
		for(int j=1;j<n;j++){
			if(j<i){
				dp[i][j]=dp[i-1][j-1]+dp[i][j-1];
			}
			else if(i==j){
				dp[i][j]=dp[i-1][j-1]+dp[i][j-1];
				if(i+1!=n)
					dp[i+1][0]=dp[i][j];
			}
			else{
				continue;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<n<<"th Catalan number is :"<<dp[n-1][0]<<endl;
	return 0;
}