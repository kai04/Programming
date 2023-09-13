//https://leetcode.com/problems/all-paths-from-source-to-target/description/
class Solution {
public:
    void dfs(int u, vector<vector<int>>& graph,vector<int> path, vector<vector<int>> &ans){
        int n = graph.size();
        if(u==n-1){
            ans.push_back(path);
            return;
        }
        for(int i=0;i<graph[u].size();i++){
            int v = graph[u][i];
            path.push_back(v);
            dfs(v,graph,path,ans);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;
        path.push_back(0);
        dfs(0,graph,path,ans);
        return ans;
    }
};