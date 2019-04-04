//https://www.spoj.com/problems/TDPRIMES/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Sieve(ll N){
	//const int N = 10000000;
vector<ll> lp(N+1,0);
vector<int> pr;

for (int i=2; i<=N; ++i) {
    if (lp[i] == 0) {
        lp[i] = i;
        pr.push_back (i);
    }
    for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
        lp[i * pr[j]] = pr[j];
}
for(auto it:lp)
	cout<<it<<" ";
cout<<endl;
}

int main(){
	ll n=50;
	Sieve(n);
	return 0;

}