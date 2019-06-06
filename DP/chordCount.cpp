#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 10e9+7;
int chordCnt(int A) {
    vector<ll> dp(A+1,0);
    dp[0] = 1;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=A;i++){
        for(int j=0;j<i;j++){
            dp[i] += (dp[i-1-j] * dp[j]) % mod;
            cout<<"i:"<<i<<" j:"<<j<<" dp[i]:"<<dp[i]<<endl; 
        }
    }
    return dp[A];
    }

int main(){
    int n;
    cin>>n;
    int x  = chordCnt(n);
    cout<<"RES:"<<x<<endl;
}
