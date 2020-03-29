//https://practice.geeksforgeeks.org/problems/stickler-theif/0
//https://www.geeksforgeeks.org/maximum-sum-such-that-no-two-elements-are-adjacent/
#include <bits/stdc++.h>
using namespace std;



int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> a(n);
	    vector<int> dp(n+1,0);
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	   // dp[0]=0;
	    if(a[0]>0)
	        dp[1] = a[0]; 
	    for(int i=2;i<=n;i++){
	        //take a[i]
	        dp[i] = max(dp[i-1],dp[i-2] + a[i-1]);
	        //Do not take a[i]
	    }
	    /*for(auto it:dp){
	        cout<<it<<" ";
	    }*/
	    cout<<dp[n]<<endl;
	   // cout<<endl;
	}
	return 0;
}
