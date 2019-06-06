//https://www.interviewbit.com/problems/painters-partition-problem/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll; 
ll no_of_painters(vector<int> &a,ll maxthresh){
    ll painter=1;
    ll total = 0;
    for(int i=0;i<a.size();i++){
        total += a[i];
        if(total>maxthresh){
            total=a[i];
            painter++;
        }
    }
    return painter;
}
ll bsearch(ll low,ll high,vector<int> &a,ll k){
    if(low>=high){
        return low;
    }
    int mid = low + ((high-low)/2);
    // cout<<"low:"<<low<<" high:"<<high<<" mid:"<<mid<<endl;
    int no_painter =no_of_painters(a,mid);
    if(no_painter<=k){
        return bsearch(low,mid,a,k);
    }
    else{
        return bsearch(mid+1,high,a,k);
    }
}

int paint(int A, int B, vector<int> &C) {
    ll n = C.size();
    ll sum = 0;
    int max1 = INT_MIN;
    for(int i=0;i<n;i++){
        sum +=C[i];
        max1 = max(max1,C[i]);
    }
    ll ans =  bsearch(max1,sum,C,A)% 10000003;
    return ((ans*B)%10000003);
    
}

int main(){
    int n,m,l;
    cin>>n>>m>>l;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<paint(m,l,a)<<endl;
    return 0;
}
