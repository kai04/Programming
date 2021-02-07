//https://leetcode.com/problems/rotate-image/
class Solution {
public:
    void print_mat(vector<vector<int>>& A) {
        int  n = A.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<A[i][j]<<" "; 
            }
            cout<<endl;
        }
        cout<<"---------------------------"<<endl;
    }
    
    void cut_horizonal_middle(vector<vector<int>>& A) {
        int  n = A.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n/2;j++){
                int temp = A[i][j];
                A[i][j] = A[i][n-1-j];
                A[i][n-1-j] = temp;
            }
        }
    }
    
    void cut_right_diagonal(vector<vector<int>>& A) {
        int  n = A.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n-1-i;j++){
                int temp = A[i][j];
                A[i][j] = A[n-1-j][n-1-i];
                A[n-1-j][n-1-i] = temp;
            }
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        cut_horizonal_middle(matrix);
        cut_right_diagonal(matrix);
    }
};
