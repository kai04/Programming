
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool comp(pair<int,int> p1,pair<int,int> p2){
    if(p1.first<p2.first)
        return true;
    return false;
}
vector<int> subUnsort(vector<int> &A) {
    int n = A.size();
    vector<pair<int,int>> a;
    for(int i=0;i<n;i++){
        a.push_back(make_pair(A[i],i));
    }
    stable_sort(a.begin(),a.end(),comp);
    int i=0,j=n-1;
    for(auto it:a){
        cout<<"("<<it.first<<","<<it.second<<"),";
    }
    cout<<endl;
    while(i<n && i==a[i].second){
        i++;
    }
    
    while(j>=0 && j==a[j].second){
        j--;
    }
    vector<int> res;
    if(i<j){
        res.push_back(i);
        res.push_back(j);
    }
    else{
        res.push_back(-1);
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> res = subUnsort(a);
    for(auto it:res)
        cout<<it<<" ";
    cout<<endl;
    return 0;
}