//https://atcoder.jp/contests/dp/tasks/dp_a
#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    std::vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    std::vector<int> dp(n,0);
    dp[1] = abs(a[1] - a[0]);
    for(int i=2;i<n;i++){
        dp[i] = min((dp[i-1]+abs(a[i] - a[i-1])),(dp[i-2]+abs(a[i] - a[i-2])));
    }
    cout<<dp[n-1]<<endl;
    return 0;
}
