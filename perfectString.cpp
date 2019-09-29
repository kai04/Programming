#include<bits/stdc++.h>
using namespace std;
bool checkChar(char c){
	if(c>=97 && c<=122){
		return true;
	}
	return false;
}
int solve(char lastchar,int i,string s){
	int n = s.length();
	//base case
	if(i==n){
		return 0;
	}
	//memoization

	//recursion
	int ret = INT_MAX;
	if(abs(s[i]-lastchar)>=2 &&abs(s[i]-lastchar)<=4){
		return solve(s[i],i+1,s);
	}
	else{
		if(checkChar(s[i]+2))
			ret = min(ret,(abs(s[i]+2-lastchar)+solve(s[i]+2,i+1,s)));
		if(checkChar(s[i]+3))
			ret = min(ret,(abs(s[i]+3-lastchar)+solve(s[i]+3,i+1,s)));
		if(checkChar(s[i]+4))
			ret = min(ret,(abs(s[i]+4-lastchar)+solve(s[i]+4,i+1,s)));
		if(checkChar(s[i]-2))
			ret = min(ret,(abs(s[i]-2-lastchar)+solve(s[i]-2,i+1,s)));
		if(checkChar(s[i]-3))
			ret = min(ret,(abs(s[i]-3-lastchar)+solve(s[i]-3,i+1,s)));
		if(checkChar(s[i]-4))
			ret = min(ret,(abs(s[i]-4-lastchar)+solve(s[i]-4,i+1,s)));
	}
	return ret;
}
int main(){
	string s;
	cin>>s;
	int res = solve(s[0],1,s);
	cout<<"RES:"<<res<<endl;
	
	return 0;
}