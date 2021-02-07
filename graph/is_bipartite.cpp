//https://leetcode.com/problems/is-graph-bipartite/submissions/
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<pair<int,int>> q;
        vector<int> color(n+1,-1);
        vector<int> parent(n+1,-1);
        bool is_bipartite = true;
        for(int i=0;i<n;i++){
            while(!q.empty())
                q.pop();
            if(graph[i].size()==0 || color[i]!=-1)
                continue;
                int src = i;
            q.push(make_pair(src,0));
            parent[src] = -1;
            color[src] = 0;
            while(!q.empty()){
                pair<int,int> p = q.front();
                q.pop();
                int node = p.first;
                int curr_color = p.second;
                for(int i=0;i<graph[node].size();i++){
                    int node_v = graph[node][i];
                    int new_color = !curr_color;
                    // cout<<"Node U:"<<node<<" U_node_color:"<<color[node_v]<<" Node V:"<<node_v<<" V_node_color:"<<color[node_v]<<" parent[V]:"<<parent[node_v]<<endl;
                    if(color[node_v]==-1){
                        q.push(make_pair(node_v,new_color));
                        parent[node_v]=node;
                        color[node_v] = new_color;
                    }
                    else if(color[node_v]==color[node]){
                        is_bipartite = false;
                        break;
                    }
                }
                if(!is_bipartite)
                    break;
            }
        }
        return is_bipartite;
    }
};