//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/submissions/
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
    int findMin(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        int pivot =findPivot(nums,0,n-1);
        if(pivot==-1)
            return nums[0];
        // cout<<"PIVOT:"<<pivot<<endl;
        int res=0;
        if(nums[0]<=nums[pivot]){
            res = nums[(pivot+1)%n];
        }
        return res;
    }
};
