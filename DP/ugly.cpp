//https://practice.geeksforgeeks.org/problems/ugly-numbers/0
#include<bits/stdc++.h>
using namespace std;

int find_min(vector<int> &exp,vector<int> a){
	// int ret=0;
	int min1 =  min((5*a[exp[2]]),(min(2*a[exp[0]],3*a[exp[1]])));
	if((2*a[exp[0]])==min1){
		exp[0]++;
	}
	if((3*a[exp[1]])==min1){
		exp[1]++;
	}
	if((5*a[exp[2]])==min1){
		exp[2]++;
	}
	return min1;
}
int main(){
	int n;
	cin>>n;
	vector<int> a(n+1,0);
	a[0]=1;
	int iter = 1;
	// int i=0,j=0;,k=0;
	vector<int> exp(3,0);

	while(iter<=n){
		int x = find_min(exp,a);
		// cout<<"iteration:"<<iter<<" ugly[iter]:"<<x<<" i:"<<exp[0]<<" j:"<<exp[1]<<" k:"<<exp[2]<<endl;
		a[iter] = x;
		/*for(int i=0;i<=iter;i++){
			cout<<a[i]<<" ";
		}
		 cout<<endl<<"---------------------------------"<<endl;*/
		iter++;
	}
	for(int i=0;i<=n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}