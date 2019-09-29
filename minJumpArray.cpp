#include<bits/stdc++.h>
using namespace std;
//https://www.youtube.com/watch?v=vBdo7wtwlXs
/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Example :
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

If it is not possible to reach the end index, return -1.

*/

int jump(vector<int> &A) {
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
        cout<<"i:"<<i<<" A[i]:"<<A[i]<<" max_reach:"<<max_reach<<" step:"<<step<<" jump:"<<jump<<" step=max_reach-i:"<<(max_reach-i)<<endl;
    }
    if(max_reach>=n-1) return jump;
    return -1;
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans = jump(a);
    cout<<"ans:"<<ans<<endl;
    return 0;
}