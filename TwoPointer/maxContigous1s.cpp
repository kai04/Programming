//https://www.interviewbit.com/problems/max-continuous-series-of-1s/
#include<bits/stdc++.h>
using namespace std;


vector<int> maxone(vector<int> &A, int B) {
    int n = A.size();
    vector<int> ret;
    pair<int,int> ans;
    int i=0,j=1;
    int t = B;
    vector<int> dp(n,0);
    if(A[0]==0){
        dp[0] = 1;
    }
    for(int i=1;i<n;i++){
        if(A[i]==0){
           dp[i] = dp[i-1] + 1;
        } else{
            dp[i] = dp[i-1];
        }
    }
    while(i<n && j<n){
        int cnt0=0;
        if(i==0){
            cnt0 = dp[j];
        } else {
            cnt0 = dp[j]- dp[i-1];
        }
        // cout<<"i:"<<i<<" j:"<<j<<" cnt 0:"<<cnt0;
        if(cnt0<=B){
            int d = j-i;
            if(d>(ans.second-ans.first)){
                ans.first = i;
                ans.second = j;
            }
            j++;
        } else{
            i++;
        }
        // cout<<" ans:["<<ans.first<<","<<ans.second<<"]"<<endl;
        if(i>j){
            j = i+1;
        }
    }
    
    for(int i=ans.first;i<=ans.second;i++){
        ret.push_back(i);
    }
    return ret;
}



int main(){
    int n,B;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>B;
    vector<int> res = maxone(a,B);
    cout<<"Printing Result...."<<endl;
    for(int x: res){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}