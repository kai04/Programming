#include<bits/stdc++.h>
using namespace std;
int knapSack(int W, vector<int> wt, vector<int> val, int n)
{
   int i, w;
   int K[n+1][W+1];
 
   // Build table K[][] in bottom up manner
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }
 
   return K[n][W];
}
int main(){
    int t;
    cin>>t;
    while(t--){
	int W,n;
	cin>>n>>W;
	vector<int> wt(n);
	vector<int> val(n);
	for(int i=0;i<n;i++){
		int x,y,z;
		cin>>x>>y>>z;
		val[i]=x*y;
		wt[i]=z;
	}
	vector<vector<int>> dp(W+1,vector<int>(n+1,0));
	for(int i=0;i<=n;i++){
		dp[0][i]=0;
	} 
	for(int i=1;i<=W;i++){
		for(int j=0;j<n;j++){
			if(i-wt[j]>=0){
				dp[i][j+1]=max((val[j]+dp[i-wt[j]][j]),dp[i][j]);
			}
			else{
				dp[i][j+1]=dp[i][j];
			}
		}
	}
   /* for(int i=0;i<=W;i++){
		for(int j=0;j<=n;j++){
            cout<<dp[i][j]<<" ";            
        }
        cout<<endl;
    }*/
       // cout<<knapSack(W,wt,val,n)<<endl;
	cout<<dp[W][n]<<endl;
    }
	return 0;
}