//https://leetcode.com/problems/peak-index-in-a-mountain-array/
class Solution {
public:
    int bsearch(int l,int h, vector<int> &a){
        int m = l + (h-l)/2;
        if(m==0){
            return -1;
        } else if(m==h){
            return -1;
        } else if(a[m-1]<a[m] && a[m]>a[m+1]){
            return m;
        } else if(a[m]<a[m+1]){
            return bsearch(m,h,a);
        } else if(a[m-1]>a[m]){
            return bsearch(l,m,a);
        }
        return -1;
    }
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int ans = bsearch(0,n-1, arr);
        return ans;
    }
};