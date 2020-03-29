#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
/* Initailly all nodes are root node viz. parent of itself,also size of each equivalence class is 1 */
void initialize(vector<int> &Parent,vector<int> &size, int N)
{
    for(int i = 0;i<N;i++)
    {
    Parent[ i ] = i ;
    size[ i ] = 1;
    }
}
bool find(vector<int> &Parent, int A, int B)                           
{
if(Parent[ A ] == Parent[ B ])
return true;
else
return false;   
}
/* Here i is node whose root are search recursively because parent can be intermediate node 
that is why Parent[ Parent[ i ] ],Note root is node who is parent of itself i.e parent[i]=i*/
int root(vector<int> &Parent ,int i)
{
    while(Parent[ i ] != i)
    {
    Parent[ i ] = Parent[ Parent[ i ] ] ; 
    i = Parent[ i ]; 
    }
return i;
}
/* First root of each node is found because root denote represent each equavalence class ,
then equavalence class with smaller size is merge into bigger equavalence class and 
size of of bigger is increase by factor of smaller equavalence size*/
void weighted_union(vector<int> &Parent,vector<int> &size,int A,int B)
{
    int root_A = root(Parent,A);
    int root_B = root(Parent,B);
    if(size[root_A] < size[root_B ])
    {
        Parent[ root_A ] = Parent[root_B];
        size[root_B] += size[root_A];
    }
    else
    {
        Parent[ root_B ] = Parent[root_A];
        size[root_A] += size[root_B];
    }

}

int kruskalMst(vector<vector<int>> &vec,int n,set<pair<int,pair<int, int> > > &pr,vector<int> &parent,vector<int> &size){
    vector<pair<int,int>> sol(0);
    int edgecount =0;
    int ret =0;
    for(auto it = pr.begin();it!=pr.end();it++){
       //cout<<"weight:"<<(*it).first<<" edge: ("<<((*it).second).first<<" -> "<<((*it).second).second<<" )"<<endl;
        int w = (*it).first;
        int u =(((*it).second).first);
        int v =(((*it).second).second);
          if(!find(parent,u,v)){
              weighted_union(parent,size,u,v);
              ret+=w;
              edgecount++;
              sol.push_back(make_pair(u,v));
          }
            if(edgecount==n-1){
                break;
            }
    }
    
    /*for(auto it:sol){
        cout<<"("<<it.first<<" , "<<it.second<<")"<<endl;
    }
    
     for(int i = 0;i<n;i++)
    {
    cout<<"i:"<<i<<" -> "<<parent[i]<<endl;
    }*/
    
 return ret;   
}

int main() {
   	int E,V,x1,x2,x3;
	 
//cout<<"Enter the no of Edges and vertices:"<<endl;
cin>>V>>E;
vector<vector<int> > vec(E);
vector<int> visited(V,-1);
vector<int> parent(V);
vector<int> size(V);
    
set<pair<int,pair<int, int> > > pr;
for(int i=0;i<E;i++)
{
	//cout<<"Enter Edges 1->2:"<<endl;
	cin>>x1>>x2>>x3;
     pr.insert(make_pair(x3,make_pair(x1-1,x2-1)));
	//vec[x1].push_back(x2);
	//comment below if undirected graph
	//vec[x2].push_back(x1);
}
    initialize(parent,size,V);
       
    cout<<kruskalMst(vec,V,pr,parent,size)<<endl;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

