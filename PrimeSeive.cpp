//http://codeforces.com/contest/26/problem/A
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> Prime(ll n){
	vector<ll> isPrime(n+1,0);
	ll cnt=0;
	isPrime[0]=isPrime[1]=1;
	for(ll i=2;i<=n;i++){
		if(isPrime[i]==0){
			//cout<<"i:"<<i<<endl;
			for(ll j=i;j<=n;j=j+i){
				isPrime[j]++;
			}
		}
	}
	return isPrime;
}

int main(){
	ll n;
	cin>>n;
	ll cnt=0;
	vector<ll> res=Prime(n);
	for(int i=0;i<res.size();i++){
		if(res[i]==2){
			cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}