#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int main(){
    cin>>n;
    vector<ll> a(n);
    for(int i = 0;i < n;i++)
        cin >> a[i];
    
    ll max1 = 1, last = a[0], temp_max = 1;
    ll i=0,j=1;
    while(i<=j&&j<n){
        //cout<<"i:"<<i<<" j:"<<j<<" max:"<<max1<<endl;
        if(a[j]<=2*a[j-1]){
            j++;
            max1=max(max1,(j-i));
            temp_max++;
        }
        else{
            max1=max(max1,(j-i));
            i=j;
            j++;
        }
        
        //cout<<"i:"<<i<<" max:"<<temp_max<<" last:"<<last<<endl;
    }
    cout<<max1<<endl;
    
return 0;
}
