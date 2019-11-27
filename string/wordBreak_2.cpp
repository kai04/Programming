//https://practice.geeksforgeeks.org/problems/word-break-part-2/0/
#include <bits/stdc++.h>
using namespace std;
string appendString(string temp,string add){
    string temp1 = " ";
    temp1 = temp1 + add;
    temp = temp + temp1;
    return temp;
}
//vector<string> dict;
void word_break(string s,vector<string> &dict,string temp,set<string> &sol){
    //if(find(dict.begin(),dict.end(),s)!=dict.end()){
    if(s.length()==0){  
        //temp = appendString(temp,s);
        string temp1 = temp.substr(1,temp.length()-1);
        sol.insert(temp1);
        //temp="";
        //return true;
    }
        
    //bool ret = false; 
     for(int i=1;i<=s.length();i++){
            string pref = s.substr(0,i);
            string suff = s.substr(i,s.length()-i);
            //if prefix found in dictionary then recurse on suffix 
            if((find(dict.begin(),dict.end(),pref)!=dict.end())){
                 string temp1  = temp;
                 temp = appendString(temp,pref);
                 word_break(suff,dict,temp,sol);
                 temp = temp1;
            }
        }
      //  return ret;
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
        set<string> sol;
        word_break(s,dict,"",sol);
        // cout<<"RESULTS...."<<endl;
        for(auto it:sol)
            cout<<"("<<it<<")";
        cout<<endl;
    }
	//code
	return 0;
}
