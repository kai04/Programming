//https://leetcode.com/problems/generate-parentheses/submissions/
#include<bits/stdc++.h>
using namespace std;

vector<string> ans;
void solveUtils(int i,string s, vector<string>& wordDict,string temp,int len){
	if(i>len|| i>s.length())
		return;
	int n = s.length();
	cout<<"i:"<<i<<" s:"<<s<<" temp:"<<temp<<endl;
	if(n==0){
		ans.push_back(temp);
		temp = "";
	}
	string substring = s.substr(0,i+1);
	
	string oldtemp = temp;
	if(find(wordDict.begin(),wordDict.end(),substring)!=wordDict.end()){
		if(temp.length()!=0)
			temp = temp + " ";
		if((s.length()-i)>0){
			temp = temp + substring;
			string newS = s.substr(i+1,(s.length()-i));
			solveUtils(0,newS,wordDict,temp,len);
		}
		
		solveUtils(i+1,s,wordDict,oldtemp,len);
	}
	else{
		solveUtils(i+1,s,wordDict,oldtemp,len);
	}
}
vector<string> wordBreak(string s, vector<string>& wordDict) {
	ans.resize(0);
	int n = s.size();
	string temp = "";
	solveUtils(0,s,wordDict,temp,n);
	return ans;
}

int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	vector<string> d(n);
	for(int i=0;i<n;i++){
		cin>>d[i];
	}
	vector<string> res = wordBreak(s,d);
	for(auto it:res)
		cout<<it<<endl;
}
