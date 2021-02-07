//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
class Solution {
public:
    /* 
        0 1 2 3 4 5
        5,7,7,8,8,10
        F F F T T T
        
        0 1 2 3 4 5
        5,7,7,8,8,10
        F F F F F T
    
    */
    int find_first_occurence(vector<int>& a, int target){
        int n = a.size();
        if(n==0 || a.back()<target){
            return n;
        }
        int left = 0;
        int right = n-1;
        while(left<right){
            int mid = left + (right-left)/2;
            if(a[mid]>=target){
                right = mid;
            }
            else{
                left = mid+1;
            }
        }
        return left;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int a = find_first_occurence(nums,target);
        int b = find_first_occurence(nums,target+1)-1;
        if(a<=b){
            return vector<int>({a,b});
        }
        else{
            return vector<int>({-1,-1});
        }
    }
};
