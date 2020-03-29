/*
Maximum Consecutive Gap
Problem Description
Given an unsorted integer array A of size N.
Find the maximum difference between the successive elements in its sorted form. Try to solve it in linear time/space.
You may assume that all the elements in the array are non-negative integers and fit in the 32-bit signed integer range.
You may also assume that the difference will not overflow.
Return 0 if the array contains less than 2 elements.  


Problem Constraints
1 <= N <= 1000000 1 <= A[i] <= 1e9  


Input Format
First argument is an integer array A of size N.


Output Format
Return an integer denoting the maximum difference.


Example Input
Input 1:
A = [1, 10, 5]
 


Example Output
Output 1:
5
 


Example Explanation
Explanation 1:
After sorting, the array becomes [1, 5, 10]
Maximum difference is (10 - 5) = 5.
*/

int Solution::maximumGap(const vector<int> &A) {
    int n = A.size();
    if(n<2)
        return 0;
    vector<int> min_bucket(n,-1);
    vector<int> max_bucket(n,-1);
    int max1 = INT_MIN;
    int min1 = INT_MAX;
    for(int i=0;i<n;i++){
        min1 = min(min1,A[i]);
        max1 = max(max1,A[i]);
    }
    int gap = (max1-min1)/(n-1);
    //base case
    if(gap==0)
        return (max1-min1);
    for(int i=0;i<n;i++){
        int bucket = (A[i]-min1)/gap;
        if(min_bucket[bucket]<0){
            min_bucket[bucket] = A[i];
            max_bucket[bucket] = A[i];
        }
        else{
            min_bucket[bucket] = min(min_bucket[bucket],A[i]);
            max_bucket[bucket] = max(max_bucket[bucket],A[i]);
        }
    }
    int max_diff = 0;
    int prev_index = 0;
    for(int i=0;i<n;i++){
        if(min_bucket[i]>0){
            max_diff = max(max_diff,min_bucket[i]-max_bucket[prev_index]);
            prev_index = i;
        }
    }
    return max_diff;
}

