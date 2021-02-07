//https://leetcode.com/problems/network-delay-time/submissions/
#define INF 1e6


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int> dist(N+1,INF);
        dist[K] = 0;
        for(int i=0;i<N-1;i++){
            for(int j=0;j<times.size();j++){
                int u = times[j][0];
                int v = times[j][1];
                int w = times[j][2];
                if(dist[v]>dist[u]+w){
                    dist[v] = dist[u]+w;
                }
            }
        }
        int ans = 0;
        for(int i=1;i<=N;i++){
            ans = max(ans,dist[i]);
        }
        if(ans==INF)
                return -1;
        return ans;
    }
};