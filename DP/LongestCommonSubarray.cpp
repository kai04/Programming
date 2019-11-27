//https://leetcode.com/problems/maximum-length-of-repeated-subarray/
class Solution {
public:
   
    int findLength(vector<int>& A, vector<int>& B) {
        int n=A.size();
        int m=B.size();
        vector<vector<int>> LC_Suffix(n,vector<int>(m,0));
        //initilization
        for(int i=0;i<n;i++){
            if(A[i]==B[0]){
                LC_Suffix[i][0] = 1;
            }
        }
        
        for(int i=0;i<m;i++){
            if(B[i]==A[0]){
                LC_Suffix[0][i] = 1;
            }
        }
        int ans = 0 ;
        //recurrence
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(A[i]==B[j]){
                    LC_Suffix[i][j] = LC_Suffix[i-1][j-1] + 1;
                }
                else{
                    LC_Suffix[i][j] = 0 ;
                }
                ans = max(ans,LC_Suffix[i][j]);
            }
        }
        
        return ans;
    }
};
