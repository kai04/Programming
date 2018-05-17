//https://www.geeksforgeeks.org/backttracking-set-5-m-coloring-problem/

/*
11 16 3
1 2
1 8
2 4
3 4
4 9
4 11
5 11
5 6
6 7
7 8
7 11
8 9
8 10
8 11
9 10
10 11

*/

#include <bits/stdc++.h>
using namespace std;

/*
Function to check if color c can be assigned to node v or not
*/
bool isSafe(int v,int c,vector<vector<int>> graph,vector<int> &Nodecolor){
    for(int i=0;i<graph[v].size();i++){
     if(Nodecolor[graph[v][i]]==c){
         return false;
     }   
    }
    return true;
}
/*
return true if curr node can be colored by any of k color otherwise return false
*/
bool graphColoringUtils(int curr,vector<vector<int>> graph,vector<int> &Nodecolor,int n,int k){
    if(curr==(n+1)){
        for(int i=1;i<=n;i++){
            cout<<"Node "<<i<<" is colored c"<<Nodecolor[i]<<endl;
        }
        return true;
    }
    //for all color check if curr node can be colored with color and then backtrack
    for(int color=1;color<=k;color++){
        if(isSafe(curr,color,graph,Nodecolor)){
            //choose
            Nodecolor[curr]=color;
            //explore
            if(graphColoringUtils(curr+1,graph,Nodecolor,n,k)==true){
                return true;
            }
            //unchoose
            Nodecolor[curr]=-1;
        }
    }
    return false;
}
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    //node index from 1 to n
    // color index from 1 to k
    vector<vector<int>> graph(n+1);
    vector<int> Nodecolor(n+1,-1);
    for(int i=0;i<m;i++){
        // cout<<"i:"<<i<<endl;
        int x,y;
        cin>>x>>y;
        //undirected
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    
    //first node is assigned color c1
    Nodecolor[1]=1;
    bool flag=graphColoringUtils(2,graph,Nodecolor,n,k);
    if(flag==false){
        cout<<k<<" coloring of given graph not possible"<<endl;
    }
    return 0;
}
