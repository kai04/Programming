//https://leetcode.com/problems/keys-and-rooms/submissions/
void dfs(int u,vector<vector<int>> &graph,vector<bool> &visited){
    visited[u] = true;
    for(int i=0;i<graph[u].size();i++){
        int v = graph[u][i];
        if(!visited[v]){
            dfs(v,graph,visited);
        }
    }
}
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n  = rooms.size();
        vector<bool> visited(n,false);
        dfs(0,rooms,visited);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                return false;
            }
        }
        return true;
    }
};