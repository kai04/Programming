//https://www.codechef.com/problems/FLOW016
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){
	if(b==0)
	{
		return a;
	}
	else{
		return gcd(b,a%b);
	}

}
int main(){
	ll t;
	cin>>t;
		while(t--){
			ll a,b;
			cin>>a>>b;
			ll res_gcd=0,res_lcm=0;
			if(a>=b){
				res_gcd=gcd(a,b);
			}
			else{
				res_gcd=gcd(b,a);
			}
			res_lcm=(a/res_gcd)*b;
			cout<<res_gcd<<" "<<res_lcm<<endl;
		}
	return 0;
}
