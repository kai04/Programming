//https://codeforces.com/contest/1084/problem/C
//The Fair Nut and String
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9 + 7;
int main(){
	string stemp;
	cin>>stemp;
	int n=stemp.length();
	string s="";
	int lastb_ix=-1;
	//preprocess remove all unnecessary char from string and leading b's
	int j=0;
	while(j<stemp.length()){
		if(j==0 && stemp[j]!='a'){
			while(stemp[j]!='a' && j<n){
				j++;
			}
		}
		if(stemp[j]=='a' || stemp[j]=='b'){
			s+=stemp[j];
		}
		j++;
		// cout<<"j:"<<j<<" s:"<<s<<" stemp len:"<<n<<endl;
	}
	n=s.length();
	// cout<<"len:"<<s.length()<<" s:"<<s<<endl;
	if(n==0){
		cout<<0<<endl;
		return 0;
	}
	vector<int> dp(n);
	dp[0]=1;
	bool flag=false;
	for(int i=1;i<n;i++){
		if(s[i]=='b'){
			flag=true;
			dp[i]=dp[i-1];
			lastb_ix=i;
		}
		else if(s[i]=='a'){
			if(lastb_ix!=-1)
				dp[i]=((dp[i-1]+mod+dp[lastb_ix])%mod)+1;
			else
				dp[i]=dp[i-1]+1;
			flag=false;
		}
	}
	/*for(auto it:dp)
		cout<<it<<" ";
	cout<<endl;*/
	cout<<dp[n-1]<<endl;
	return 0;
}