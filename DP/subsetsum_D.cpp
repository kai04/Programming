#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void display(vector<int> p){
    for(int i=0;i<p.size();i++){
        cout<<p[i]<<" ";
    }
    cout<<endl;
}

void printSubset(vector <int> &myset,vector<vector<bool> > &dp,int sum1,vector <int> p,int i){
    if(i==0){
        //if(dp[i][sum1])
        //    p.push_back(myset[i]);
        display(p);
        return;
    }
    if(dp[i-1][sum1]){
        vector<int> b(0);
        printSubset(myset,dp,sum1,b,i-1);
        return;
    }
    if((sum1-myset[i])>=0 && dp[i-1][sum1-myset[i]]){
        p.push_back(myset[i]);
        printSubset(myset,dp,sum1-myset[i],p,i-1);
        return;
        
    }
}

bool subsetsum(vector <int> &myset,int sum1){
    int n=myset.size();
    //bool dp[n][sum1+1];
    vector<vector<bool> > dp(n);
    for(int i=0;i<n;i++){
        dp[i].resize(sum1+1);
    }
    //initialize
    //Empty subset sum cannot have sum greater than 1 
    for(int i=0;i<=sum1;i++){
        dp[0][i]=false;
    }
    //all 0 size subset has sum=0
    for(int i=0;i<n;i++){
        dp[i][0]=true;
    }

    //compute
    for(int i=1;i<n;i++){
        int t =myset[i];
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
    
    if(dp[n-1][sum1]){
    vector<int> p(0);
    printSubset(myset,dp,sum1,p,n-1);
    }
    else{
        cout<<"No such subset with given sum"<<endl;
    }
    
    return dp[n-1][sum1];
}
int main() {
    int n,sum1;
    cin>>n>>sum1;
    vector <int> a(n+1,0);
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a[i]=x;
    }
    cout<<subsetsum(a,sum1)<<endl;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
