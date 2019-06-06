#include <bits/stdc++.h>
#include <climits>
using namespace std;
typedef long long ll;
int bsearch(vector<int> a,int l,int h,int x){
    int mid =(l+h)/2;
    //cout<<"mid:"<<mid<<" l:"<<l<<" h:"<<h<<endl;
    if(h<l)
        return -1;
    if(a[mid]==x)
        return mid;
    else if(a[mid]<x)
        return (bsearch(a,mid+1,h,x));
    else
        return (bsearch(a,l,mid-1,x));
}
int cut_dp(int s,vector<int> &l,vector<int> &p){
    int n=l.size();
    vector<int> dp(n+1);
    //dp(i) denote max profit from rod of len i
    dp[0]=0;
    //initially max profit for any rod is whole rod itself
    for(int i=1;i<dp.size();i++)
        dp[i]=p[i-1];
    //for any rod of len i ,I will cut the rod from (1,i) denoted by j 
    //then one part is of len j another of i-j,calculate this iteratively 
    for(int i=1;i<=n;i++){
        int max1=-1;
        for(int j=1;j<=i;j++){
            max1=max(max1,(dp[j]+dp[i-j]));
        }
        dp[i]=max(dp[i],max1);
    }
    for(auto it:dp)
        cout<<it<<" ";
    cout<<endl;
    return dp[s];
}
int cut(int s,vector<int> &l,vector<int> &p,vector<int> &mem){
    int max1=0;
    //if(s==0)
    //    return 0;
    if(s<=0)
        return 0;
    else {
        int q=bsearch(l,0,l.size()-1,s);
        
        for(int i=0;i<=q;i++){
            if(mem[s-l[i]]==0){
                mem[s-l[i]]=cut(s-l[i],l,p,mem);
                max1=max(max1,(p[i]+mem[s-l[i]]));
            }
            else{
                max1=max(max1,(p[i]+mem[s-l[i]]));
            }
            //cout<<"i:"<<i<<" s:"<<s<<" max:"<<max1<<endl;
        }
    }
     return max1;   
}
int main() {
    int n,x;
    cin>>n;
    vector<int> l(n);
    vector<int> p(n);
    for(int i=0;i<n;i++){
        cin>>x;
        l[i]=x;
    }
    for(int i=0;i<n;i++){
        cin>>x;
        p[i]=x;
    }
    vector<int> mem(n,0);
    //cout<<bsearch(l,0,l.size()-1,8)<<endl;
    //cout<<cut(l[n-1],l,p,mem)<<endl;
    cout<<cut_dp(l[n-1],l,p)<<endl;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
