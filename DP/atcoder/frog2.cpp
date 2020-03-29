//https://atcoder.jp/contests/dp/tasks/dp_b
#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,k;
    cin>>n>>k;
    std::vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    std::vector<int> dp(n+1,INT_MAX/2);
    dp[0] = 0;

    // for(int i=1;i<k;i++){
    //     for(int j=i-1;j>=0;j--){
    //         dp[i] = min(dp[i],abs(a[i]-a[j])+dp[j]);
    //     }
    // }
    //dp[1] = abs(a[1] - a[0]);
    for(int i=1;i<n;i++){
        for(int j=i-1;j>=i-k;j--){
            if(j>=0)
                dp[i] = min(dp[i],abs(a[i]-a[j])+dp[j]);   
        }
    }
    cout<<dp[n-1]<<endl;
    //cin.get();
    return 0;
}
