//https://leetcode.com/problems/redundant-connection/submissions/
/* 
    color = {
            0 - white
            1 - gray
            2 - black
        }
*/
static void dfs(int u,vector<int> &color,vector<int> &parent,set<pair<int,int>> &cycle,vector<vector<int>> &graph)
{
    
    for(int i=0;i<graph[u].size();i++){
        int v = graph[u][i];
        if(color[v]==0 && parent[u]!=v){
            color[v] = 1;
            parent[v] = u;
            dfs(v,color,parent,cycle,graph);
        }
        else if(color[v]==1 && parent[v]!=u && parent[u]!=v){
            //cycle found from u-v
            int t = u;
            cycle.insert(make_pair(u,v));
            
            while(t!=-1 && (parent[t]!=-1) && t!=v){
                cycle.insert(make_pair(t,parent[t]));
                t=parent[t];
            }
            break;
        }
    }
    color[u] = 2;
}


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = 0;
        
        for(int i=0;i<edges.size();i++){
            n = max(n,edges[i][0]);
            n = max(n,edges[i][1]);
        }
        vector<vector<int>> graph(n+1);
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> color(n+1,0);
        vector<int> parent(n+1,-1);
        set<pair<int,int>> cycle;
        color[1] = 1;
        dfs(1,color,parent,cycle,graph);
        vector<int> ans(2);
        cerr<<"h2:"<<endl;
        /*cout<<"Cycle ...."<<endl;
        for(auto it:cycle)
            cout<<it.first<<","<<it.second<<endl;*/
        for(int i=edges.size()-1;i>=0;i--){
            if(cycle.find(make_pair(edges[i][0],edges[i][1]))!=cycle.end() ||
              (cycle.find(make_pair(edges[i][1],edges[i][0]))!=cycle.end())){
                ans = edges[i];
                break;
            }
            
        }
        return ans;
    }
};