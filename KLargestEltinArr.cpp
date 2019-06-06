//https://practice.geeksforgeeks.org/problems/k-largest-elements/0
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            pq.push(x);
        }
        for(int i=0;i<k;i++){
            int x = pq.top();
            pq.pop();
            cout<<x<<" ";
        }
        cout<<endl;
        
    }
	//code
	return 0;
}
