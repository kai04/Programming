/*
https://www.geeksforgeeks.org/find-subarray-with-given-sum-in-array-of-integers/
https://practice.geeksforgeeks.org/problems/subarray-range-with-given-sum/0
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
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
        int k;
        cin>>k;
        int sum1=0;
        int cnt=0;
        unordered_map<int,int> m;
        unordered_map<int,int> m1;
        for(int i=0;i<n;i++){
            sum1+=a[i];
             if(sum1==k){
                 cnt++;
             }
            if(m.find(sum1)==m.end()){
                m[sum1]=1;
                m1[sum1]=i;
            }
            else{
                m[sum1]++;
            }
            if(m.find(sum1-k)!=m.end()){
                if(k==0){
                if(m1[sum1-k]!=i){
                    cnt+=m[sum1-k]-1;
                }
                }
                else{
                   cnt+=m[sum1-k];
                }
            }
            // cout<<"i:"<<i<<" sum1:"<<sum1<<" m[sum1]:"<<m[sum1]<<" m1[sum1-k]:"<<m1[sum1-k]<<" cnt:"<<cnt<<endl; 
        }
        cout<<cnt<<endl;
    }
	//code
	return 0;
}
