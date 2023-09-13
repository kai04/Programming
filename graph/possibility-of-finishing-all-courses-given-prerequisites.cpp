//https://www.interviewbit.com/problems/cycle-in-directed-graph/
#include <bits/stdc++.h>
using namespace std;
bool dfs(int u, vector<int> &parent, vector<int> &color, vector<vector<int> > &graph, int n, int &cycle_start, int &cycle_end){
    color[u] = 1;
    // cout<<"U:"<<u<<endl;
    for(int v: graph[u]){
        // cout<<"v:"<<v<<" u:"<<u<<endl;
        if(color[v]==0){
            parent[v] = u;
            // cout<<"f("<<u<<") calling -> f("<<v<<")"<<endl;
            if(dfs(v,parent,color,graph,n, cycle_start, cycle_end)){
                return true;    
            }
        } else if(color[v]==1){
            cout<<"V:"<<v<<" U:"<<u<<endl;
            cycle_start = v;
            cycle_end = u;
            return true;
        }
    }
    color[u] = 2;
    return false;
}
void printGraph(vector<vector<int>> &graph){
    cout<<"Printing ...."<<" Size:"<<graph.size()<<endl;
    for(int i=0;i<graph.size();i++){
        cout<<"["<<i<<"] -> {";
        for(int j=0;j<graph[i].size();j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<" }"<<endl;
    }
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

int solve(int A, vector<int> &B, vector<int> &C) {
    int n = B.size();
    vector<vector<int>> graph(A+1);
    for(int i=0;i<n;i++){
        graph[B[i]].push_back(C[i]);
    }
    // printGraph(graph);
    // vector<bool> visited(n+1,false);
    vector<int> color(n+1,0);
    vector<int> parents(n+1,-1);
    int cycle_start=-1, cycle_end=-1;
   for(int i=1;i<=A;i++){
       if(color[i]==0){
           bool ret = dfs(i, parents, color,graph, A,cycle_start, cycle_end);
           if(ret){
                // printCycle(cycle_start, cycle_end, parents);
               return 0;
           }
       }
   }
   return 1;
}


int main(){
    int A,m;
    cin>>A>>m;
    vector<int> B(m);
    vector<int> C(m);
    for(int i=0;i<m;i++){
        cin>>B[i];
    }
    for(int i=0;i<m;i++){
        cin>>C[i];
    }

    int ans = solve(A, B, C);
    cout<<"ANS:"<<ans<<endl;
    return 0;
}