//https://www.interviewbit.com/problems/tushars-birthday-bombs/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> solve(int A, vector<int> &B) {
    int n = B.size();
    vector<vector<int>> dp(n+1,vector<int>(A+2,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=A;j++){
			//cout<<"i:"<<i<<" j:"<<j<<j<<endl;
            if(B[i-1]<=j){
                dp[i][j] = max(dp[i-1][j],1+dp[i][j-B[i-1]]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    vector<int> sol;
    int j = A;
    int i=n;
    while(i>0 && j>0){
        if(j>=B[i-1] && dp[i][j] != dp[i-1][j] && dp[i][j]>=dp[i][j-B[i-1]]){
			sol.push_back(i-1);
			j = j - B[i-1];
		}
		else{
			i--;
		}
		//cout<<i<<" "<<j<<endl;
    }
    return sol;
}


int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++)
		cin>>a[i];
	vector<int> res = solve(m,a);
	for(auto it:res)
		cout<<it<<" ";
	cout<<endl;
}
