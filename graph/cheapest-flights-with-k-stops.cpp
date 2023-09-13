//https://leetcode.com/problems/cheapest-flights-within-k-stops/description/
class Solution {
public:
    void bellman_ford(int src, vector<vector<int>> &flights, int k, vector<int> &dist){
        dist[src] = 0;
        for(int i=1;i<=k+1;i++){
            vector<int> temp =  dist;
            for(auto edge:flights){
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                if(dist[v]> dist[u]+wt){
                    temp[v] = min(dist[u]+wt, temp[v]);
                }
            }
            dist = temp;
        }
    }
    void printDist(vector<int> &dist){
        cout<<"Printing destination ...."<<endl;
        // for(auto it1:dist){
            for(auto it2:dist){
                cout<<it2<<" ";
            }
            // cout<<endl;
        // }
        cout<<endl<<"-----------------------------"<<endl;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n+1,1e9);
        bellman_ford(src,flights,k,dist);
        // printDist(dist);
        int ans = dist[dst];
        if(ans==1e9){
            return -1;
        }
        return ans;
    }
};