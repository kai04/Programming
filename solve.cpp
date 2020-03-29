#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
map<ll, ll> dp;
map<ll, bool> flag;
ll calc(ll tmp_target,ll x){
	ll p=0;
	while(tmp_target>=x){
		p++;
		tmp_target/=x;
	}
	if(x==1)
		return p;
	return p+1;
}
ll solve(ll target,ll x){
	if(flag[target])
		return (INT_MAX/2);
	// cout<<"target:"<<target<<endl;
	if(target == x)
		{	dp[target] = 0;
			return 0;
		}
	if(target<0)
		return INT_MAX;
	if(target==0 || target ==1)
		{dp[target]=target;
		return target;}
	if(dp.find(target) != dp.end())
		{
			cout<<"target:"<<target<<" dp[target]:"<<dp[target]<<endl;
			return dp[target];
			}
	// dp[target] = INT_MAX;
	flag[target]=true;
	ll m = calc(target,x);
	ll l=0;
		l=pow(x,m);
		cout<<"target:"<<target<<" calling "<< pow(x,m)<<" "<<(pow(x,m)-target)<<" "<< (target - x)<<" "<<( x-target)<<endl;
	ll q = 1 + solve(pow(x,m),x) + solve((pow(x,m)-target),x);
	dp[target]=min(dp[target],q);
	// cout<<" calling "<< pow(x,m-1)<<" "<<(target - pow(x,m-1))<<endl;
	ll r = 1 + solve(pow(x,m-1),x) + solve((target - pow(x,m-1)),x);
	dp[target]=min(dp[target],r);

	if(target>x)
		{
			ll s = 1 + solve((target - x),x);
			dp[target]=min(dp[target],s);
		}
		else{
			ll t = 1 + + solve((x-target),x);
			dp[target]=min(dp[target],t);	
		}
	cout<<"target:"<<target<<" dp[target]:"<<dp[target]<<endl;
	return dp[target];


}

int main(){
	ll x,target;
	cin>>x>>target;
	ll p= calc(target,x);
	ll q= pow(x,p);

	// cout<<"q:"<<q<<endl;
	// vector<ll> dp(q,INT_MAX/2);
	// vector<bool> flag(q,false);
	for(ll i=1;i<=p;i++){
		dp[pow(x,i)]= i-1;
	}
	for(ll i=1;i<(target)/x;i++){
		dp[x*i]= i-1;
	}
	cout<<solve(target,x)<<endl;	
	return 0;
}
