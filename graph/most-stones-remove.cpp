//https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/submissions/
static void dfs(int u,vector<int> &visited,vector<vector<int>> &graph,int &cnt){
    visited[u] = 1;
    for(int j=0;j<graph[u].size();j++){
        int v = graph[u][j];
        if(visited[v]==0){
            cnt++;
            dfs(v,visited,graph,cnt);
        }
    }
}
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = 0;
        map<pair<int,int>,int> m;
        for(int i=0;i<stones.size();i++){
            n = max(n,stones[i][0]);
            n = max(n,stones[i][1]);
            m[make_pair(stones[i][0],stones[i][1])] = i;
        }
        vector<vector<int>> xpt(n+1);
        vector<vector<int>> ypt(n+1);
        vector<vector<int>> graph(stones.size());
        for(int i=0;i<stones.size();i++){
            xpt[stones[i][0]].push_back(i);
            ypt[stones[i][1]].push_back(i);
        }
        
        for(int i=0;i<xpt.size();i++){
            for(int j=0;j<xpt[i].size();j++){
                for(int k=j+1;k<xpt[i].size();k++){
                    graph[xpt[i][j]].push_back(xpt[i][k]);
                    graph[xpt[i][k]].push_back(xpt[i][j]);
                }
            }
        }
        
        for(int i=0;i<ypt.size();i++){
            for(int j=0;j<ypt[i].size();j++){
                for(int k=j+1;k<ypt[i].size();k++){
                    graph[ypt[i][j]].push_back(ypt[i][k]);
                    graph[ypt[i][k]].push_back(ypt[i][j]);
                }
            }
        }
        
        /*for(auto it:m){
            cout<<"["<<it.second<<"]:"<<it.first.first<<","<<it.first.second<<endl;
        }
        for(int i=0;i<graph.size();i++){
            cout<<i<<"-> ";
            for(int j=0;j<graph[i].size();j++){
                cout<<graph[i][j]<<" ";
            }
            cout<<endl;
        }*/
        vector<int> visited(stones.size(),0);
        int maxCnt = 0;
        for(int i=0;i<stones.size();i++){
            if(visited[i]==0){
                int curr_cnt = 0;
                dfs(i,visited,graph,curr_cnt);
                maxCnt += curr_cnt;
            }
        }
        return (maxCnt);
    }
};
