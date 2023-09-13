//https://www.interviewbit.com/problems/cycle-in-undirected-graph/
#include <bits/stdc++.h>
using namespace std;
bool dfs(int u, vector<int> &parent, vector<int> &color, vector<vector<int> > &graph, int n){
    color[u] = 1;
    // cout<<"U:"<<u<<endl;
    for(int v: graph[u]){
        // cout<<"v:"<<v<<" u:"<<u<<endl;
        if(color[v]==0 && v!=parent[u]){
            parent[v] = u;
            // cout<<"f("<<u<<") calling -> f("<<v<<")"<<endl;
            if(dfs(v,parent,color,graph,n)){
                return true;    
            }
        } else if(color[v]==1 && v!=parent[u]){
            cycle_start = v;
            cycle_end = u;
            return true;
        }
    }
    color[u] = 2;
    return false;
}

void printCycle(int cycle_start, int cycle_end, vector<int> &parent){
    vector<int> cycle;
    cycle.push_back(cycle_start);
    for (int v = cycle_end; v != cycle_start; v = parent[v])
        cycle.push_back(v);
    cycle.push_back(cycle_start);
    reverse(cycle.begin(), cycle.end());

    cout << "Cycle found: ";
    for (int v : cycle)
        cout << v << " ";
    cout<<endl<<"-------------------"<<endl;
}
int solve(int A, vector<vector<int> > &B) {
    vector<int> color(A+1,0);
    vector<int> parent(A+1,-1);
    int m = B.size();
    vector<vector<int>> graph(A+1);
    for(int i=0;i<B.size();i++){
        graph[B[i][0]].push_back(B[i][1]);
        graph[B[i][1]].push_back(B[i][0]);
    }
    cycle_start = -1;
    for(int i=1;i<=A;i++){
        if(color[i]==0){
            bool ret = dfs(i,parent,color,graph,A);
            if(ret){
                printCycle(cycle_start, cycle_end, parent);
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int> > A(m);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        vector<int> z(2);
        z[0] = x;
        z[1] = y;
        A[i]=z;
    }
    int ans = solve(n, A);
    cout<<"ANS:"<<ans<<endl;
    return 0;
}