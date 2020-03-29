//https://www.interviewbit.com/problems/max-distance/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int maximumGap(const vector<int> &A) {
    int n=A.size(),ans=-1;
 if(n==1)
    return 0;
    vector<int> lmin(n,INT_MAX);
    vector<int> rmax(n,INT_MIN);
    lmin[0] = 0;
    rmax[n-1] = n-1;
    for(int i=1;i<n;i++){
        lmin[i] = min(lmin[i-1],A[i]);
    }
    for(int i=n-2;i>=0;i--){
       rmax[i] = max(rmax[i+1],A[i]);
    }
    int i=0,j=n-1;
    while(i<n && j<n && i<j){
        if(lmin[i]>=rmax[j]){
            i++;
        }
        else{
            ans = max(ans,j-i);
            j--;
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans = maximumGap(a);
    cout<<"ANS:"<<ans<<endl;
    return 0;
}