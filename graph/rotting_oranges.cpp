//https://leetcode.com/problems/rotting-oranges/submissions/
int x[4] = {-1,0,1,0};
int y[4] = {0,-1,0,1};

static bool isvalid(int x,int y,int n, int m){
    if(x<0 || x>=n || y<0 || y>=m)
        return false;
    return true;
}
static int bfs(vector<vector<int>>& grid){
    queue<pair<int,pair<int,int>>> q;
    int n = grid.size();
    int m = grid[0].size();
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[i].size();j++){
            if(grid[i][j]==2){
                q.push(make_pair(0,make_pair(i,j)));
            }
        }
    }
    int ans = 0;
    while(!q.empty()){
        pair<int,pair<int,int>> p = q.front();
        q.pop();
        pair<int,int> p1 = p.second;
        int t = p.first;
        ans = max(ans,t);
        int i = p1.first;
        int j = p1.second;
        for(int d=0;d<4;d++){
            if(isvalid(i+x[d],j+y[d],n,m) && grid[i+x[d]][j+y[d]]==1){
                q.push(make_pair(t+1,make_pair(i+x[d],j+y[d])));
                grid[i+x[d]][j+y[d]] = 2;
            }
        }
    }
    return ans;
}
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = bfs(grid);
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    return -1;
                }        
            }
        }
        return ans;
    }
};