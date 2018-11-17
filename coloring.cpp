#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> x;
vector<vector<int>> G;
bool isSafe(int k,int c){
    bool flag=true;
    for(int i=0;i<n;i++){
        if(G[k][i]==1 && x[i]==c){
            flag=false;
            break;
        }
    }
    return flag;
}
void graphcolor(int k){
	//for all edges
    for(int c=1;c<=m;c++){
        if(isSafe(k,c)){
            x[k]=c;
            if(k<n){
                graphcolor(k+1);
            }
            else{
                return;
            }
        }
    }
}
int main(){
    //int n,m;
    //n nodes m edges
    cin>>n>>m;
    G.resize(n+1,vector<int>(n+1));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin >> G[i][j];
        }
    }
    int k=0;
    x.resize(n+1,0);
    graphcolor(0);
    for(int i=0;i<n;i++){
        cout<<"node "<<i<<" colored:"<<x[i]<<endl;
    }
    return 0;
}
