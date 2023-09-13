//https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance
const int INF = 1e7;
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INF));
        for(int i=0;i<n;i++){
            dist[i][i] = 0;
        }
        for(int i=0;i<edges.size();i++){
            dist[edges[i][0]][edges[i][1]] = edges[i][2];
            dist[edges[i][1]][edges[i][0]] = edges[i][2];
        }
        vector<set<int>> reach(n);
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                    if(i!=j && dist[i][j]<=distanceThreshold){
                        reach[i].insert(j);
                    }
                }
            }
        }
        int ans = -1;
        int smallReach = n;
        for(int i=0;i<n;i++){
            if(reach[i].size()<=smallReach){
                smallReach = reach[i].size();
                ans = i;
            }
        }
        return ans;
    }
};