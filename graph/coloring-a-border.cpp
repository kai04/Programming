//https://leetcode.com/problems/coloring-a-border/submissions/
class Solution {
public:
    // (1,1) => {(0,1)(1,0)(1,2)(2,1)}
    int dirx[4] = {-1,0,0,1};
    int diry[4] = {0,-1,1,0};

    bool isAdjacent(int i,int j,int n, int m, vector<vector<int>>& grid, int c1){
        //border
        if(i==0 || j==0 || i==n-1 || j==m-1){
            return true;
        }
        for(int d=0;d<4;d++){
            int dx = i+dirx[d];
            int dy = j+diry[d];
            if(grid[dx][dy]>=0 && grid[dx][dy]!=c1){
                return true;
            }
        }
        return false;
    }
    bool isValid(int x,int y, int n, int m){
        if(x<0||y<0||x>=n||y>=m){
            return false;
        }
        return true;
    }

    void dfs(int i, int j, int c1,vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        bool adj = isAdjacent(i,j,n,m,grid,c1);
        // cout<<"i:"<<i<<" j:"<<j<<" adj:"<<adj<<endl;
        if(adj){
            grid[i][j] = -1001;
        } else {
            grid[i][j] *= -1;
        }
        for(int d=0;d<4;d++){
            int dx = i+dirx[d];
            int dy = j+diry[d];
            if(isValid(dx,dy,n,m)){
                if(grid[dx][dy]==c1){
                    // cout<<"i:"<<i<<" j:"<<j<<" adj:"<<adj<<" dx:"<<dx<<" dy:"<<dy<<" grid[i][j]:"<<grid[i][j]<<endl;
                    dfs(dx, dy,c1,grid);
                }
            }
        }
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int n = grid.size();
        int m = grid[0].size();

        dfs(row,col,grid[row][col],grid);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]<0){
                    if(grid[i][j]==-1001){
                        grid[i][j] = color;
                    } else{
                        grid[i][j] *= -1;
                    }
                }
            }
        }

        return grid;
    }
};