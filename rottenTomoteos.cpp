//https://practice.geeksforgeeks.org/problems/rotten-oranges/0
#include <bits/stdc++.h>
using namespace std;
bool check(int n,int m,int i,int j){
    bool flag =true;
    if(i<0 || i>=n){
        flag =false;
    }
    if(j<0 || j>=m){
        flag =false;
    }
    return flag;
}

bool check1(int n,int m,vector<vector<int>> &a){
    bool flag =true;
    for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
            if(a[i][j]==1){
                flag =false;
                break;
            }
            }
            
        }
    return flag;
}

void printMatrix(vector<vector<int>> &a,int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"------------------------------------"<<endl;
}
static int ans;
void dfs(vector<vector<int>> &a,vector<vector<int>> &visited,queue<pair<int,pair<int,int>>> q,int n,int m){
    queue<pair<int,pair<int,int>>> r;
    // cout<<"ans:"<<ans<<endl;
    //printMatrix(a,n,m);
    while(!q.empty()){
        pair<int,pair<int,int>> p = q.front();
        q.pop();
        int x = p.first;
        pair<int,int> y = p.second;
        int i = y.first;
        int j = y.second;
        ans = max(x+1,ans);
        if(visited[i][j]==-1){
            visited[i][j]=1;
            if(check(n,m,i+1,j)){
                if(a[i+1][j]==1){
                    a[i+1][j]=2;
                    r.push(make_pair(x+1,make_pair(i+1,j)));
                }
            }
            
            if(check(n,m,i-1,j)){
                if(a[i-1][j]==1){
                    a[i-1][j]=2;
                    r.push(make_pair(x+1,make_pair(i-1,j)));
                }
            }
            
            if(check(n,m,i,j+1)){
                if(a[i][j+1]==1){
                    a[i][j+1]=2;
                    r.push(make_pair(x+1,make_pair(i,j+1)));
                }
            }
            
            if(check(n,m,i,j-1)){
                if(a[i][j-1]==1){
                    a[i][j-1]=2;
                    r.push(make_pair(x+1,make_pair(i,j-1)));
                }
            }
            
        }

    }
    bool myflag = check1(n,m,a);
    if(!myflag && !r.empty()){
        dfs(a,visited,r,n,m);
    }
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        ans = 0;
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> a(n,vector<int> (m));
        vector<vector<int>> visited(n,vector<int> (m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
                if(a[i][j]==2){
                    q.push(make_pair(0,make_pair(i,j)));
                }
            }
            
        }

        dfs(a,visited,q,n,m);
        if(check1(n,m,a))
            cout<<ans<<endl;
        else
            cout<<-1<<endl;
    }
	//code
	return 0;
}