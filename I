#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#define mod 1000000007
typedef long long ll;

using namespace std;
/*ll power(ll a,ll b){
    ll res=1;
    ll x;
    if(b==0)
        res=1;
    else if(b==1)
        res=a;
    else{    
    if(b%2==0){
        x=power(a,(b/2));
        res=x*x;
    }
    else{
        x=power(a,(b/2));
        res=a*x*x;
    }
    }
    return res;
}*/
 ll power(ll a, ll b)
    {
    	ll ans = 1;
    	while ( b > 0 ) {
    		if ( b&1 ) ans = (ans*a)%mod;
    		a = (a*a)%mod;
    		b >>= 1;
    	}
    	return ans;
    }
void compute(set<ll> &vec,ll n,ll even,bool z_pres){
    ll res,all_even,end_even,dcount;
    dcount=vec.size();
    if(z_pres==true){
        //cout<<"even:"<<even<<endl;
        //cout<<"dcount:"<<dcount<<endl;
        //cout<<"power(dcount,n-2):"<<power(dcount,n-2)<<endl;
        end_even=even*(dcount-1)*(power(dcount,n-2))%mod;
        all_even=(even-1)*(power(even,n-1))%mod;
            
    }
    else{
        end_even=even*(power(dcount,n-1))%mod;
        all_even=(power(even,n))%mod;
    }
    //cout<<"end_even:"<<end_even<<endl;
    //cout<<"all_even:"<<all_even<<endl;
    res=((end_even)%mod-(all_even)%mod)%mod;
    if ( res < 0 ) res += mod;
    cout<<res<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   ll Q,N;
    
    set<ll> vec;
    string s;
    bool z_pres=false;
    cin>>s;
        cin >>Q;
    while(Q--){
    ll p,even=0;
      cin >>N;
    for(ll i=0;i<s.length();i++){
        p=s[i]-'0';
      
        //vec.push_back(p);
        vec.insert(p);
    }
    for(set<ll>::iterator it=vec.begin();it!=vec.end();it++){
        p=*it; 
        if(p%2==0)
        {
            even++;
            if(p==0)
                z_pres=true;
        }
    }
    //cout<<endl;*/
    //cout<<"z_pres:"<<z_pres<<endl;
    compute(vec,N,even,z_pres);
    vec.clear();
    }
    return 0;
}

