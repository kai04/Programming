//https://leetcode.com/problems/search-insert-position/
class Solution {
public:
    
    
    int searchInsert(vector<int>& A, int target) {
        int n = A.size();
        int low = 0,high = n-1;
        if(target>A[n-1])
            return n;
        if(target<A[0])
            return 0;
        
        while(low<high){
            int mid = low + (high-low)/2;
            // cout<<"low:"<<low<<" high:"<<high<<" mid:"<<mid<<endl;
            if(A[mid]==target){
                high = mid;
                break;
            }
            else if(A[mid]>target){
                high = mid;
            }
            else{
                low = mid+1;
            }
            
        }
        return high;
    }
};
