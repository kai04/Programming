//https://leetcode.com/problems/count-submatrices-with-all-ones/submissions/
static void precompute(vector<vector<int>> &temp,vector<vector<int>> &mat){
    int n = temp.size();
    int m = temp[0].size();
    for(int i=0;i<n;i++){
        for(int j=m-1;j>=0;j--){
            if(j==m-1){
                temp[i][j] = mat[i][j];
            }
            else{
                if(mat[i][j]==1){
                    temp[i][j] = temp[i][j+1] + mat[i][j];
                }
                else{
                    temp[i][j] = 0;
                }
            }
        }
    }
}
class Solution {
public:
    
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> temp(n,vector<int>(m,0));
        precompute(temp,mat);
        
        int ans = 0;
        //fixed top left diagonal point of rectangle
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int min_row = INT_MAX;
                for(int k=i;k<n;k++){
                    min_row = min(min_row,temp[k][j]);
                    ans+=min_row;
                }
            }
        }
        return ans;
    }
    
    };