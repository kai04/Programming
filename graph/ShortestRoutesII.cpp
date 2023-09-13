//https://cses.fi/problemset/task/1672
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9+7;

void floyd_warshal(int n, vector<vector<ll>> &edges, vector<vector<ll>> &dist){
    dist.resize(n+1, vector<ll>(n+1, INF));
    for(int i=1;i<=n;i++){
        dist[i][i] = 0;
    }
    for(int i=0;i<edges.size();i++){
        dist[edges[i][0]][edges[i][1]] = edges[i][2];
        dist[edges[i][1]][edges[i][0]] = edges[i][2];
    }
    for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
    }   
}

int main(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<ll>> edges(m, vector<ll>(3));
    for(int i=0;i<m;i++){
        cin>>edges[i][0]>>edges[i][1]>>edges[i][2];
    }
    vector<vector<ll>> dist;
    floyd_warshal(n,edges,dist);
    for(int i=0;i<q;i++){
        int r,s;
        cin>>r>>s;
        if(dist[r][s]>=INF){
            cout<<-1<<endl;
        } else{
            cout<<dist[r][s]<<endl;
        }
    }

    return 0;
}