//http://www.geeksforgeeks.org/dynamic-programming-set-32-word-break-problem/
#include <bits/stdc++.h>
using namespace std;
//vector<string> dict;
bool word_break(string s,vector<string> &dict){
    if(s.length()==0)
        return true;
    bool ret = false; 
     for(int i=1;i<=s.length();i++){
            string pref = s.substr(0,i);
            string suff = s.substr(i,s.length()-i);
            //if prefix found in dictionary then recurse on suffix 
            if((find(dict.begin(),dict.end(),pref)!=dict.end()) && word_break(suff,dict)){
                ret = true; 
            }
        }
        return ret;
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict(n);
        for(int i=0;i<n;i++){
            cin>>dict[i];
        }
        string s;
        cin>>s;
       cout<<word_break(s,dict)<<endl;
    }
	//code
	return 0;
}
