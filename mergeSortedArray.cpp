//https://leetcode.com/problems/merge-sorted-array/description/
#include <bits/stdc++.h>
using namespace std;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i=m-1,j=n-1,k=m+n-1;
    while(k>=0){
        if(j>=0 && i>=0 && nums1[i]<=nums2[j]){
            nums1[k] = nums2[j];
            j--;
        } else if(j>=0 && i>=0 && nums1[i]>nums2[j]){
            nums1[k] = nums1[i];
            i--;
        } else if(j>=0){
            nums1[k] = nums2[j];
            j--;
        } else if(i>=0){
            nums1[k] = nums1[i];
            i--;
        }
        k--;
    }
}

int main(){
    int m,n;
    cin>>m>>n;
    vector<int> a(m+n,0),b(n);
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    merge(a,m,b,n);
    for(auto x:a){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}


