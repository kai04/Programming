//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
class Solution {
public:
    int findMin(vector<int>& A) {
        int n = A.size();
        if(n==1 || A[0]<A[n-1])
            return A[0];
        int pivot = -1;
        int l = 0;
        int r = n-1;
        while(l<r){
            int m = l + (r-l)/2;
            // cout<<"l:"<<l<<" r:"<<r<<" m:"<<m<<" pivot:"<<pivot<<endl;
            if(m>0 && A[m]<A[m-1]){
                pivot = m;
                break;
            } else if(m<n-1 && A[m+1]<A[m]){
                pivot = m+1;
                break;
            } else if(A[m]>A[r]){
                l = m+1;
            } else if(A[m]>A[r]){
                r = m;
            } else {
                r--;
            }
        }
        
        if(pivot!=-1){
            return A[pivot];
        }
        return A[0];
    }
};