//https://codeforces.com/contest/986/problem/A
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e12L +5;

void bfs(int node, 
    unordered_map<int,vector<int>> &mi,
    vector<vector<bool>> visited,
    vector<vector<int>> &dist,
    vector<vector<int>> &graph){
    queue<pair<int,int>> q;
    int n = graph.size();
    
    for(auto it:mi[node]){
        dist[node][it] = 0;
        visited[node][it] = true;
        q.push(make_pair(it,0));
    }
    while(!q.empty()){
        int u = q.front().first;
        int d = q.front().second;
        for(int i=0;i<graph[u].size();i++){
            int v = graph[u][i];
            if(!visited[node][v]){
                dist[node][v] = d+1;
                q.push(make_pair(v,dist[node][v]));
                visited[node][v] = true;
            }
        }
        q.pop();
    }
}

void printDist(vector<vector<int>> &dist){
    cout<<"Printing distances..."<<endl;
    for(int i=1;i<dist.size();i++){
        for(int j=1;j<dist[i].size();j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"----------------------------"<<endl;
}

void printLevelDist(vector<vector<int>> &dist){
    cout<<"Printing Level distances..."<<endl;
    for(int i=1;i<dist.size();i++){
        for(int j=1;j<dist[i].size();j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"----------------------------"<<endl;
}

int main(){
    int n,m,k,s;
    cin>>n>>m>>k>>s;
    vector<int> A(n+1);
    unordered_map<int,vector<int>> mi;
    vector<vector<int>> graph(n+1);
    for(int i=1;i<=n;i++){
        cin>>A[i];
        mi[A[i]].push_back(i);
    }

    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    vector<vector<bool>> visited(k+1, vector<bool>(n+1, false));
    vector<vector<int>> dist(k+1, vector<int>(n+1, 0));
    vector<vector<int>> levels(n+1, vector<int>(k+1, 0));
    for(auto it:mi){
        int x1 = it.first;
        // vector<int> x2 = it.second;
        bfs(x1,mi,visited,dist,graph);
    }
    // printDist(dist);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            levels[i][j] = dist[j][i];
        }
        sort(levels[i].begin(),levels[i].end());
    }

    // printLevelDist(levels);

    for(int i=1;i<=n;i++){
        int sum = 0;
        for(int j=1;j<=s;j++){
            sum = sum + levels[i][j];
            // cout<<"i:"<<i<<" j:"<<j<<" sum:"<<sum<<" levels[i][j]:"<<levels[i][j]<<endl;
        }
        if(i==n){
            cout<<sum;
        } else{
            cout<<sum<<" ";
        }
    }

    return 0;
}
