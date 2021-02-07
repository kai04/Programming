#include<bits/stdc++.h>
using namespace std;

int main(){
	int q;
	cin>>q;
	string s;
	while(q--){
		char symbol;
		char ix;
		string input;
		cin>>symbol>>ix>>input;
		int index = ix-'0';
		//cout<<"Symbol:"<<symbol<<endl;
		//cout<<"Index:"<<index<<endl;
		//cout<<"Input:"<<input<<endl;
		//cout<<"-------------------------"<<endl;
		if(symbol=='+'){
			if(index==0){
				s = input+s;
			}
			else{
				string pre="";
				string post="";
				pre = s.substr(0,index);
				post = s.substr(index,s.length()-index);
				s = pre + input+ post;
				
			}
		}
		else if(symbol=='?'){
			stringstream ss(input);
			int len=0;
			ss>>len;
			string sub = s.substr(index-1,len);
			cout<<sub<<endl;
		}
		//cout<<"symbol:"<<symbol<<" index:"<<index<<" input:"<<input<<endl;
		//cout<<"Output:"<<s<<endl;
		//cout<<"-----------------------------------"<<endl;
	}
	return 0;
}
