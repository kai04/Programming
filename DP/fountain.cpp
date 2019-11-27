//https://leetcode.com/discuss/interview-question/363036/walmart-oa-2019-activate-fountains
#include<bits/stdc++.h>
using namespace std;

int f(int l,int r,vector<int> &left,vector<int> &right){
	int n = left.size();
	//base case
	if(l<0||r>=n){
		return INT_MAX/2;
	}
	if(l==r){
		return 1;
	}
	if(l>r){
		return INT_MAX/2;
	}
	int p = left[l];
	int q = right[l];
	int s = left[r];
	int t = right[r];

	//recursion
	//fountain at 
	int x1 = (1 + f(0,p-1,left,right)+ f(q+1,r,left,right));
	int x2 = (1 + f(l,s-1,left,right)+ f(q+1,n,left,right));
	int x3 = f(0,l-1,left,right)+ f(l+1,r-1,left,right)+f(r+1,n,left,right);
	int ans  = INT_MAX/2;
	ans = min(ans,x1);
	ans = min(ans,x2);
	ans = min(ans,x3);
	return ans;

}

int solve(vector<int> &a,int low,int high,vector<vector<int>>&dp,int n){
	if(low>high)
		return 0;
	if(low==high)
		return 1;
	if(dp[low][high]!=INT_MAX/2)
		return dp[low][high];
	//dp[low][high]=INT_MAX;
	for(int curr = low;curr<=high;curr++){
		int right = min(n,curr+a[curr]);
		int left = max(1,curr-a[curr]);
		dp[low][high] = min(dp[low][high],1+solve(a,right,high,dp,n));
		dp[low][high] = min(dp[low][high],1+solve(a,low,left,dp,n));
	}
	return dp[low][high];
}
int numFountains(vector<int> fountains) {
    int n = fountains.size();
    vector<int> extents(n, 0);

    for (int i = 0; i < n; i++) {
        int left = max(i - fountains[i], 0);
        int right = min(i + (fountains[i] + 1), n);

        extents[left] = max(extents[left], right);
        cout<<"i:"<<i<<" left[i]:"<<left<<" right[i]:"<<right<<" extent[left]:"<<extents[left]<<endl;
    }
    
    int num_fountains = 1;
    int right = extents[0], next_right = 0;
    for (int i = 0; i < n; i++) {
        next_right = max(next_right, extents[i]);
        if (i == right) {
            num_fountains++;
            right = next_right;
        }
    }

    return num_fountains;
}
int main(){
	int n;
	cin>>n;
	vector<int> a(n);
	vector<int> left(n);
	vector<int> right(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i-a[i]<0){
			left[i] = 0;
		}
		else{
			left[i] = i-a[i];	
		}

		if(i+a[i]>=n){
			right[i] = n-1;
		}
		else{
			right[i] = i+a[i];	
		}
	}
	vector<vector<int>> dp(n+1,vector<int>(n+1,INT_MAX/2));
	//int ans = solve(a,0,n-1,dp,n);

	//int ans = f(0,n-1,left,right);
	int ans  = numFountains(a);
	cout<<"ANS:"<<ans<<endl;


	return 0;
}
