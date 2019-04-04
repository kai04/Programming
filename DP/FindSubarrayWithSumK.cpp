/*
https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0
https://www.geeksforgeeks.org/find-subarray-with-given-sum/
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        int k;
        cin>>n>>k;
        vector<int> a;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            a.push_back(x);
        }
        
        int sum1=0;
        int start=0;
        int end=0;
        unordered_map<int,int> m1;
        for(int i=0;i<n;i++){
            sum1+=a[i];
             if(sum1==k){
                 end=i;
                 break;
             }
            if(m1.find(sum1)==m1.end()){
                m1[sum1]=i;
            }
            
            if(m1.find(sum1-k)!=m1.end()){
                if(m1[sum1-k]!=i){
                    start=m1[sum1-k]+1;
                    end=i;
                    break;
                }
                
            }
         
        }
        if(start==0&&end==0)
            cout<<-1<<endl;
        else
            cout<<start+1<<" "<<end+1<<endl;
    }
	//code
	return 0;
}

