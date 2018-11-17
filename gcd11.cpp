#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
void divisor(ll n){
    for(ll i=1;i<=sqrt(n)+1;i++){
        if(n%i==0)
        {
            if(n/i==i)
                cout<<i<<" ";
            else{
            cout<<i<<" "<<n/i<<" ";
            //divisor(n/i);
            }
        }
    }
    
    
}
static ll gcd(ll a, ll b){
    a = abs(a); b = abs(b);
    return (b==0) ? a : gcd(b, a%b);
  }
int main() {
    /*ll n;
    cin>>n;
    ll a[n];
    ll b[n];
    ll x=0,y=0;
    for(ll i=0;i<n;i++){
    cin>>a[i];
    }
     for(ll i=0;i<n;i++){
    cin>>b[i];
    }
    ll max1=0;
    ll sum1=0;
     for(ll i=0;i<n;i++){
         ll first =a[i];
        for(ll j=0;j<n;j++){
        ll second =b[j];
            ll p=gcd(first,second);
            if(p>=max1){
                
                if(p==max1){
                    if(sum1<(first+second)){
                        max1=p;
                        x=first;
                        y=second;
                        sum1=x+y;
                    }
                    }
                else{
                    max1=p;
                    x=first;
                    y=second;
                    sum1=x+y; 
                }
            }
            //max1=max(max1,p);
        } 
     }
    cout<<sum1<<endl;*/
    ll a,b;
    cin>>a;
    divisor(a);
    
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
