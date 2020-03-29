#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,s;
int main(){
    cin>>n>>s;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    ll i=0;
    sort(a.begin(), a.end());
    ll op = 0;
    vector<ll>::iterator it=find(a.begin(), a.end(), s);
    if(it==a.end()){
        i=n/2;
        if(a[i]<s){
            while(a[i]<s && i<n){
                op += abs((s - a[i]));
                i++;
            }
        }
        else{
            while(a[i]>s && i>0){
                op+=abs((s - a[i]));
                i--;
            }
        } 
    }
    else{
            i= (distance(a.begin(), it));
            if(i < n/2){
                while(i <= (n/2)){
                    op +=abs(s - a[i]);
                    i++;
                }
            }
            if(i > n/2){
                while(i >= (n/2)){
                    op+=abs((s-a[i]));
                    i--;
                }
            }

    }    

    
    
    cout << op << endl;
    
return 0;
}
