#include<bits/stdc++.h>
using namespace std;

string int2bin(string value,long unsigned int k ){
	string ret = bitset<64>(value).to_string();
	return ret;
}
int main(){
	string s;
	s = "2045";
	int k = 12;	
	string ans = int2bin(s,k);
	cout<<"ANS:"<<ans<<endl;
	// cin.getchar();
	//int x;
	//cin>>x;

	return 0;
}