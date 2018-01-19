#include<iostream>
#include<vector>
#include<map>
#include<list>
#include<set>
#include<string>
#include <bits/stdc++.h>
using namespace std;
static queue<int> q;
void MSTPrim(vector<vector<pair<int,int> > > &vec,int E,int v,int p){
    int parent[v+1];
    //vector<pair<pair<int,int>,int>> res1;
    vector<int> visited(v+1,-1);
    vector<int> value(v+1,INT_MAX);
    set<pair<int,pair<int,int>>> heap;
    set<pair<int,pair<int,int>>> res1;
    while(true){
    visited[p]=1;
    for(int j=0;j<vec[p].size();j++){
        int w=vec[p][j].second;
        int q=vec[p][j].first;
        pair<int,int> t=make_pair(p,q);
        heap.insert(make_pair(w,t));
        value[q]=min(w,value[q]);
        parent[q]=p;
        
    }
        for(auto it:heap){
        //pair<int,pair<int,int>> r=*(heap.begin());
        pair<int,int> s=(it).second;
        if(visited[s.second]!=1){
            visited[s.second]=1;
            //res1.insert(make_pair(it.second,it.first));
            res1.insert(it);
           p=s.second;
            
            break;
        }
        }
        bool flag=false;
        for(int i=1;i<=v;i++){
            if(visited[i]==-1)
                flag=true;
        }
        /*for(int i=1;i<=v;i++){
            cout<<visited[i]<<" ";
        }
        cout<<endl;*/
        
        if(flag==false)
            break;
        
    }
    int res2=0,maxi=INT_MIN;
    //cout<<"Spanning tree:"<<endl;
    int jsub;
    for(auto it:res1){
        
        int i=(it.second).first;
        int j=(it.second).second;
        int wt=it.first;
        maxi=max(maxi,wt);
        if(maxi==wt)
            jsub=j;
        res2+=wt;
        //cout<<"("<<i<<","<<j<<") :"<<wt<<endl;
    }
    cout<<(res2-maxi)<<" "<<vec[jsub].size()<<endl;
    
    
    
}



void BFS(vector<vector<int> > vec,vector<int> &visited){
	//vector<int> v=vec[s];
	while(!q.empty()){
		int s =q.front();
		cout<<s<< " ";
		visited[s]=1;	
	for(vector<int>::iterator i=vec[s].begin();i!=vec[s].end();i++){
		if(visited[*i]==-1){
			q.push(*i);
			visited[*i]=1;
		}
	}
	q.pop();
}

}
void DFS(int s,vector<vector<int> > vec,vector<int> &visited){
visited[s]=1;
cout<<s<< " ";
for(int i=0;i<vec[s].size();i++){
int u=vec[s][i];
	if(visited[u]==-1){
		DFS(u,vec,visited);
		
	}

}



}

int main(){
	int E,V,x1,x2;
	 
//cout<<"Enter the no of Edges and vertices:"<<endl;
cin>>E>>V;
vector<vector<int> > vec(V);
vector<int> visited(V,-1);
for(int i=0;i<E;i++)
{
	//cout<<"Enter Edges 1->2:"<<endl;
	cin>>x1>>x2;
	vec[x1].push_back(x2);
	//comment below if undirected graph
	//vec[x2].push_back(x1);
}
cout<<"Edges are as follows:"<<endl;
for(int j=0;j<vec.size();j++)
{
	for(int k=0;k<vec[j].size();k++){
		cout<< j<<"->"<<vec[j][k]<<" ";
	}
	cout<<endl;
}
/*cout<<"Showing DFS"<<endl;
DFS(2,vec,visited);
cout<<endl;*/
cout<<"Showing BFS"<<endl;    
q.push(0);
BFS(vec,visited);
cout<<endl;
	return 0;
}
