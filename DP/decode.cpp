#include<bits/stdc++.h>
using namespace std;
int solve(string s,int i){
    if(i+1>=s.length()){
        return 1;
    }
    int x1 = s[i] - '0';
    int x2 = s[i+1] - '0';
    int x3 = x1*10 + x2;
    cout<<"x3:"<<x3<<" i:"<<i<<" x1:"<<x1<<" x2:"<<x2<<endl;
    return (solve(s,i+1) * solve(s,i+2)); 
}


int numDecodings(string A) {
    int n = A.length();
    vector<int> dp(n+1,0);
    dp[0] = 1;
    
    if((A[0]-'0')<=2 &&(A[1]-'0')<=6){
    	// cout<<"A[0]:"<<A[0]<<" A[1]:"<<A[1]<<endl;
    	dp[1] = 2;
    }
    else{
    	dp[1] = 1;
    }
    // cout<<"n:"<<n<<endl;
    for(int i=2;i<n;i++){
        int x3 = INT_MAX,x1,x2;
        if(i>0){
            x1 = A[i] - '0';
            x2 = A[i-1] - '0';
            x3 = x2*10 + x1;
        }
        cout<<"i:"<<i<<" x3:"<<x3<<" x1:"<<x1<<" x2:"<<x2<<endl;
        if(x3<=26 && x2!=0){
            dp[i] = dp[i-1] + dp[i-2];
        }
        else{
            dp[i] = dp[i-1];
        }
         cout<<"i:"<<i<<" dp[i]:"<<dp[i]<<endl;
         cout<<"--------------------------"<<endl;
    }
    for(auto it:dp)
    	cout<<it<<" ";
    cout<<endl;
    return dp[n-1];
}
int main(){
	string x;
	cin>>x;
	//int res = solve(x,0);
	int res = numDecodings(x);
	cout<<"RES:"<<res<<endl;
	return 0;
}