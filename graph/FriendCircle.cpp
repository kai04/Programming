//https://leetcode.com/explore/interview/card/top-interview-questions-hard/118/trees-and-graphs/846/
class Solution {
public:
    void dfs(int u,vector<bool> &visited,vector<vector<int>> &graph){
        int n = visited.size();
        for(int j = 0;j<n;j++){
            int v = graph[u][j];
            if(v && !visited[j]){
                visited[j] = true;
                dfs(j,visited,graph);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        int cnt = 0;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                visited[i] = true;
                dfs(i,visited,M);
                cnt++;
            }
        }
        return cnt;
    }
};
