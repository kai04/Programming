/*
INPUT:
4
a b c a
OUTPUT:
4
*/
#include<bits/stdc++.h>
using namespace std;


void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}


vector<int> cutFilms(vector<string> inputList){
	int n = inputList.size();
	unordered_map<string,int> mp;
	for(int i=0;i<n;i++){
		mp[inputList[i]] = i;
	}
	vector<int> res;
	int j;
	for(int i=0;i<n;i++){
		int cnt_max = mp[inputList[i]];
		for(j=i+1;j<=cnt_max;j++){
			if(cnt_max < mp[inputList[j]]){
				cnt_max = mp[inputList[j]];
			}
		}
		j--;
		// cout<<"i:"<<i<<" j:"<<j<<endl;
		res.push_back((j-i+1));
		i=j; 	
	}
	
	return res;
}
int main(){
	c_p_c();
	int n;
	cin>>n;
	
	vector<string> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	vector<int> ans = cutFilms(v);
	for(auto it:ans){
		cout<<it<<" ";
	}
	cout<<endl;
	return 0;
}