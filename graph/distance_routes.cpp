//https://cses.fi/problemset/task/1196
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 10000000000000000LL;

void singleSourceShortestPath(int src, vector<vector<pair<ll,ll>>> &edges,
     vector<vector<ll>> &dist, int k){

    priority_queue<pair<ll,ll>> pq;
    pq.push({0,src});
    dist[src][0] = 0;
    
    while(!pq.empty()){
        ll cost = pq.top().first;
        ll u = pq.top().second;
        pq.pop();
        // if current cost to reach u is greater than kth smallest cost of node u
        if(dist[u][k-1]<cost){continue;}

        //relaxation
        for(int i=0;i<edges[u].size();i++){
            ll v = edges[u][i].first;
            ll wt = edges[u][i].second;
            // if kth smallest cost is greater than cost+ wt
            if(dist[v][k-1]>cost+wt){
                dist[v][k-1] = cost+wt;
                pq.push({dist[v][k-1],v});
                sort(dist[v].begin(), dist[v].end());
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<pair<ll,ll>>> edges(n+1);
    for(int i=0;i<m;i++){
        ll r,s,w;
        cin>>r>>s>>w;
        edges[r].push_back({s,w});
    }
    vector<vector<ll>> dist(n+1, vector<ll>(k, INF));
    singleSourceShortestPath(1,edges,dist,k);

    for(int i=0;i<dist[n].size();i++){
        cout<<dist[n][i]<<" ";
    }
    cout<<endl;
    return 0;
}