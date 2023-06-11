//https://practice.geeksforgeeks.org/problems/painting-the-fence3727/1
//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends

typedef long long ll;
const long mod = 1e9+7;
class Solution{
    public:
    
    long long countWays(int n, int k){
        vector<ll> same(n+1,0);
        vector<ll> diff(n+1,0);
        
        //base case
        same[1] = 0;
        diff[1] = k;
        for(int i=2;i<=n;i++){
            same[i] = diff[i-1]%mod;
            diff[i] = (((k-1)*diff[i-1])%mod + ((k-1)*same[i-1])%mod)%mod;
        }
        
        return (same[n]%mod+diff[n]%mod)%mod;
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends