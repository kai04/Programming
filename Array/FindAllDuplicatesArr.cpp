//https://leetcode.com/problems/find-all-duplicates-in-an-array/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for(int i=0;i<n;i++){
            int x = nums[abs(nums[i])-1];
            if(x<0){
                res.push_back(abs(nums[i]));
            }
            else{
                nums[abs(nums[i])-1] = -x;
            }
        }
        return res;
    }
};


//https://www.interviewbit.com/problems/find-duplicate-in-array/
int Solution::repeatedNumber(const vector<int> &A) {
    int slow = A[0];
    int fast = A[A[0]];
    while (slow != fast) {
        slow = A[slow];
        fast = A[A[fast]];
    }

    fast = 0;
    while (slow != fast) {
        slow = A[slow];
        fast = A[fast];
    }
    if(slow==0) return -1;
        return slow;
}