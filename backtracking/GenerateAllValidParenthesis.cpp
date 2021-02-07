//https://leetcode.com/problems/generate-parentheses/submissions/
#include<bits/stdc++.h>
using namespace std;

vector<string> ans;
void solveUtils(string s,int cnt,int n){
	//base case
	//cout<<"s:"<<s<<"cnt:"<<cnt<<endl;
	if(s.length()==(2*n)){
		if(cnt==0)
			ans.push_back(s);
		return;
	}
	if(cnt<n){
		solveUtils(s+"(",cnt+1,n);
	}
	if(cnt>0){
		solveUtils(s+")",cnt-1,n);
	}
	
}
vector<string> generateParenthesis(int n) {
	ans.resize(0);
	solveUtils("",0,n);
	return ans;
}

int main(){
	int n;
	cin>>n;
	vector<string> res = generateParenthesis(n);
	for(auto it:res)
		cout<<it<<endl;
}
