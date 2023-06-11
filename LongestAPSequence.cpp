#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &a){
int n = a.size();
vector<int> dp(n);
dp[n-1] = 1;
for(int j = n-2;j>=0;j--){
	int i = j-1;
	int k = j+1;
	while(i>0 || k<n){
		if(a[i]+a[k]==(2*a[j])){
			dp[j] = max(dp[j],dp[k]+1);
			i--;
			k++;
		} else if(a[i]+a[k]<(2*a[j])){
			k++;
		} else{
			i--;
		}
	}
}
for(auto it:dp)
	cout<<it<<" ";
cout<<endl;
}
int main(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	solve(a);
	return 0;
}
