#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <climits>
typedef long long ll;
using namespace std;

void primesieve(ll n){
    ll q=sqrt(n);
    //q=n;
    vector<ll> a(n+1);
    vector<ll> primes(0);
    map<ll,ll> factors;
    vector<bool> touched(n+1,false);
    for(int i=1;i<n;i++)
    {
        a[i]=i;
    }
    vector< map<ll,ll> > pf(n+1);
    for(int i=2;i<q;i++){
        if(!touched[i]){
            primes.push_back(i);
            touched[i]=true;
            //factors[i]=i;
            pf[i][i]=1;
        }
        for(int j=2*i;j<n;j=j+i){
            touched[j]=true;
            while(a[j]%i==0){
                //if(factors.find(i)!=factors.end()){
                if(pf[j].find(i)!=pf[j].end()){
                    pf[j][i]+=1;
                    //factors[i]+=1;
                }
                else{
                    pf[j][i]=1;
                    //factors[i]=1
                }
                a[j]=a[j]/i;
            }
        }
    }
    for(int k=q;k<n;k++){
        if(!touched[k])
            primes.push_back(k);
    }
    for(auto it:primes){
        cout<<it<<" ";
    }
    cout<<endl;
    cout<<"prime factor of 54:"<<endl;
    for(auto it:pf[54]){
        cout<<it.first<<" "<<it.second<<endl;
    }
        cout<<endl;

}

int main() {
    ll n;
    cin>>n;
    primesieve(n);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
