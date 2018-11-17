#include <bits/stdc++.h>
#define MAX 100
using namespace std;
int n,m;
vector<int> x;
vector<vector<int>> G;
//vector<pair<int,int>> set1;
//vector<pair<int,int>> set2;
vector<int> s1;
vector<int> s2;
vector<int> color;

queue<int> q;
bool BFS(int V){
    int y=0;
    q.push(y);
    int p=1;
    color.resize(V,0);
    color[y]=p;
    
    vector<int> visited(V,-1);
    bool flag=true;
    while(!q.empty()){
        int x;
        x=q.front();
        visited[x]=1;
        if(color[x]==1)
            p=2;
        else if(color[x]==2)
            p=1;
        
        for(int i=0;i<V;i++){
            if(G[x][i]==1)
                {   
                if(visited[i]==-1){
                    q.push(i);
                    color[i]=p;
                   }
                else{
                    if(color[i]==color[x]){
                        flag=false;
                        break;
                    }
                }
                }
        }
        
        q.pop();
        if(!flag)
            break;
    }
    return flag;
  
    
}
int main(){
    //int n,m;
    cin>>n;
    G.resize(n+1,vector<int>(n+1));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin >> G[i][j];
        }
    }
    int k=0;
    x.resize(n+1,0);
    if(BFS(n)){
        cout<<"Can be bipartite"<<endl;
    }
    else{
        cout<<"Cannot be bipartite"<<endl;
    }
    cout<<"color1:"<<endl;
    for(int i=0;i<s1.size();i++)
        cout<<s1[i]<<" ";
    cout<<endl<<"======================================="<<endl;
        cout<<"color2:"<<endl;
    for(int i=0;i<s2.size();i++)
        cout<<s2[i]<<" ";
    cout<<endl<<"======================================="<<endl;
    /*graphcolor(0);
    for(int i=0;i<n;i++){
        cout<<"node "<<i<<" colored:"<<x[i]<<endl;
    }*/
   
    return 0;
}

