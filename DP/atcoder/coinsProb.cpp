//https://atcoder.jp/contests/dp/tasks/dp_i
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin>>n;
    vector<float> p(n);
    for(int i=0;i<n;i++){
		cin>>p[i];
	}
	vector<vector<float>> dp(n+1,vector<float>(n+1,0.0f));
	dp[0][0] = 1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=i;j++){
			if(j==0){
				dp[i][j] = (float ) dp[i-1][j] * (1-p[i-1]);
			}
			else{
				dp[i][j] = (float ) dp[i-1][j-1]*p[i-1] + dp[i-1][j]*(1-p[i-1]);
			}
		}
	}
	double answer = 0.0f;
	for(int cnt=(n/2)+1;cnt<=n;cnt++){
		answer += dp[n][cnt]; 
	}
	//std::cout << std::fixed;
	//std::setprecision(10);
	cout<<setprecision(10)<<answer<<endl;
    return 0;
}
