//https://cses.fi/problemset/task/1671
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e16+7;

void singleSourceShortestPath(int src, vector<vector<pair<ll,ll>>> &edges, vector<ll> &dist){
    priority_queue<pair<ll,ll>> pq;
    pq.push({0,src});
    dist[src] = 0;
    while(!pq.empty()){
        // int wt = pq.top().first;
        int v = pq.top().second;
        pq.pop();
        //relaxation
        for(int i=0;i<edges[v].size();i++){
            ll u = edges[v][i].first;
            ll wt = edges[v][i].second;
            if(dist[u]> dist[v]+wt){
                dist[u] = dist[v]+wt;
                pq.push({dist[u],u});
            }    
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>> edges(n+1);
    for(int i=0;i<m;i++){
        ll r,s,w;
        cin>>r>>s>>w;
        edges[r].push_back({s,w});
    }
    vector<ll> dist(n+1, INF);
    singleSourceShortestPath(1,edges,dist);
    for(int i=1;i<dist.size();i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
    // return 0;
}