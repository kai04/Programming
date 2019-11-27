#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &a,int k){
    int n = a.size();
    sort(a.begin(),a.end());
    vector<int> v(n);
    v = a;
    int ans = a[n-1] - a[0];
    for(int i=1;i<n-1;i++){
        int max1 = a[n-1],min1 = a[0];
        for(int j=0;j<n;j++){
            if(j<i){
                a[j] = a[j] + k;
            }
            else{
                a[j] = a[j] - k;
            }
        }
        cout<<"i:"<<i<<endl;
         for(auto it:a)
             cout<<it<<" ";
         cout<<endl<<"------------------------------"<<endl;
        int diff =(*max_element(a.begin(),a.end())-*min_element(a.begin(),a.end()));
        a = v;
        ans = min(ans,diff);
    }
    return ans;
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int k,n;
	    cin>>k>>n;
	    vector<int> a(n);
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    int ans = solve(a,k);
	    cout<<ans<<endl;
	}
	return 0;
}