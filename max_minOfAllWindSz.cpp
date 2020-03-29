/*

https://www.geeksforgeeks.org/find-the-maximum-of-minimums-for-every-window-size-in-a-given-array/
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a;
        vector<int> res;
        res.push_back(-1);
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            a.push_back(x);
            dp[i][i]=x;
            res[0]=max(res[0],x);
        }
        
        for(int k=2;k<=n;k++){
            int max1=-1;
            for(int i=0;i<n-1;i++){
                int j=i+k-1;
                if(j<n){
                    dp[i][j]=min(min(dp[i][j-1],a[j]),min(dp[i+1][j],a[i]));
                
                max1=max(max1,dp[i][j]);
                }
            }
            res.push_back(max1);
        }
        for(int i=0;i<n;i++){
            cout<<res[i]<<" ";
        }
        cout<<endl;
    }
	//code
	return 0;
}
