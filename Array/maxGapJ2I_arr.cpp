//https://www.interviewbit.com/problems/maximum-unsorted-subarray/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool comp(pair<int,int> p1,pair<int,int> p2){
    if(p1.first<=p2.first)
        return true;
    return false;
}
int maximumGap(const vector<int> &A) {
    int n=A.size(),ans=0;
    vector<pair<int,int>> a;
    for(int i=0;i<n;i++){
        a.push_back(make_pair(A[i],i));
    }
    sort(a.begin(),a.end(),comp);
    /*for(auto it:a)
        cout<<"("<<it.first<<","<<it.second<<"),";
    cout<<endl;*/
    int i=0,j=n-1;
    vector<int> lmin(n,INT_MAX);
    vector<int> rmax(n,INT_MIN);
    lmin[0] = a[0].second;
    for(int i=1;i<n;i++){
        lmin[i] = min(lmin[i-1],a[i].second);
    }
    rmax[n-1] = a[n-1].second;
    for(int i=n-2;i>=0;i--){
        rmax[i] = max(rmax[i+1],a[i].second);
    }
    /*for(auto it:lmin){
        cout<<it<<" ";
    }
    cout<<endl;
    
    for(auto it:rmax){
        cout<<it<<" ";
    }
    cout<<endl;*/
    for(int i=0;i<n;i++){
        ans = max(ans,(rmax[i]-lmin[i]));
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
    int res = maximumGap(a);
    cout<<"RES:"<<res<<endl;
    return 0;
}