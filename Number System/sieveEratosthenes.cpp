//
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<bool> Prime(ll n){
	vector<bool> isPrime(n+1,true);
	isPrime[0]=isPrime[1]=true;
	for(ll i=2;i<=sqrt(n);i++){
		if(isPrime[i]){
			for(ll j=i*i;j<=n;j=j+i){
				isPrime[j]=false;
			}
		}
	}
	return isPrime;
}

int main(){
	ll n;
	cin>>n;
	vector<ll> res;
	vector<bool> isPrime=Prime(n);
	for(ll i=1;i<isPrime.size();i++){
		if(isPrime[i]){
			res.push_back(i);
		}
	}
	ll cnt=1;
	/*for(ll i=0;i<res.size();i++){
		cout<<res[i]<<" ";
	}*/
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=res.size();j++){
			if(i%res[j]==0){
				int p=0;
				while(i%res[j]==0)
					{i=i/res[j];p++;}
				for(ll k=1;k<=res.size();k++){
					if(k!=j&&i%res[k]==0){
						int q=0;
						while(i%res[k]==0)
						{i=i/res[k];q++;}
						if(i<=n){
							cnt+=((p+1)*(q+1)/2);
							cout<<"("<<res[j]<<"^"<<p<<") * ("<<res[k]<<")"<<endl; 
						}
					}
				}
			}
		}
	}
	//cout<<endl;
	/*set<ll> res1;
	for(ll i=1;i<res.size();i++){
		for(ll k=1;pow(res[i],k)<=n;k++){
			ll term1=pow(res[i],k);
			for(ll j=1;j<res.size();j++){
				if(j!=i && res[j]*term1 <= n){
					res1.insert(term1*res[j]);
					cout<<cnt<<") t1:"<<term1<<" t2:"<<res[j]<<endl;
					cnt++;
				}
			}
		}
	}*/

	cout<<"cnt:"<<cnt<<endl;
	//cout<<res1.size()<<endl;
	return 0;
}