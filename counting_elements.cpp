//https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/528/week-1/3289/
#include<bits/stdc++.h>
using namespace std;
int countElements(vector<int>& arr) {
        int n = arr.size();
        map<int,int> m;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }
        int cnt =0;
        for(auto it:m){
            int x = it.first;
            if(m.find(x+1)!=m.end()){
                int y = m[x+1];
                cout<<"x:"<<x<<" y:"<<y<<endl;
                cnt+=min(m[x],m[x+1]);
            }
        }
        
        return cnt;
    } 
    
    int main(){
		int n;
		cin>>n;
		vector<int> a(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int ans = countElements(a);
		cout<<"ANS:"<<ans<<endl;
		return 0;
	}
