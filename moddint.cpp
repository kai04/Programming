#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ll t;
    cin>>t;
    while(t--){
    ll n,m;
    cin >> n>>m;
    //vector<ll> a(n);
        string a;
        cin>>a;
    vector<ll> even(n,0);
    vector<ll> odd;
    for(ll i=0;i<n;i++){
        //cin>>a[i];
        if(i==0){
            if(a[i]=='0')
                even[i]=1;
            else{
                odd.push_back(i);
                even[i]=0;
            }
        }
        else{
        if(a[i]=='0')
            even[i]=even[i-1]+1;
        else{
            odd.push_back(i);
            even[i]=even[i-1];
        }
        }
    }
    ll res=0;
        /*cout<<"odd array:"<<endl;
        for(ll i=0;i<odd.size();i++){
            cout<<odd[i]<<" ";
        }
        cout<<endl<<"================"<<endl;
        cout<<"even array:"<<endl;
        for(ll i=0;i<even.size();i++){
            cout<<even[i]<<" ";
        }
        cout<<endl<<"================"<<endl;*/
    for(ll i=0;i+m-1<odd.size();i++){
        ll j=i+m-1;
        ll x,y;
        if(i-1<0)
            x=even[odd[i]-1];
            //x=0;
        else
            x=even[odd[i]-1]-even[odd[i-1]];
        if(j+1>=odd.size())
            y=even[n-1]-even[odd[odd.size()-1]];
        else{
            y=even[odd[j+1]-1]-even[odd[j]];
            //cout<<"even[odd[j+1]-1]:"<<even[odd[j+1]-1]<<" even[odd[j]]:"<<even[odd[j]]<<endl;
        }
        
            
        //cout<<"i:"<<i<<" j:"<<j<<" indexi:"<<odd[i]<<" indexj:"<<odd[j]<<" x:"<<x<<" y:"<<y<<endl;
        if(x>0 && y>0)
            res+=(x+1)*(y+1);
        else if(x==0)
            res+=(y+1);
        else
            res+=(x+1);
    }
    cout<<res<<endl;
    }
    return 0;
}
