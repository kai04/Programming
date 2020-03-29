//https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string/0

#include <bits/stdc++.h>
using namespace std;
vector<string> split(string s,char delimeter){
    vector<string> res;
    istringstream is(s);
    string token="";
    while(getline(is,token,delimeter)){
        res.push_back(token);
    }
    return res;
}
int main() {
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        vector<string> elems = split(s,'.');
        string res;
        if(elems.size()>=1){
            res = elems[elems.size()-1];
            for(int i=elems.size()-2;i>=0;i--){
                res = res + "." + elems[i]; 
            }
        }
        else{
            res = s;
        }
        // cout<<res<<endl;
        // copy(elems.begin(), elems.end(), ostream_iterator<string>(res, '.'));
        cout<<res<<endl;
    }
     
	//code
	return 0;
}