//https://www.spoj.com/problems/TDPRIMES/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ll n;
	cin>>n;
	vector<ll> a;
	for(ll i=0;i<n;i++){
		ll x;
		cin>>x;
		a.push_back(x);
	}
	ll res=INT_MAX;
	for(ll x=1;x<=n;x++){
		ll temp=0;
		for(ll i=1;i<=n;i++){
			temp+=2*a[i-1]*(abs(x-i)+abs(i-1)+abs(x-1));
		}
		// cout<<"floor:"<<x<<" temp:"<<temp<<endl;
		res=min(res,temp);
	}
	cout<<res<<endl;


	return 0;
}

