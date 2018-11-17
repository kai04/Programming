#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
int count1=0;
int roadcount=0;
void DFS(int s,vector<vector<int> > vec,vector<int> &visited,vector<int> &startTime,vector<int> &endTime){
visited[s]=1;
    roadcount++;
cout<<s<< " ";
    count1++;
    startTime[s]=count1;
for(int i=0;i<vec[s].size();i++){
int u=vec[s][i];
    count1++;
	if(visited[u]==-1){
		DFS(u,vec,visited,startTime,endTime);
	}
}
    //count1++;
    endTime[s]= count1;
}


int main() {
    int t;
    cin>>t;
    while(t--){
        int n,m,cl,cr;
        cin>>n>>m>>cl>>cr;
        vector<int> startTime(n+1,0);
        vector<int> endTime(n+1,0);
        vector<int> visited(n+1,-1);
        vector<vector<int> > vec(n+1);
        int deg[n+1][2]={0};
        for(int i=0;i<m;i++)
        {   int x1,x2;
            cin>>x1>>x2;
            deg[x1][1]++;
            deg[x2][0]++;
            vec[x1].push_back(x2);
            //vec[x2].push_back(x1);
        }
        int res=0;
        int dfscall =0;
        if(cl>cr){
        for(int j=1;j<visited.size();j++){
            if(visited[j]!=1){
                dfscall++;
                DFS(j,vec,visited,startTime,endTime);
                cout<<endl;
                res+=(roadcount-1)*cr;
                roadcount=0;
            }
        }
        res+=dfscall*cl;
        }
        else{
          res+=n*cl;  
        }
        cout<<res<<endl;
        cout<<"NO of DFS:"<<dfscall<<endl;
       
        /*for(int i = 1;i<startTime.size();i++){
            cout<<endl<<"i:"<<i<<" starttime:"<<startTime[i]<<" endtime:"<<endTime[i]<<endl;
        }*/
    }
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

