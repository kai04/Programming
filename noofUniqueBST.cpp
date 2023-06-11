#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<vector<ll>> dp;
ll calculateNCR(int n, int r){
     //initialize
   for(int i=0;i<=n;i++){
        dp[0][i]=1;
        dp[i][0]=1;
   }
   dp[0][0] = 0;
   for(int i=1;i<=n;i++){
       for(int j=1;j<=i;j++){
        dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
    } 
}
return dp[n][r];
}

int numTrees(int A) {
    if(A<=1)
        return A;
    dp.resize((2*A)+1,vector<ll>((2*A)+1,0));
    ll b = calculateNCR((2*A),A);
    cout<<"NCR:"<<b<<endl;
    return (b/(A+1));
}

int main(){
    int x;
    cin>>x;
    int ans = numTrees(x);
    cout<<"ANS:"<<ans<<endl;
    return 0;
}
