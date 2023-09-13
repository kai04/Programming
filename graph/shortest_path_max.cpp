//https://leetcode.com/problems/path-with-minimum-effort/description/
class Solution {
public:
    // [1,1] = {L->[1,0],R->[1,2], U->[0,1], D->[2,1]}
    int dirx[4] = {0,0,-1,1};
    int diry[4] = {-1,1,0,0};
    vector<pair<int,int>> getCells(int i,int j, int n, int m){
        vector<pair<int,int>> res;
        for(int d=0;d<4;d++){
            int ix = i+dirx[d];
            int iy = j+diry[d];
            if(ix>=0 && iy>=0 && ix<n && iy<m){
                res.push_back({ix,iy});
            }
        }
        return res;
    }
    void printSet(set<pair<int,int>> myset){
       cout<<"Printing set...."<<endl;
       cout<<"{";
       for (auto it = myset.begin(); it !=myset.end(); ++it){
           cout <<"["<<it->first<<","<<it->second<<"] ,";
       }
       cout<<"}";
       cout<<endl<<"-------------------------"<<endl;
        

    }

    void dijikstra(int src, vector<vector<pair<int,int>>> &graph, int n, vector<int> &dist, vector<int> &parent){   
        set<pair<int,int>> st;
        dist[src] = 0;
        st.insert({0,src});
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        while(!st.empty()){
            auto it = *(st.begin());
            int dis = it.first;
            int u = it.second;
            // printSet(st);
            st.erase(st.begin());
            for(int i=0;i<graph[u].size();i++){
                pair<int,int> p1 = graph[u][i];
                int v = p1.first;
                int edgW = p1.second;
                // LOGIC:
                // new_dist[v] = max(dist[u], weight[u][v])
                int new_cost = max(dis, edgW);
                if(new_cost<dist[v]){
                    dist[v] = new_cost;
                    st.insert({dist[v], v});
                }
                // if(dis + edgW < dist[v]) {
                //     if(dist[v] != 1e6) 
                //         st.erase({dist[v], v}); 
                //     parent[v] = u;
                //     dist[v] = dis + edgW; 
                //     st.insert({dist[v], v}); 
                // }
                
            }
        }

    }
    void printMapping(int n, unordered_map<int,pair<int,int>> &node){
        cout<<"Printing node mapping..."<<endl;
        for(int i=0;i<n;i++){
            cout<<"["<<i<<"] ->  i:"<<node[i].first<<", j:"<<node[i].second<<endl;
        }

        cout<<"-----------------------"<<endl;
    }
    int printPath(int n, vector<int> &parent, unordered_map<string,int> &weight){
        int u = n;
        int v;
        int ans = -1;
        vector<int> path;
        while(u!=parent[u]){
            int temp = u;
            u = parent[u];
            v = temp;
            path.push_back(v);
            string key = to_string(u)+":"+to_string(v);
            ans = max(ans, weight[key]);
        }
        path.push_back(u);
        reverse(path.begin(),path.end());
        cout<<"Printing shortest path...."<<endl;
        for(auto it:path){
            cout<<it<<" ";
        }
        cout<<endl<<"-------------------------------"<<endl;

        return ans;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        unordered_map<int,pair<int,int>> node;
        unordered_map<string,int> rev_node;
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                string k = to_string(i)+":"+to_string(j);
                rev_node[k] = cnt;
                node[cnt] = {i,j};
                cnt++;
            }
        }
        vector<vector<pair<int,int>>> graph(cnt+1);
        unordered_map<string,int> weight;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                string k1 = to_string(i)+":"+to_string(j);
                int u = rev_node[k1];
                vector<pair<int,int>> vi = getCells(i,j,n,m);
                for(int t=0;t<vi.size();t++){
                    int ix = vi[t].first;
                    int iy = vi[t].second;
                    string k2 = to_string(ix)+":"+to_string(iy);
                    int v = rev_node[k2];
                    int wt = abs(heights[i][j]-heights[ix][iy]);
                    graph[u].push_back({v,wt});
                    string key = to_string(u)+":"+to_string(v);
                    weight[key] = wt;
                }
            }
        }
        vector<int> dist(cnt+1,1e6);
        vector<int> parent(cnt+1);
        dijikstra(0, graph, cnt,dist,parent);
        // printMapping(cnt, node);
        // for(auto it:dist){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        // int ans = printPath(cnt-1, parent, weight);
        
        int ans = dist[cnt-1];
        return ans;

    }
};