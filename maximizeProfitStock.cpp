// Maximize Profit by making 1 txn ,
// Stock value of a day are stored in array = [7 1 5 3 6 4]
// output = 5

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &a){
	int n = a.size();
	vector<int> min_left(n,INT_MAX);
	vector<int> max_right(n,INT_MIN);
	for(int i=0;i<n;i++){
		if(i==0){
			min_left[i] = a[i];
		} else{
			min_left[i] = min(min_left[i-1],a[i]);
		}
		
	}
	for(int i=n-1;i>=0;i--){
		if(i==n-1)
			max_right[i] = a[i];
		else	
		max_right[i] = max(max_right[i+1],a[i]);
	}
	
	int ans = 0;
	for(int i=0;i<n;i++){
		ans = max(ans, (max_right[i]-min_left[i]));
	}

	return ans;
}

int main(){
	int n,k;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<"ANS:"<<solve(a)<<endl;
	return 0;
}