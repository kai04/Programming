#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
/*#include <jsoncpp/json/json.h>


You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s.


Input: grid = [[1,0],[0,1]]
Output: 3

cnt = 3
{1:2,2:5,3:9}
dfs(x,y)

[1 1 1]
[0 0 0]
[2 2 2]
[0 2 2]
[0 0 0]
[3 3 3]
[3 3 3]
[3 3 3]

res =2
[1 1 0]
[0 0 0]
[2 2 2]
[0 2 2]
[0 0 0]
[3 3 3]
[3 3 3]
[3 3 3]

Input: grid = [[1,1],[1,0]]
Output: 4

Input: grid = [[1,1],[1,1]]
Output: 4

*/
vector<int> x_dir = {-1,1,0,0};
vector<int> y_dir = {0,0,1,-1};
unordered_map<int, int> island_len;
int cnt;
int dfs(int x,int y,vector<vector<int>> &grid){
  int n = grid.size();
  int m = grid[0].size();
  int ret = 0;
  for(int i=0;i<4;i++){
    int x1 = x + x_dir[i];
    int y1 = y + y_dir[i];
    if(x1>=0 &&y1>=0 &&x1<n && y1<m && grid[x1][y1]==1){
      grid[x1][y1] = cnt;
      ret += (1 + dfs(x1,y1,grid));
    }
  }
  return ret;
}

int dfs_new(int x,int y,vector<vector<int>> &grid, vector<bool> &visited){
  int n = grid.size();
  int m = grid[0].size();
  int ret = 0;
  int t = grid[x][y]; 
  grid[x][y]=cnt;
  for(int i=0;i<4;i++){
    int x1 = x + x_dir[i];
    int y1 = y + y_dir[i];
    if(x1>=0 &&y1>=0 &&  x1<n && y1<m && grid[x1][y1]!=0 && grid[x1][y1]!=cnt){
      int len = island_len[grid[x1][y1]];
      if(!visited[grid[x1][y1]])
        ret += (len + dfs_new(x1,y1,grid,visited));
      else
        ret += (dfs_new(x1,y1,grid,visited));
      visited[grid[x1][y1]] = true;
      cout<<"x:"<<x<<" y:"<<y<<" x1:"<<x1<<" y1:"<<y1<<" Island id:"<<grid[x1][y1]<<" Island len:"<<island_len[grid[x1][y1]]<< " return:"<<ret<<endl;
    }
  }
  grd[x][y]=t;
  return ret;
}

int main() {
  int n,m;
  cin>>n>>m;
  cnt = 2;
  vector<vector<int>> grid(n,vector<int>(m));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>grid[i][j];
    }
  }

  int len = 0;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(grid[i][j]==1){
          int ret = dfs(i,j,grid);
          island_len[cnt] = ret;
          cnt++;
        } 
     }
    }
   vector<bool> visited(cnt-1,false);
   for(auto it:island_len)
    cout<<it.first<<" -> "<< it.second<<endl;
   int ans = 0;
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(grid[i][j]==0){
        int res = 1 + dfs_new(i,j,grid,visited);
        visited.resize(cnt-1,false);
        ans = max(ans,res);
      }
    }
    } 
    
    cout<<"ANS:"<<ans<<endl;
  return 0;
}
