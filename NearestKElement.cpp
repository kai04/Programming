//https://leetcode.com/problems/find-k-closest-elements/
#include <bits/stdc++.h>
using namespace std;
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        int n = arr.size();
        auto it = lower_bound(arr.begin(),arr.end(),x);
        int j = it-arr.begin();
        int i = j-1;
        // cout<<"i:"<<i<<" j:"<<j<<" k:"<<k<<endl;
        while(k>0 && i>=0 && j<n){
            // cout<<"i:"<<i<<" j:"<<j<<" k:"<<k<<endl;
            if(abs(arr[i]-x)<abs(arr[j]-x)){
                ans.push_back(arr[i]);
                i--;
            } else if(abs(arr[i]-x)==abs(arr[j]-x) && arr[i]<arr[j]){
                ans.push_back(arr[i]);
                i--;
            } else if(abs(arr[i]-x)>abs(arr[j]-x)){
                ans.push_back(arr[j]);
                j++;
            }
            k--;
        }
        // cout<<"HERE1"<<endl;
        if(k>0){
            if(i<0){
                while(j<n && k>0)
                {
                    // cout<<"XXXXX I:"<<i<<" J:"<<j<<" K:"<<k<<endl;
                    ans.push_back(arr[j]);
                    j++;
                    k--;
                }
            } else if(j==n){
                while(i>=0 && k>0)
                {
                    // cout<<"YYYYYY I:"<<i<<" J:"<<j<<" K:"<<k<<endl;
                    ans.push_back(arr[i]);
                    i--;
                    k--;
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
    int main(){
        int k,x,n;
        cin>>k>>x>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        vector<int> res = findClosestElements(a,k,x);
        for(auto it:res)
            cout<<it<<" ";
        cout<<endl;
        return 0;
    }