//https://leetcode.com/problems/search-in-rotated-sorted-array/
class Solution {
public:
     int findPivot(vector<int> &a,int low,int high){
        if(low>high){
            return -1;
        }
        if(low==high){
            return low;
        }
        int mid = low +((high-low)/2); 
        if(mid < high && a[mid]>a[mid+1]){
            return mid;
        }
        if(low< mid && a[mid-1]>a[mid]){
            return mid-1;
        }
        if(a[low]>=a[mid]){
            return findPivot(a,low,mid-1);
        }
        return findPivot(a,mid+1,high);
    }
    
    int findPivot1(vector<int> &a){
        int n = a.size();
        int l = 0;
        int r = n-1;
        int ans = -1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(a[mid]<=a[n-1]){
                r = mid-1;
                ans = mid;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
    int bsearch(vector<int> a,int low,int high,int target){
        int mid = low+(high-low)/2;
        // cout<<"MID:"<<mid<<" low:"<<low<<" high:"<<high<<endl;
        if(low>high)
            return -1;
         
        if(a[mid]==target){
            return mid;
        }
        else if(a[mid]<target)
            return bsearch(a,mid+1,high,target);
        else{
            return bsearch(a,low,mid-1,target);
        }
    }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==0)
            return -1;
        // int pivot = findPivot(nums,0,n-1);
        int pivot = findPivot1(nums);
        int ans = -1;
        // cout<<"PIVOT:"<<pivot<<endl;
        if(pivot<=0){
            ans = bsearch(nums,0,n-1,target);
        }
        else if(target>=nums[0]){
            ans = bsearch(nums,0,pivot-1,target);
        }else{
            ans = bsearch(nums,pivot,n-1,target);
        }
        return ans;
    }
};



