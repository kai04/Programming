//https://leetcode.com/problems/min-cost-to-connect-all-points/submissions/
class Solution {
public:
    int minimum_spanning_tree(int n, vector<vector<pair<int,int>>> &adj){
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int sum=0;
        vector<int> visited(n,0);
        // cout<<"N:"<<n<<endl;
        pq.push({0,0});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int wt = it.first;
            // cout<<"node:"<<node<<" weight:"<<wt<<" sum:"<<sum<<" pq size:"<<pq.size()<<endl;
            if(visited[node]==1){
                continue;
            }
            visited[node] = 1;
            sum = sum + wt;
            for(int i=0;i<adj[node].size();i++){
                int v = adj[node][i].first;
                int weight = adj[node][i].second;
                if(v!=node && visited[v]==0){
                    // cout<<"adding node:"<<v<<" wt:"<<weight<<endl;
                    pq.push({weight,v});
                }
            }
            
        }
        return sum;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int wt = abs(points[j][0]-points[i][0])+abs(points[j][1]-points[i][1]);
                adj[i].push_back({j,wt});
                adj[j].push_back({i,wt});
            }
        }
        int ans = minimum_spanning_tree(n,adj);
        return ans;
    }
};