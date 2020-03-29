//https://www.geeksforgeeks.org/buy-maximum-stocks-stocks-can-bought-th-day/
//https://www.hackerrank.com/contests/gs-codesprint/challenges/buy-maximum-stocks/submissions/code/1308081285
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool comp(pair<ll,ll> p1,pair<ll,ll> p2){
    if(p1.first<p2.first){
        return true;
    }
    else if(p1.first==p2.first && p1.second<p2.second){
        return true;
    }
    else
        return false; 
}
int main() {
    ll n;
    cin>>n;
    vector<pair<ll,ll>> a;
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        a.push_back(make_pair(x,i+1));
    }
    ll k;
    cin>>k;
    sort(a.begin(),a.end(),comp);
    /*for(auto it:a){
        cout<<"("<<it.first<<","<<it.second<<")"<<" ";
        
    }
    cout<<endl;*/
    ll max1=0;
    for(ll j=0;j<n;j++){
        ll L=a[j].second;
        ll C=a[j].first;
        ll P=min(L,(k/C));
        k=k-P*C;
        max1=max1+P;
    }
    cout<<max1<<endl;
        
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

