#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll q,n,m,k;
int main(){
    cin>>q;
    while(q--){
        ll ans=0;
        cin>>n>>m>>k;
        ll a=max(n,m);
        if(a>k){
            ans=-1;
            //cout<<-1<<endl;
        }
        else{
            ans+=a;
            ll b = k-a;
            if(b%2==0){
                ans+=b;
            }
            else{
                if(b==1){
                    ans-=1;
                }
                else{
                    ans+=(b-1);    
                }
                
            }
        }
        cout<<ans<<endl;
    }


return 0;
}
