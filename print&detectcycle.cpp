#include <bits/stdc++.h>
using namespace std;
int n;
int count1=0;
int *parent;
int *startt;
int *endt;
int** a;
void dfs(int v,int *visited){
    visited[v]=1;
    startt[v]=count1++;
    for(int i=0;i<n;i++){
        if(a[v][i]==1 && visited[i]==-1){
            parent[i]=v;
            dfs(i,visited);
        }
    }
    endt[v]=count1++;
}
int main() {
    cin>>n;
    a= new int*[n];
    for(int i=0;i<n;i++){
        a[i]= new int[n];
    }
    int visited[n];
    int visit1[n];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }    
    }
    startt=new int[n];
    endt=new int[n];
    parent=new int[n];
    for(int i=0;i<n;i++){
        visited[i]=-1;
        visit1[i]=-1;
        parent[i]=-1;
    }
    dfs(0,visited);
    /*for(int i=0;i<n;i++){
        cout<<startt[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<endt[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<parent[i]<<" ";
    }*/
    cout<<endl;
    bool flag=false;
    vector<string> cycles;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==1){
                int s1=startt[i];
                int e1=endt[i];
                int s2=startt[j];
                int e2=endt[j];
                
                if(s1-s2>=0 && e2-e1>=0){
                    string res="";
                    res+=j+'0';
                    int k=i;
                    while(visit1[k]==-1){
                        res+=k+'0';
                        visit1[k]=1;
                        k=parent[k];
                    }
                    reverse(res.begin(),res.end());
                    cycles.push_back(res);
                    flag=true;
                }
            }
        }
    }
    if(flag)
    {
        cout<<"cycle exist:"<<endl;
        for(auto it:cycles)
            cout<<it<<endl;
    }
    else
        cout<<"cycle doesn't exist"<<endl;
	//code
	return 0;
}
