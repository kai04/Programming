//https://leetcode.com/problems/longest-turbulent-subarray/
class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int n = A.size();
        if(n==0)
            return 0;
        
        vector<int> incr(n,1);
        vector<int> decr(n,1);
        int max_cnt = 1;
        for(int i=1;i<n;i++){
            if(A[i]<A[i-1]){
                decr[i] = incr[i-1]+1;
            }
            else if(A[i]>A[i-1]){
                incr[i] = decr[i-1]+1;
            }
            // cout<<"i:"<<i<<" INCR[i]:"<<incr[i]<<" DECR[i]:"<<decr[i]<<endl;
            max_cnt = max(max_cnt,decr[i]);
            max_cnt = max(max_cnt,incr[i]);
        }
        return max_cnt;
    }
};