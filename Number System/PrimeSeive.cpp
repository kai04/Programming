//http://codeforces.com/contest/26/problem/A
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void linearSeive(){
	const ll N = 100000000;
	//lp[i] hold lowest prime factor for no i eg for 10 it is 2 and for 15 it is 3 etc
	vector<ll> lp(N+1,0);
	//pr hold lowest prime no's
	vector<ll> pr;

	for (ll i=2; i<=N; ++i) {
    	if (lp[i] == 0) {
        	lp[i] = i;
        	pr.push_back (i);
    	}
    	// for all pr[j](prime) less then lowest prime of no i, update lowest prime for all no i*pr[j]  
    	for (int j=0; j<(ll)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
        	lp[i * pr[j]] = pr[j];
	}
}

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