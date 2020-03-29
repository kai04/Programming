#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll rec(vector<ll> a){
    ll maxi=0;
    if(a.size()==0)
        return 0;
    if(a.size()==1)
        return *(a.begin());
    //cout<<"size:"<<a.size()<<endl;
    ll n=a.size();
    for(ll i=0;i<n;i++){
        vector<ll> arr;
        for(ll j=i+1;j<n;j++){
        if(a[j]!=a[i]+1 && a[j]!=a[i]-1){
            arr.push_back(a[j]);
        }
            //cout<<"size1:"<<a.size()<<" size2:"<<arr.size()<<endl;
            
        }
        maxi=max(maxi,a[i]+rec(arr));
           /* cout<<"k:"<<a[i]<<endl;
            for(auto it:arr)
                cout<<it<<" ";
            cout<<endl;
            cout<<"--------------------"<<endl;*/
        
    }
    return maxi;
}

int main() {
    ll n;
    cin>>n;
    vector<ll> a;
    while(n--)
    {
        ll x;
        cin>>x;
     a.push_back(x);
    }
    sort(a.begin(),a.end());
   /* cout<<"iniially:"<<endl;
     for(auto it:a)
                cout<<it<<" ";
            cout<<endl;*/
    cout<<rec(a)<<endl;
    
        return 0;
}