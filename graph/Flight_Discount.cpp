//https://cses.fi/problemset/task/1195
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 10000000000000000LL;

void singleSourceShortestPath(int src, vector<vector<pair<ll,ll>>> &edges, vector<vector<ll>> &dist){
    priority_queue<pair<ll,pair<ll,ll>>> pq;
    pq.push({0,make_pair(src,0)});
    dist[src][0] = 0;
    dist[src][1] = 0;
    while(!pq.empty()){
        ll cost = pq.top().first;
        pair<ll,ll> p = pq.top().second;
        pq.pop();
        ll v =  p.first;
        ll flag = p.second; 
        //relaxation
        for(int i=0;i<edges[v].size();i++){
            ll u = edges[v][i].first;
            ll wt = edges[v][i].second;
            if(flag==1){
                if(dist[u][1]> (dist[v][0]+wt)){
                    dist[u][1] = dist[v][0]+wt;
                    pq.push({dist[u][1],make_pair(u,1)});
                }
                if(dist[u][1]> (dist[v][1]+wt)){
                    dist[u][1] = dist[v][1]+wt;
                    pq.push({dist[u][1],make_pair(u,1)});
                }
            } else{
                if(dist[u][1]> (dist[v][0]+wt/2)){
                    dist[u][1] = dist[v][0]+wt/2;
                    pq.push({dist[u][1],make_pair(u,1)});
                }

                if(dist[u][1]> (dist[v][1]+wt)){
                    dist[u][1] = dist[v][1]+wt;
                    pq.push({dist[u][1],make_pair(u,1)});
                }

                if(dist[u][0]> (dist[v][0]+wt)){
                    dist[u][0] = dist[v][0]+wt;
                    pq.push({dist[u][0],make_pair(u,0)});
                }
            }

                
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>> edges(n+1);
    for(int i=0;i<m;i++){
        ll r,s,w;
        cin>>r>>s>>w;
        edges[r].push_back({s,w});
    }
    vector<vector<ll>> dist(n+1, vector<ll>(2, INF));
    singleSourceShortestPath(1,edges,dist);
    cout<<dist[n][1]<<endl;
    // for(int i=1;i<dist.size();i++){
    //     cout<<"("<<dist[i][0]<<","<<dist[i][1]<<")"<<endl;
    // }
    // cout<<endl;
    return 0;
}