//LIS in O(nlogn)
//https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
//https://leetcode.com/problems/longest-increasing-subsequence/
#include <bits/stdc++.h>
using namespace std;
// Binary search (note boundaries in the caller) 
int CeilIndex(std::vector<int>& v, int l, int r, int key) 
{ 
    while (r - l > 1) { 
        int m = l + (r - l) / 2; 
        if (v[m] >= key) 
            r = m; 
        else
            l = m; 
    } 
  
    return r; 
} 

int lengthOfLIS(vector<int>& nums) {
        if(nums.size()<=1)
            return nums.size();
        int len=1;
        vector<int> lis;
        lis.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=lis[0]){
                lis[0]=nums[i];
            }
            else if(nums[i]>lis[lis.size()-1]){
                lis.push_back(nums[i]);
                len++;
            }
            else{
                //int x=ceilIndex(lis,nums[i]);
                auto x1 =upper_bound(lis.begin(),lis.end(),nums[i]);
                *x1=nums[i];
            }

        }
        int ans=1;
        for(int i=1;i<lis.size();i++){
            if(lis[i]!=lis[i-1])
                ans++;
        }
        return ans;
    }

int LongestIncreasingSubsequenceLength(std::vector<int>& v) 
{ 
    if (v.size() == 0) 
        return 0; 
  
    std::vector<int> tail(v.size(), 0); 
    int length = 1; // always points empty slot in tail 
  
    tail[0] = v[0]; 
    for (size_t i = 1; i < v.size(); i++) { 
  
        // new smallest value 
        if (v[i] < tail[0]) 
            tail[0] = v[i]; 
  
        // v[i] extends largest subsequence 
        else if (v[i] > tail[length - 1]) 
            tail[length++] = v[i]; 
  
        // v[i] will become end candidate of an existing 
        // subsequence or Throw away larger elements in all 
        // LIS, to make room for upcoming grater elements 
        // than v[i] (and also, v[i] would have already 
        // appeared in one of LIS, identify the location 
        // and replace it) 
        else{
        	int k=CeilIndex(tail, -1, length - 1, v[i]);
        	cout<<"i:"<<i<<" lower:"<<k<<endl;
            tail[k] = v[i]; 
        }
    } 
  
    return length; 
} 

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> tail(n,0);
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> a[arr_i];
    }
    /*int len=1;
    tail[0]=a[0];
    for(int i=0;i<n;i++){
        if(a[i]<tail[0]){
            tail[0]=a[i];
        }
        else if(a[i]>tail[len-1]){
            len++;
            tail[len]=a[i];
        }
        else{
            vector<int>::iterator lower = upper_bound(tail.begin(),tail.begin()+len,a[i]);
            while(lower!=tail.end()+len&& a[i]>(*lower)){
                lower++;
            }
            (*lower)=a[i];
            cout<<"i:"<<i<<" lower:"<<tail[*lower]<<endl;
        }
    }
    cout<<len<<endl;

    cout<<"-------------------------------------------------"<<endl;
    */

    cout<<LongestIncreasingSubsequenceLength(a)<<endl;
}
