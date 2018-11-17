
/*http://www.geeksforgeeks.org/minimum-steps-reach-target-knight/*/
#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
int n;
int tx,ty;
//queue<pair<int,int>> q;
int dist(int i,int j,vector<vector<int>> &board,vector<vector<int>> &dp){
    if(i==tx && j==ty){
        dp[i][j]=0;
        return 0;
    }
    if(dp[i][j]!=-1)
        return dp[i][j];
        int p,q,r,s,t,u,v,w;
           int ans=INT_MAX/2;
    
    if(board[i][j]!=1){
        board[i][j]=1;
            if(i+2<=n && j+1<=n){
                p=1+dist(i+2,j+1,board,dp);
                ans=min(ans,p);
            }
            if(i+2<=n && j-1>0){
                q=1+dist(i+2,j-1,board,dp);
                ans=min(ans,q);
            }
            if(i+1<=n && j+2<=n){
                r=1+dist(i+1,j+2,board,dp);
                ans=min(ans,r);
            }
            if(i+1<=n && j-2>0){
                s=1+dist(i+1,j-2,board,dp);
                ans=min(ans,s);
            }
           //--------------------//
            if(i-1>0 && j-2>0){
                t=1+dist(i-1,j-2,board,dp);
                ans=min(ans,t);
            }
            if(i-1>0 && j+2<=n){
                u=1+dist(i-1,j+2,board,dp);
                ans=min(ans,u);
            }
            if(i-2>0 && j-1>0){
                v=1+dist(i-2,j-1,board,dp);
                ans=min(ans,v);
            }
            if(i-2>0 && j+1<=n){
                w=1+dist(i-2,j+1,board,dp);
                ans=min(ans,w);
            }
        dp[i][j]=ans;
    
    }
    return ans;
    
}
int main() {
    int t;
    cin>>t;
    while(t--){
        //int n;
        cin>>n;
        //cout<<n<<endl;
        vector<vector<int>> board(n+1,vector<int>(n+1,-1));
        int x,y;
        cin>>x>>y;
        
        cin>>tx>>ty;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        cout<<dist(x,y,board,dp)<<endl;
    }
	//code
	return 0;
}
