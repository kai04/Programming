//https://leetcode.com/problems/pacific-atlantic-water-flow/
#include<bits/stdc++.h>

using namespace std;

vector<int> x_dir = {0,0,-1,1};
vector<int> y_dir = {-1,1,0,0};


bool dfs(int x,int y,vector<vector<int>> &h, vector<vector<bool>> &p){
    int n = h.size();
    int m = h[0].size();
    if(p[x][y]){
        return true;
    }
    int k = h[x][y];
    bool ret = false;
    h[x][y] = 1e6;
    for(int d=0;d<4;d++){
        int x_new = x + x_dir[d];
        int y_new = y + y_dir[d];
        if(x_new>=0 && y_new>=0 && x_new<n && y_new<m && h[x_new][y_new]<=k ){
            ret = ret || dfs(x_new,y_new,h,p); 
        }
    }
    h[x][y] = k;
    p[x][y] = ret;
    return ret;
}



vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
    int n = h.size();
    int m = h[0].size();
    vector<vector<int>> ans;
    vector<vector<bool>> pac(n,vector<bool>(m,false));
    vector<vector<bool>> atl(n,vector<bool>(m,false));
    for(int i=0;i<n;i++){
        pac[i][0] = true;
        atl[i][m-1] = true;
    }
    
    for(int i=0;i<m;i++){
        pac[0][i] = true;
        atl[n-1][i] = true;
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(dfs(i,j,h,pac) && dfs(i,j,h,atl)){
                vector<int> t;
                t.push_back(i);
                t.push_back(j);
                ans.push_back(t);
            }
        }
    }
    
    return ans;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> mat(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    vector<vector<int>> a = pacificAtlantic(mat);
    for(auto it:a){
        cout<<"[";
        for(auto it1:it)
            cout<<it1<<",";
        cout<<"]\n";
    }
    return 0;
}
