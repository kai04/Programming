#include<bits/stdc++.h>

using namespace std;

vector<pair<int,int>> solve(vector<pair<int,int>> &a, vector<pair<int,int>> &b, int low, int high){
    int n = a.size();
    int m = b.size();
    vector<pair<int,int>> res;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int i=0,j=0;
    while(i<n && j<m){
        int sum = a[i].first + b[j].first;
        cout<<"i:"<<i<<" j:"<<j<<" sum:"<<sum<<endl;
        if(sum<=high && sum>=low){
            res.push_back({a[i].second,b[j].second});
        }
        if(a[i].first<b[j].first){
            i++;
        } else{
            j++;
        }
    }
    return res;
}
int main(){
    int n,m,low,high;
    cin>>n>>m;
    vector<int> a(n),b(m);
    vector<pair<int,int>> a1;
    vector<pair<int,int>> b1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        a1.push_back({a[i]*a[i],i});
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
        b1.push_back({b[i]*b[i],i});
    }
    cin>>low>>high;
    vector<pair<int,int>> res = solve(a1,b1,low,high);
    for(auto it:res){
        cout<<"["<<it.first<<","<<it.second<<"]"<<endl;
    }
    return 0;
}