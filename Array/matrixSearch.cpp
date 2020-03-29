//https://leetcode.com/problems/search-a-2d-matrix-ii/submissions/
class Solution {
public:
    bool bfs(int i,int j,int n,int m,vector<vector<int>>& matrix, int target){
        if(i<0 || i>=n || j<0 || j>=m){
        
            return false;
        }
        if(matrix[i][j]==target){
            return true;
        }
        else if(matrix[i][j] < target){
            return bfs(i+1,j,n,m,matrix,target);
        }
        else if(matrix[i][j] > target){
            return bfs(i,j-1,n,m,matrix,target);
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n =matrix.size();
        if(n==0)
            return false;
        int m = matrix[0].size();
        bool ans = bfs(0,m-1,n,m,matrix,target);
        return ans;
    }
};
