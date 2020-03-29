//https://practice.geeksforgeeks.org/problems/consecutive-1s-not-allowed/0
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;

int main() {
    int t;
    cin>>t;
    vector<ll> a(101,0);
    vector<ll> b(101,0);
    b[0]=1;
    a[0]=1;
    for(int i=1;i<101;i++){
        a[i]=(a[i-1]%mod+b[i-1]%mod)%mod;
        b[i]=a[i-1]%mod;
    }
    while(t--){
        int n;
        cin>>n;
        cout<<(a[n-1]%mod+b[n-1]%mod)%mod<<endl;
    }
	//code
	return 0;
}
