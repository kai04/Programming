//https://atcoder.jp/contests/abc215/tasks/abc215_d
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX_VAL 1e5+5

// precompute all prime no's
vector<ll> spf;
void precompute(){
    spf.resize(MAX_VAL,0);
    spf[1] = 1; 
    for(ll i = 2; i<MAX_VAL; i++){
        if(spf[i]!=0)
            continue;
        for(ll j = i * i; j< MAX_VAL;j = j + i){
            if(spf[j]==0) spf[j] = i;
        }
    }
}

vector<int> factorize(int x){
    vector<int> factor;
    while(x>1){
        if(spf[x]!=0 && (x % spf[x]) ==0){
            factor.push_back(spf[x]);
            x = x / spf[x];
            
        }
    }
    return factor;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute();
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    vector<int>cnt(MAX_VAL,0) ;
    for(int i = 0 ;i<n;i++){
        cin>>a[i];
        for(auto &factor: factorize(a[i])){
            // cout<<"Number:"<<a[i]<<" Factor:"<<factor<<endl;
            cnt[factor]++;
        }
    }
    vector<int> ans;
    for(int i =1;i<=m;i++){
        bool valid = true;
        for(auto &factor:factorize(i)){
            // cout<<"Num:"<<i<<" Factor:"<<factor<<endl;
            if(cnt[factor]>0) valid = false;
        }
        if(valid)
            ans.push_back(i);            
    }
    cout<<ans.size()<<endl;
    for(auto it:ans)
        cout<<it<<endl;
    return 0;
}