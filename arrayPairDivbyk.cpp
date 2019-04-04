//https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem/0
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
	    int k;
	    cin>>k;
	    vector<int> rem(k+1,0);
	    for(int i=0;i<n;i++){
	        rem[a[i]%k]++;
	    }
	    bool flag = true;
	   // cout<<"k:"<<k<<endl;
	  
	    for(int i=1;i<k;i++){
	       //  cout<<i<<" "<<" rem[i]:"<<rem[i]<<" rem[k-i]:"<<rem[k-i]<<endl;
	        if(rem[i]!=rem[k-i])
	            {
	                flag =false;
	                break;
	            }
	           
	    }
	    
	   // cout<<endl;
	   if(rem[0]>0){
	       //cout<<"rem[0]:"<<rem[0]<<endl;
	       if(rem[0]%2!=0)
	            flag =false;
	   }
	    if(flag)
	        cout<<"True"<<endl;
	    else
	    cout<<"False"<<endl;
	       
	   
	   
	}
	
	return 0;
}
