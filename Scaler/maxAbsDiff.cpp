/*
Maximum Absolute Difference
Problem Description
You are given an array of N integers, A1, A2 ,..., AN.

Return the maximum value of f(i, j) for all 1 ≤ i, j ≤ N. f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes absolute value of x.


Problem Constraints
1 <= N <= 100000 1 <= A[i] <= 1e9 


Input Format
First argument is an integer of size N.


Output Format
Return an integer denoting the maximum value of f(i, j).


Example Input
Input 1:
A=[1, 3, -1]


Example Output
Output 1:
5
*/

int Solution::maxArr(vector<int> &A) {
    int n = A.size();
    int maxAdd = INT_MIN;
    int maxSub = INT_MIN;
    int minAdd = INT_MAX;
    int minSub = INT_MAX;
    for(int i=0;i<n;i++){
        maxAdd = max(maxAdd,A[i]+i);
        maxSub = max(maxSub,A[i]-i);
        
        minAdd = min(minAdd,A[i]+i);
        minSub = min(minSub,A[i]-i);
    }
    int ans = 0;
    int temp1 = abs(maxAdd - minAdd);
    int temp2 = abs(maxSub - minSub);
    ans = max(temp1,temp2);
    return ans;
    
}
