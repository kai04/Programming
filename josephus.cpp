#include<bits/stdc++.h>
using namespace std;


int josephus(int n, int k){
	//base case
	if(k>=n){
		k = k % n;
	}
	if(n==1)
		return 1;

	int ans = (josephus(n-1,k) + (k-1)) %n+1;
	return ans;
}

int main()
{
	int n;
	cin>>n;
	cout<<"ANS:"<<josephus(n,2)<<endl
;}	