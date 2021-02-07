//https://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> a(n);
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    int low = 0,mid = 0, high = n-1;
	    while(mid<=high){
	        if(a[mid]==0){
	            int temp = a[low];
	            a[low] = a[mid];
	            a[mid] = temp;
	            low++;
	            mid++;
	        }
	        else if(a[mid]==1){
	            mid++;
	        }
	        else if(a[mid]==2){
	            int temp = a[high];
	            a[high] = a[mid];
	            a[mid] = temp;
	            high--;
	        }
	    }
	    for(int i=0;i<n;i++){
	        cout<<a[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}