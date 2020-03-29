#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void linearSeive(vector<ll> &lp,vector<ll> &nonAffraid){
	ll n =pow(10,6);
	lp.resize(n+1,0);
	nonAffraid.resize(n+1,0);
	vector<ll> pr;
	ll cnt=0;
	for(ll i=2;i<=n;i++){
		if(lp[i]==0){
			lp[i]=i;
			pr.push_back(i);
			ll k=i;
			while(k%10!=0 && k>0){
				k=k/10;
			}
		}
		for(ll j=0;j<pr.size()&&pr[j]<=lp[i]&&(i*pr[j])<=n;j++){
			lp[i*pr[j]]=pr[j];
		}
	}

}

int main(){
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;

	}
	return 0;
}