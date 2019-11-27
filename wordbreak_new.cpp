#include<bits/stdc++.h>
using namespace std;

int solve(int j,string s,vector<string> &B){
    int m = s.length();
    if(m==0|| j==m)
        return true;

    string s1 = s.substr(j,m-j);
    if((find(B.begin(),B.end(),s1)!=B.end()))
        return 1;
    for(int i=j+1;i<m;i++){
        string s2 = s1.substr(j,i);
        string s3 = s1.substr(i,m-i);
        // cout<<"s1:"<<s1<<" s2:"<<s2<<" flag:"<<flag<<endl;
          if((find(B.begin(),B.end(),s2)!=B.end()) && solve(j,s,B)){
            return 1;
        }
    }
    return 0;
}
int wordBreak(string A, vector<string> &B) {
    int n = B.size();
    sort(B.begin(),B.end());
    if(solve(0,A,B))
        return 1;
    else
        return 0;
}

int main(){
    int n;
    cin>>n;
    vector<string> a;
    string s;
    cin>>s;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int res = wordBreak(s,a);
    cout<<"RES:"<<res<<endl;
    return 0;
}