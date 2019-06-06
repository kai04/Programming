#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    int n = s.length();
	    vector<vector<int>> dp(n+1,vector<int> (n+1,0));
	    //length 1
	    for(int i=0;i<n;i++){
	        dp[i][i] = 1;
	    }
	    //length 2
	    int p = 0,q=0;
	    for(int i=1;i<n;i++){
	        if(s[i]==s[i-1]){
	            dp[i-1][i] = 1;
	            p=i-1;
	            q = i;
	        }
	    }
	    for(int l=3;l<=n;l++){
	    	for(int i=0;i<n;i++){
	            int j = i+l-1;
	            if(j<n && i>=0){
	                if(s[i]==s[j]&&dp[i+1][j-1]==1){
	                    dp[i][j]=1;
	                    if(j-i+1>q-p+1){
	                        p=i;
	                        q=j;
	                    }
	                }
	            }
	        }
	    }
	    /*for(int i=0;i<n;i++){
	    	for(int j=0;j<n;j++){
	    		cout<<dp[i][j]<<" ";
	    	}
	    	cout<<endl;
	    }*/
	     for(int i=p;i<=q;i++){
	         cout<<s[i];
	     }
	     cout<<endl;
	    
	}
	return 0;
}