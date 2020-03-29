//https://www.geeksforgeeks.org/palindrome-partitioning-dp-17/
//https://www.interviewbit.com/problems/palindrome-partitioning-ii/
#include <bits/stdc++.h>
using namespace std;

bool isPallindrome(string s){
    int n = s.length();
    int start_idx,len;
    len = n/2;
    bool flag = true;
    if(n%2==0){
        start_idx = n/2;
    }
    else{
        start_idx = (n/2)+1;
    }
    string temp = s.substr(start_idx,len);
    // cout<<"s:"<<s<<" idx:"<<start_idx<<" len:"<<len<<" TEMP:"<<temp<<endl;
    reverse(temp.begin(),temp.end());
    for(int i=0;i<len;i++){
        if(s[i]!=temp[i]){
            flag = false;
            // cout<<"i:"<<i<<" s[i]:"<<s[i]<<endl;
            break;
        }
    }
    // cout<<"----------------------"<<endl;
    return flag;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    int n = s.length();
	    vector<vector<int>> dp(n,vector<int>(n,n));
	    vector<vector<bool>> P(n,vector<bool>(n,false));
	    //base case
	    for(int i=0;i<n;i++){
	        dp[i][i] = 0;
	        P[i][i] = true;
	    }
	    for(int i=0;i<n;i++){
	        dp[i][i] = 0;
	        P[i][i] = true;
	    }
	    for (int L = 2; L <= n; L++) { 
        for (int i = 0; i < n - L + 1; i++) { 
            int j = i + L - 1; 

            if (L == 2){ 
                P[i][j] = (s[i] == s[j]);
                dp[i][j] =  !(s[i] == s[j]);
            }
            else
                P[i][j] = (s[i] == s[j]) && P[i + 1][j - 1]; 
        }
	        
	    }  
	   
	    
	    for(int len=3;len<=n;len++){
	        for(int i=0;i<n;i++){
	            int j = i+len-1;
	            if(i<j && j<n){
	               // string tempstr = s.substr(i,j-i+1);
	               // bool f1 = isPallindrome(tempstr);
	               // cout<<"i:"<<i<<" j:"<<j<<" substr[i..j]:"<<tempstr<<" pall:"<<f1<<endl;
	                if(P[i][j]){
	                    dp[i][j] = 0;
	                }
	                else{
	                    dp[i][j] = j-i;   
	                }
	                for(int k=i;k<j;k++){
	                    int temp = 1 + dp[i][k] + dp[k+1][j];
	                    dp[i][j] = min(dp[i][j],temp);    
	                }
	            }   
	        }
	    }
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            cout<<dp[i][j]<<" ";
	        }
	        cout<<endl;
	    }
	    cout<<dp[0][n-1]<<endl;
	}
	return 0;
}