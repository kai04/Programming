#include <bits/stdc++.h>
#include <bitset>
using namespace std;
typedef long long ll;
vector<ll>dp(100001,0);

ll compute(ll N,vector<ll>A){
   
    return dp[N];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,T,x,K;
    cin>>T;
    while(T--){
      cin>>N;
    cin>>K;
    bitset<8> foo[N];
    bitset<8> res;
    int count=0;
    for(int i=0;i<K;i++)
        res.set(i,1);
    int len[N];
    for(int i=0;i<N;i++){
        cin>>len[i];
        
        
        for(int j=0;j<len[i];j++){
            cin>>x;
            foo[i].set(x-1,1);
            //foo[i].flip();
        }
        count=0;
        //bitset<4> foo1;
      
        //foo1.set(2,1);
        //foo1.set(1,1);
        //cout<<foo[i]<<endl;
    
        
    }
      //  cout<<"------------------"<<endl;
          for(int j=0;j<N;j++){
            for(int k=j+1;k<N;k++){
               // cout<<(foo[k]|foo[j])<<endl;
                if((foo[k]|foo[j])==res){
                    count++;
                }
            }
        }
    cout<<count<<endl;
    //cout<<"res:"<<res<<endl;
   

    }
    return 0;
}


