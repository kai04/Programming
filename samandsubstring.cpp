#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;
#define mod 1000000007 

ll ans=0;
ll sum=0;
ll numbersystem(string s){
    string temp="";
    for(int i=0;i<s.length();i++){
            temp+="1";
    }
    ll num = atol(temp.c_str())%mod;
    for(int i=0;i<s.length();i++){
        //char c=s[i];
        cout<<"num:"<<num<<endl;
        sum+=(s[i]-'0')*(i+1)*(num%mod);
        num=num/10;
    }
    return sum%mod;
}
ll rec(string s){
    if(s=="")
        return 0;
    string sub="";
    for(int i=0;i<s.length();i++){
        sub+=s[i];
        long l=atol(sub.c_str())%mod;
        ans+=l;
        ans=ans%mod;
    }
    ll ret=rec(s.substr(1,s.length()-1));
    return ans;
}
int main() {
    string s;
    cin>>s;
    //cout<<rec(s)<<endl;
    cout<<numbersystem(s)<<endl;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
