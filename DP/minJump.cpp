//https://www.geeksforgeeks.org/minimum-number-of-jumps-to-reach-end-of-a-given-array/
//https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps/0
//https://www.interviewbit.com/problems/min-jumps-array/
#include <bits/stdc++.h>
using namespace std;


int Solution::jump(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n=A.size();
    if(n==1) return 0;
    int max_reach=A[0],step=A[0],jump=1;
    for(int i=1;i<n-1;i++){
        max_reach=max(max_reach,i+A[i]);
        step--;
        if(step<0) return -1;
        if(step==0){
         jump++;
         step=max_reach-i; 
        }
    }
    if(max_reach>=n-1) return jump;
    return -1;
}

int minJumpsTopDown(vector<int> arr, int l, int h,vector<int> &dp) 
{ 
      
// Base case: when source and  
// destination are same 
if (h == l) 
    return 0; 
  
// When nothing is reachable from  
// the given source 
if (arr[l] == 0) 
    return INT_MAX/2; 
  
  if(dp[l]!=INT_MAX/2){
        // cout<<"h3"<<endl;
        return dp[l];
    }
// Traverse through all the points  
// reachable from arr[l]. Recursively  
// get the minimum number of jumps  
// needed to reach arr[h] from these 
// reachable points. 
    // cout<<"i:"<<l<<endl;
int min = INT_MAX; 
for (int i = l + 1; i <= h && 
         i <= l + arr[l]; i++) 
{ 
    int jumps = minJumpsTopDown(arr, i, h,dp); 
    if(jumps != INT_MAX && jumps + 1 < min) 
        min = jumps + 1; 
} 
  dp[l] = min;
return min; 
}

int minJump(vector<int> a,vector<int> &dp,int n){
    //already at the end
        dp[n-1] = 0;
    for(int i=n-2;i>=0;i--){
        // element is 0 then not possible to reach end
        if(a[i]==0)
            dp[i]=INT_MAX/2;
        //only one step is required in below case
        else if(a[i]+i>=n-1){
            dp[i]=1;
        }
        else{
            int min1 = INT_MAX;
            for(int j=i+1;j<n-1 && j<=a[i]+i;j++){            
                min1 = min(min1,dp[j]+1); 
            }
            dp[i] = min1;
        }
    }
   return dp[0]; 
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        vector<int> dp(n,INT_MAX/2);
        for(int i=0;i<n;i++){
            cin>>a[i];
            
        }
        //int ans = minJumpsTopDown(a,0,n-1,dp);
        int ans = minJump(a,dp,n);
        if(ans>=INT_MAX/2)
            cout<<-1<<endl;
        else
            cout<<ans<<endl;
    }
    //code
    return 0;
}
