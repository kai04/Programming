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
#include <iostream>
#include <algorithm>
#include <unordered_map>
typedef long long ll;
using namespace std;
ll dp[100001][101];
ll rec(vector<ll> &B,ll i,ll j,ll n){
    if(i>n)
        return 0;
    if(dp[i][j]==-1){
    //ll r=rec(B,i+1,1,n)+abs(j-1);
    //ll s=rec(B,i+1,B[i],n)+abs(j-B[i]);
    //dp[i+1][1]=rec(B,i+1,1,n)+abs(j-1);
    //dp[i+1][B[i]]=rec(B,i+1,B[i],n)+abs(j-B[i]);
        
        if(i==1){
                dp[i+1][1]=rec(B,i+1,1,n);
                dp[i+1][B[i]]=rec(B,i+1,B[i],n);
                
        }
        else{
         dp[i+1][1]=rec(B,i+1,1,n)+abs(j-1);
        dp[i+1][B[i]]=rec(B,i+1,B[i],n)+abs(j-B[i]);
        //dp[i][j]=max(dp[i+1][1],dp[i+1][B[i]]);    
        }
        dp[i][j]=max(dp[i+1][1],dp[i+1][B[i]]);
        
    }
    cout<<"i:"<<i<<" j:"<<j<<" dp:"<<dp[i][j]<<endl;
    /*if(i==1)
    {   cout<<"hwll"<<endl;
        return max(dp[2][1],dp[2][B[1]]);
    }*/
    return (dp[i][j]);
    
}
int main() {
    ll n,T,x;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    //cin>>T;
    //while(T--){
    cin>>n;
    vector<ll> B(n+1);
    for(int i=1;i<=n;i++){
        cin>>x;
        B[i]=x;
    }
    for(int j=0;j<n+2;j++){
        for(int k=0;k<101;k++){
            dp[j][k]=-1;
    }
    }
    cout<<rec(B,1,0,n)<<endl;
    /*cout<<"Showing:"<<endl;
    for(int j=0;j<n+2;j++){
        for(int k=0;k<101;k++){
            cout<<dp[j][k]<<endl;
    }
    }*/
    //}
    return 0;
}
