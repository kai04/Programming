
//https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/submissions/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void PrintStack(stack<char> st){
	cout<<"printing stack..."<<endl;
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl<<"---------------------------------------"<<endl;
	}
void check(stack<char> &st){
	string last3 ="";
	last3+=string(1,st.top());
	st.pop();
	last3+=string(1,st.top());
	st.pop();
	last3+=string(1,st.top());
	st.pop();
	if(last3=="cba"){
		return;
	}
	else{
		for(int i=last3.length()-1;i>=0;i--)	
			st.push(last3[i]);
	}
}
bool isValid(string S) {
        string pattern = "abc";
        stack<char> st;
        int j=pattern.length()-1;
        for(int i=0;i<S.length();i++){
            st.push(S[i]);
            // cout<<"i:"<<i<<" S[i]:"<<S[i]<<endl;
            // cout<<"Before..."<<endl;
            // PrintStack(st);
            if(st.size()>=3){
            	check(st);
            }
            // cout<<"After..."<<endl;
            // PrintStack(st);
            // cout<<endl<<"=================================="<<endl;
        }
        if(st.empty())
            return true;
        return false;
        
    }

    


int main() {
	string s;
	cin>>s;
	cout<<isValid(s)<<endl;
	
	
	return 0;
}