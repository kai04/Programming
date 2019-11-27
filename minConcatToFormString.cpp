//https://codeforces.com/blog/entry/70730
/*
s=zaza
t=baz
*/
#include <bits/stdc++.h>
using namespace std;

int solve(string s,string t){
    int n = s.length();
    int m = t.length();
    int i=0,j=0,attempt=0;
    int ans = 0;
    while(i<n && attempt<=n){
        while(j<m){
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        if(j>=m){
            ans++;
            j=0;
        }
        attempt++;
    }
    // cout<<"a:"<<ans<<endl;
    if(attempt>n)
        return INT_MAX;
    else
        return ans;
}

int main() {
	//code
	string s,t;
    cin>>s>>t;
    int ans = solve(s,t);
    cout<<"ANS:"<<ans<<endl;
	return 0;
}