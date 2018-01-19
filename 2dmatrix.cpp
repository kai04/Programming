//http://www.geeksforgeeks.org/dynamic-programming-set-27-max-sum-rectangle-in-a-2d-matrix/
#include <bits/stdc++.h>
using namespace std;
int ro,co;
int max_sum(int p,int q,int r,int s,vector<vector<int>> sum){
    int maxsum=INT_MIN/2;
        maxsum=max(maxsum,sum[p][q]);
         for(int i=p;i<=r;i++){
            for(int j=q+1;j<=s;j++){
                sum[i][j]+=sum[i][j-1];
                maxsum=max(maxsum,sum[i][j]);
            }
         }
        
        for(int j=q;j<=s;j++){
            for(int i=p+1;i<=r;i++){
                sum[i][j]+=sum[i-1][j];
                maxsum=max(maxsum,sum[i][j]);
            }
         }
    return maxsum;
}
//int max2dsum(int p,int q,int r,int s,vector<vector<int>> sum,vector<vector<vector<vector<int>>>> &dp){
    
//}
int main() {
    int t;
    cin>>t;
    while(t--){
        cin>>ro>>co;
        vector<vector<int>> a(ro,vector<int>(co));
        vector<vector<int>> sum(ro,vector<int>(co,0));
        vector<vector<vector<vector<int>>>> dp(ro,vector<vector<vector<int>>>(co,vector<vector<int>>(ro,vector<int>(co,-1))));
        for(int i=0;i<ro;i++){
            for(int j=0;j<co;j++){
                cin>>a[i][j];
                sum[i][j]=a[i][j];
            }
        }
        int maxsum = INT_MIN/2;
        for(int i=0;i<ro;i++){
            for(int j=0;j<co;j++){
                for(int k=0;k<ro;k++){
                    for(int l=0;l<co;l++){
                        if(k>=i && l>=j)
                        {
                            maxsum= max(maxsum,max_sum(i,j,k,l,sum));
                        }
                    }
                }
            }
        }
        cout<<maxsum<<endl;
    }
        
    //code
    return 0;
}