#include <bits/stdc++.h>
#include <climits>
using namespace std;
typedef long long ll;
vector<pair<ll,ll>> res(0);
vector<ll> resw(0);
vector<ll> resh(0);
vector<ll> res2(0);
ll LISpoly(vector<ll> a){
    int n=a.size(); 
    vector<ll> dp(n,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[i]>a[j]){
                dp[i]=max(dp[i],(dp[j]+1));
            }
        
        }
    }
    /*for(auto it:a)
        cout<<it<<" ";
    cout<<endl;
    cout<<"----------------------------------"<<endl;
        for(auto it:dp)
        cout<<it<<" ";
    cout<<endl;*/
    return (*max_element(dp.begin(),dp.end()));
}

int bsearch(vector<ll> s,int l,int h,int x){
    //cout<<"l:"<<l<<" h:"<<h<<endl;
    int mid =(l+h)/2;
    /*if(l==0 && h==1)
    {
        cout<<"x:"<<x<<endl;
        for(auto it:s)
            cout<<it<<" ";
    }
    cout<<endl;*/
    
    if(l==h)
        return l-1;
    if(mid+1==s.size())
        return mid;
    if(s[mid]<=x&&s[mid+1]>=x)
        return mid;
    else if(s[mid]<x&&s[mid+1]<x)
        return bsearch(s,mid+1,h,x);
    else
        return bsearch(s,l,mid,x);
}
vector<ll> ans(0);
map<ll,int> m;
ll large;
 int largei;
ll LIS1(vector<ll> a,int n){
    large=INT_MIN;
    largei=-1;
    vector<ll> parent(n,-1);
    for(int i=0;i<n;i++){
        if(a[i]>=large){
            ans.push_back(a[i]);
            large=a[i];
            parent[i]=largei;
            m[a[i]]=parent[i];
            largei=i;
        }
        else{
            int p=bsearch(ans,0,ans.size()-1,a[i]);
            parent[i]=m[ans[p+1]];
            if(ans[p+1]==large)
            {
                large=a[i];
                largei=i;
            }
            ans[p+1]=a[i];
            
        }
      /*cout<<"largest:"<<large<<endl;
     for(auto it:ans)
      cout<<it<<" ";
    cout<<endl;*/
    }
   
    /*cout<<"parent:"<<endl;
     for(auto it:parent)
      cout<<it<<" ";
    cout<<endl;*/
    res2.resize(n);
    res2=parent;
    return ans.size();
}
ll LIS(vector<ll> w,vector<ll> h,int n){
    resw.clear();
    resh.clear();
    res.clear();
     resw.resize(0);
    resh.resize(0);
    res.resize(0);
   ll largestw =INT_MIN;
    ll largesth =INT_MIN;
    for(int i=0;i<n;i++){
        //cout<<"i:"<<i<<endl;
        if(w[i]>largestw && h[i]>largesth){
            largestw=w[i];
            largesth=h[i];
            res.push_back(make_pair(w[i],h[i]));
            resw.push_back(w[i]);
            resh.push_back(h[i]);                    
        }
        else{
            //cout<<"resw.size:"<<resw.size()<<endl;
            int p=bsearch(resw,0,resw.size()-1,w[i]);
            if(h[p]<=h[i]){
                resw[p+1]=w[i];
                resh[p+1]=h[i];
                largestw=w[i];
                largesth=h[i]; 
            }
            else{
                int q=bsearch(resh,0,resh.size()-1,h[i]);
                    if(h[q]<=h[i]){
                    resw[q+1]=w[i];
                    resh[q+1]=h[i];
                    largestw=w[i];
                    largesth=h[i];
                    }   
                }                   
            }
        }
 
    return resw.size();
    }

int main() {
        ll n,x;
        cin>>n;
        vector<ll> a(n);
        for(int i=0;i<n;i++){
            cin>>x;
            a[i]=x;
                
        }
        cout<<"LIS length:"<<LIS1(a,n)<<endl;
        ll i=largei;
        while(i!=-1){
            cout<<a[i]<<" ";
            i=res2[i];
        }
    cout<<endl;
   //cout<<bsearch(a,0,a.size()-1,1)<<endl;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
