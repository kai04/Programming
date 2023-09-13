//https://cses.fi/problemset/task/1680
#include<bits/stdc++.h>
#define PLL pair<ll, ll>
using namespace std;
typedef long long ll;
const ll INF = 10000000000000000LL;

class Compare {
public:
    bool operator()(PLL p1, PLL p2)
    {
        if(p1.first<p2.first){
            return true;
        }
        return false;
    }
};

void printPQ(priority_queue<PLL, vector<PLL>, Compare> pq){
    cout<<"Printing priority queue...."<<endl;
    while(!pq.empty()){
        cout<<"("<<pq.top().first<<","<<pq.top().second<<") ";
        pq.pop();
    }
    cout<<endl<<"--------------------------"<<endl;
}

void singleSourceShortestPath(int src, vector<vector<ll>> &edges,
     vector<ll> &dist, vector<ll> &parent){

    priority_queue<PLL, vector<PLL>, Compare> pq;
    pq.push({1,src});
    dist[src] = 1;
    parent[src] = src;
    
    while(!pq.empty()){
        ll cost = pq.top().first;
        ll u = pq.top().second;
        // printPQ(pq);
        pq.pop();

        //relaxation
        for(int i=0;i<edges[u].size();i++){
            ll v = edges[u][i];
            if((cost+1)>dist[v]){
                dist[v] = max(dist[v],cost+1);
                pq.push({dist[v],v});
                parent[v] = u;    
            }
        }
    }
}

void printParent(vector<ll> &parent, int u){
    int v = u;
    vector<ll> path;
    while(v!=parent[v]){
        // cout<<v<<" ";
        path.push_back(v);
        v = parent[v];
    }
    path.push_back(v);
    reverse(path.begin(),path.end());
    for(ll x:path){
        cout<<x<<" ";
    }    
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<vector<ll>> edges(n+1);
    for(int i=0;i<m;i++){
        ll r,s;
        cin>>r>>s;
        edges[r].push_back(s);
    }
    vector<ll> parent(n+1);
    for(int i=0;i<parent.size();i++){
        parent[i] = i;
    }
    vector<ll> dist(n+1, 1);
    singleSourceShortestPath(1,edges,dist,parent);
    if(dist[n]==1){
        cout<<"IMPOSSIBLE"<<endl;
    } else{
        cout<<dist[n]<<endl;
        printParent(parent, n);    
    }
    

    return 0;
}