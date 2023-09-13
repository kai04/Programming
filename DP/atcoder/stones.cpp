//https://atcoder.jp/contests/dp/tasks/dp_k
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
  	int n,k;
  	cin>>n>>k;
  	vector<int> A(n);
  	for(int i=0;i<n;i++){
  		cin>>A[i];
  	}
  	vector<bool> dp(k+1, false);
  	for(int i=1;i<=k;i++){
  		for(int j=0;j<n;j++){
  			int x = i-A[j];
  			if(x>=0){
  				dp[i] = dp[i] || !dp[x];	
  			}
  		}
  	}
  	if(dp[k]){
  		cout<<"First"<<endl;
  	} else{
  		cout<<"Second"<<endl;
  	}

    return 0;
}
