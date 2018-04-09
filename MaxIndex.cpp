/*
 * maxIndex.cpp
 *
 * Given an array arr[], find the maximum j – i such that arr[j] > arr[i]
 *
 *  Created on: 30-Mar-2018
 *      Author: saurav
 */

//https://www.geeksforgeeks.org/given-an-array-arr-find-the-maximum-j-i-such-that-arrj-arri/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int maximIndex(vector<int> a){
    stack<int> s;
    int n=a.size();
    for(int i=0;i<n;i++){
        if(s.empty()||a[i]<a[s.top()]){
            s.push(i);
        }
    }
    
    int res=-1;
    
    for(int j=n-1;j>=0;j--){
        while((!s.empty())&&a[s.top()]<=a[j]){
            res=max(res,j-s.top());
            s.pop();
        }
        while((!s.empty())&&s.top()>j)
            s.pop();
    }
    return res;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a;

		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			a.push_back(x);
		}
cout<<maximIndex(a)<<endl;



	
}
return 0;
}



