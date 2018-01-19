#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector> 
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <ctime>
#include <map>
#include <stack>
#include <cassert>
using namespace std; // }}}
static int count=0;

void DFS(vector<vector<int> > &adj,int v,stack<int> &s,map<int,bool> &mymap){
       //cout<<"v:"<<v<<endl;
       //cout<<"mymap[v]:"<<mymap[v]<<endl;   
    if(mymap[v]==false){
        //cout<<"pushing.....:"<<v<<endl;
        s.push(v);
        mymap[v]=true;
           for(int k=0;k<adj[v].size();k++){
               //v=adj[v][k];
               DFS(adj,adj[v][k],s,mymap);
           }
         
         }    
}

int main()
{ 
    stack<int> s;
    int N, I,count1=0,temp;
    cin >> N >> I;
    vector<vector<int> > pairs(N);
    
    for (int i = 0; i < I; ++i) {
        int a, b;
        cin >> a >> b;
        pairs[a].push_back(b);
        pairs[b].push_back(a);
    }
    long long result = 0; 
    map<int,bool> mymap;
    for(int i=0;i<N;i++){
        mymap.insert(pair<int,bool>(i,false));
    }
    vector<int> res(0);
    for(int j=0;j<N;j++)
    {
        if(mymap[j]==false)
        {
            s=stack<int>();
            count1++;
            DFS(pairs,j,s,mymap);
             //cout<<"old size:"<<res.size()<<endl;
            //cout<<"pushing...."<<s.size()<<endl;
            res.push_back(s.size());
           
            //int x=res.size();
            //x++;
            //res.resize(x);
            //cout<<"new size:"<<res.size()<<endl;
                
            //cout<<"Stack size:"<<s.size()<<endl;
            //result*=s.size();
            /* while(!s.empty()){
                temp=s.top();
                cout<<temp<<endl;
                s.pop();
            }*/
        }
        //res.resize((res.size()-1));
        
    }
    //cout<<"===================="<<endl;
    //cout<<"res.size():"<<res.size();
    for(int i=0;i<res.size()-1;i++){
        for(int j=i+1;j<res.size();j++){
        //cout<<res[i]<<endl;
            result+=res[i]*res[j];
        }
    }
    //cout<<"count:"<<count1<<endl;
    
    
    /** Write code to compute the result using N,I,pairs **/
    
    
    cout << result << endl;
    return 0;
}

