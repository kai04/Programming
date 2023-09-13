//https://leetcode.com/problems/number-of-operations-to-make-network-connected/
class Solution {
public:
    vector<int> sizes;
    vector<int> parent;
    vector<int> edges;

    void make_set(int v){
        parent[v] = v;
        sizes[v] = 1;
        edges[v] = 0;
    }

    int find_set(int v){
        if(parent[v]==v){
            return v;
        }
        return parent[v] = find_set(parent[v]);
    }

    void union_set(int u, int v){
        int p_u = find_set(u);
        int p_v = find_set(v);
        
        // cout<<"Before Union of U:"<<u<<" V:"<<v<<" Parent[U]:"<<parent[p_u]<<" Parent[V]:"<<parent[p_v]<<" Size[P_U]:"<<sizes[p_u]<<" Size[P_v]:"<<sizes[p_v]<<" edges[p_u]:"<<edges[p_u]<<" edges[p_v]:"<<edges[p_v]<<endl;
        if(p_u==p_v){
            edges[p_v]++;
        } else if(sizes[p_u] < sizes[p_v]){
            parent[p_u] = p_v;
            edges[p_v] += edges[p_u];
            sizes[p_v] += sizes[p_u];
            edges[p_v]++;
        } else if(sizes[p_u] > sizes[p_v]){
            parent[p_v] = p_u;
            edges[p_u] += edges[p_v];
            sizes[p_u] += sizes[p_v];
            edges[p_u]++;
        } else{
            parent[p_u] = p_v;
            edges[p_v] += edges[p_u];
            sizes[p_v] += sizes[p_u];
            edges[p_v]++;
        }
        // cout<<"After Union of U:"<<u<<" V:"<<v<<" Parent[U]:"<<parent[p_u]<<" Parent[V]:"<<parent[p_v]<<" Size[P_U]:"<<sizes[p_u]<<" Size[P_v]:"<<sizes[p_v]<<" edges[p_u]:"<<edges[p_u]<<" edges[p_v]:"<<edges[p_v]<<endl;
        // cout<<"-------------------------------"<<endl;
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        sizes.resize(n);
        edges.resize(n);
        parent.resize(n);
        for(int i=0;i<n;i++){
            make_set(i);
        }
        for(int i=0;i<m;i++){
            union_set(connections[i][0], connections[i][1]);
        }
        int extra_edges = 0;
        int conn = 0;
        for(int i=0;i<n;i++){
            int par = find_set(i);
            // cout<<" Node:"<<i<< " Parent:"<<par<<" No of edges of parent:"<<edges[par]<<" size of component:"<<sizes[par]<<endl;
            if(par==i){
                int x = edges[par] - (sizes[par]-1);
                if(x>0) extra_edges+=x;
                conn++;
            }
        }
        if(conn-1<=extra_edges){
            return conn-1;
        }
        return -1;
    }
};