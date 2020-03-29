#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
static int cnt=0;

void DFS(int s,vector<vector<int> >  vec,vector<int> &visited,vector<int> &start,vector<int> &finish,vector<int> &mylist){
visited[s]=1;
cnt++;
start[s]=cnt;    
//cout<<s<< " ";
for(vector<int>::iterator i=vec[s].begin();i!=vec[s].end();i++){
    //int u=(*i).first;
    int u=(*i);
	if(visited[u]==-1){
		DFS(u,vec,visited,start,finish,mylist);
		
	}
    

}
cnt++;    
finish[s]=cnt;
    if(start[s]==(finish[s]-1))
        mylist.push_back(s);


}
int main() {
    int T;
    cin>>T;
    while(T--){
    vector<int> border(0);
    vector<vector<int> > vec(2501);
    map<int,int> mymap;
    int m,n;
    cin>>m>>n;
    int mat[m][n];
    int cnt=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cnt++;
            cin>>mat[i][j];
            mymap[cnt]=mat[i][j];
            if(i==0||j==0||i==m-1||j==n-1)
                border.push_back(cnt);
                
    }
    }
     for(int i=1;i<m-1;i++){
        for(int j=1;j<n-1;j++){
            if(mat[i][j]>=mat[i-1][j])
            { int x1,x2;
             x1=(i*n)+j+1;
             x2=((i-1)*n)+j+1;
                vec[x1].push_back(x2);
            }
            if(mat[i][j]>=mat[i+1][j])
            { int x1,x2;
             x1=(i*n)+j+1;
             x2=((i+1)*n)+j+1;
             vec[x1].push_back(x2);
            }
            if(mat[i][j]>=mat[i][j-1])
            { int x1,x2;
             x1=(i*n)+j+1;
             x2=(i*n)+j;
                vec[x1].push_back(x2);
            }
            if(mat[i][j]>=mat[i][j+1])
            { int x1,x2;
             x1=(i*n)+j+1;
             x2=(i*n)+j+2;
                vec[x1].push_back(x2);
            }
        }
     }
    int V=m*n;
    int temp=(2*n)+(m-2)*2;
    int incr=0;
         for(int i=1;i<m-1;i++){
        for(int j=1;j<n-1;j++){
    vector<int> visited(V+1,-1);
    vector<int> start1(V+1,-1);
    vector<int> end1(V+1,-1);
            int temp1=(i*n)+j+1;
            vector<int> mylist(0);
            DFS(temp1,vec,visited,start1,end1,mylist);
            for(vector<int>::iterator it=mylist.begin();it!=mylist.end();it++)
            {  
                //cout<<*it<<endl;
                if((find(border.begin(),border.end(),*it))!=(border.end()))
                   {
                       incr++;
                       break;
                   }
            }
            //cout<<"--------------"<<endl;
        }
         }
    cout<<(incr+temp)<<endl;
    }
/*    cout<<"Edges are as follows:"<<endl;
for(int j=0;j<vec.size();j++)
{
	for(int k=0;k<vec[j].size();k++){
		cout<< j<<"->"<<vec[j][k]<<" ";
	}
	cout<<endl;
}*/
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

