#include<bits/stdc++.h>
using namespace std;

bool subsetsum(vector <int> &myset,int sum1){
    int n=myset.size();
    //bool dp[n][sum1+1];
    vector<vector<bool> > dp(n+1);
    for(int i=0;i<=n;i++){
        dp[i].resize(sum1+1);
    }
    //initialize
    //Empty subset sum cannot have sum greater than 1 
    for(int i=0;i<=sum1;i++){
        dp[0][i]=false;
    }
    //all 0 size subset has sum=0
    for(int i=0;i<=n;i++){
        dp[i][0]=true;
    }

    //compute
    for(int i=1;i<=n;i++){
        int t = myset[i-1];
        for(int j=1;j<=sum1;j++){
            if(j-t>=0){
                dp[i][j]=dp[i-1][j] || dp[i-1][j-t]; 
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    /*cout<<"showing:"<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<=sum1;j++){
            cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
    cout<<endl<<"========================================="<<endl;*/

    
    return dp[n-1][sum1];
}

int main(){
	int n,sum1;
    cin>>n>>sum1;
    vector <int> a(n+1,0);
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a[i]=x;
    }
    cout<<subsetsum(a,sum1)<<endl;
	return 0;
}