#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
    int t;
    cin>>t;
    int k=1;
    while(k<=t){
        int n;
        cin>>n;
        vector<int> R(n);
        vector<int> B(n);
        for(int i=0;i<n;i++){
            cin>>R[i];
        }
        for(int i=0;i<n;i++){
            cin>>B[i];
        }
        vector<pair<int,int>> graph;
        map<pair<int,int>,int> m1;
            map<pair<int,int>,int> m2;
        for(int i=0;i<n;i++){
            graph.push_back(make_pair(R[i],B[i]));
           // m1[make_pair(R[i],B[i])]=i;
            //m2[i]=make_pair(R[i],B[i]);
        }
        int E = n*(n-1)/2;
        int V = n;
        vector<vector<int> > vec(E);
        vector<int> visited(V,-1);
        vector<int> parent(V);
        vector<int> size(V);
        set<pair<int,pair<int, int> > > pr;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x3= min((graph[i].first^graph[j].second),(graph[j].first^graph[i].second));
                //vec.push_back()
                pr.insert(make_pair(x3,make_pair(i,j)));
                pr.insert(make_pair(x3,make_pair(j,i)));
            }
            
        }
        initialize(parent,size,V);
       
        int ans=kruskalMst(vec,V,pr,parent,size);
        cout<<"Case #"<<k<<": "<<ans<<endl;
        k++;
    }
}
