#include <cmath>
#include <cstdio>
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
void initialize(vector<int> &Arr,vector<int> &size, int N)
{
    for(int i = 0;i<N;i++)
    {
    Arr[ i ] = i ;
    size[ i ] = 1;
    }
}
bool find(vector<int> &Arr, int A, int B)                           
{
if(Arr[ A ] == Arr[ B ])
return true;
else
return false;   
}

int root(vector<int> &Arr ,int i)
{
    while(Arr[ i ] != i)
    {
    Arr[ i ] = Arr[ Arr[ i ] ] ; 
    i = Arr[ i ]; 
    }
return i;
}

void weighted_union(vector<int> &Arr,vector<int> &size,int A,int B)
{
    int root_A = root(Arr,A);
    int root_B = root(Arr,B);
    if(size[root_A] < size[root_B ])
    {
        Arr[ root_A ] = Arr[root_B];
        size[root_B] += size[root_A];
    }
    else
    {
        Arr[ root_B ] = Arr[root_A];
        size[root_A] += size[root_B];
    }

}

int main() {
    int e,n;
    cin>>n>>e;
    vector<vector<int>> g(n);
    for(int i=0;i<n;i++){
        g[i].resize(0);
    }
    vector<int> Arr(n);
    vector<int> size(n);
    initialize(Arr,size,n);
      for(int i=0;i<e;i++){
          int x,y;
          cin>>x>>y;
          g[x].push_back(y);
          if(!find(Arr,x,y)){
              weighted_union(Arr,size,x,y);
          }
          
      }
    
    for(int i=0;i<n;i++){
        cout<<Arr[i]<<" ";
    }
    cout<<endl;
    cout<<"------------------------------------------------------------"<<endl;
     for(int i=0;i<n;i++){
        cout<<size[i]<<" ";
    }
    cout<<endl;
    map<int,int> m;
    for(int i=0;i<n;i++){
        m[Arr[i]]+=1;
    }
    int res=0;
    vector<int> q(0);
    for(auto it:m){
        cout<<it.first <<" -> "<< it.second<<endl;
        //res *=it.second;
        q.push_back((it.second));
    }
    for(int i=0;i<q.size();i++){
        for(int j=i+1;j<q.size();j++){
        res+=(q[i]*q[j]);
    }
    }
    cout<<res<<endl;
    
    
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

