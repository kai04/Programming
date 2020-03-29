#include <bits/stdc++.h>
using namespace std;
bool isreduce(string s){
    bool flag=true;
    for(int i=0;i<s.length();i++){
        if(s[i]=='A' && s[i+2]=='E'){
            flag = false;
            break;
        }
    }
    return flag;
}
void reduce(string &s){
    int n =s.length();
    int i=0;
    while(i+2<n){
        while(s[i]=='A' && s[i+2]=='E'){
            string x = s.substr(0,i+1) + s.substr(i+2,n-(i+2));
            n=x.length();
            s=x;
        }
        if(s[i]!='A' || s[i+2]!='E'){
            i++;
        }
    }
}
int main() {
    string s;
    cin>>s;
    while(!isreduce(s)){
    reduce(s);
        //cout<<s<<endl;
    }
    cout<<s<<endl;

	return 0;
}