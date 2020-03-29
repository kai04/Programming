#include <bits/stdc++.h>
using namespace std;
typedef int ll;
ll solve(ll i,map<ll,map<ll,ll> > dp,vector<ll> a,ll cursum){
	if(dp[i][cursum]!=0)
		return dp[i][cursum];
	if(i<0)
		return INT_MIN;
	if(cursum==0)
		return 1;
	ll q=a[i]+solve(i,dp,a,cursum+a[i]);
	ll w = solve(i,dp,a,cursum-a[i]);
	ll e = solve(i,dp,a,cursum);
	dp[i][cursum]=max(dp[i][cursum],q);
	dp[i][cursum]=max(dp[i][cursum],w);
	dp[i][cursum]=max(dp[i][cursum],e);
	return dp[i][cursum];
}

int main()
{
	ll n;
	cin>>n;
	vector<ll> v;
	ll sum1=0;
	for (int i = 0; i < n; ++i)
	{	
		ll x;
		cin>>x;
		sum1+=x;
		v.push_back(x);
		/* code */
	}
	map<ll,map<ll,ll> > dp;
	ll ans=0;
	cout<<solve(n-1,dp,v,0)<<endl;

	/* code */
	return 0;
}