    #include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int dirx[4] = {0, 0, -1, 1};
int diry[4] = {-1, 1, 0, 0};            
int maximumSafenessFactorOld(vector<vector<int>>& grid) {

    int n = grid.size();
    int m = grid[0].size();
            //creating a 2d grid for safeness of every cell
    vector<vector<int>>safety(n,vector<int>(m,INT_MAX));

    queue<pair<pair<int,int>,int>>bfs;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(grid[i][j]){
                        //we will start from every thief cell
                bfs.push({{i,j},0});
                safety[i][j] = 0;
            }
        }
    }

    int mx = 0;
    while(!bfs.empty()){
        pair<pair<int,int>,int>temp = bfs.front();
        bfs.pop();
        int x = temp.first.first;
        int y = temp.first.second;
        int val = temp.second;
        mx = max(mx,val);

                //I can go to down cell if the safeness there is > than val
        if((x+1)<n){
            if(safety[x+1][y] > (val+1)){
                safety[x+1][y] = val+1;
                bfs.push({{x+1,y},val+1});
            }
        }

                //I can go to right cell if the safeness there is > than val
        if((y+1)<n){
            if(safety[x][y+1] > (val+1)){
                safety[x][y+1] = val+1;
                bfs.push({{x,y+1},val+1});
            }
        }

                //I can go to up cell if the safeness there is > than val
        if((x-1)>=0){
            if(safety[x-1][y] > (val+1)){
                safety[x-1][y] = val+1;
                bfs.push({{x-1,y},val+1});
            }
        }
                //I can go to left cell if the safeness there is > than val
        if((y-1)>=0){
            if(safety[x][y-1] > (val+1)){
                safety[x][y-1] = val+1;
                bfs.push({{x,y-1},val+1});
            }
        }
    }
    for(int ii=0;ii<n;ii++){
        for(int jj=0;jj<n;jj++){
            cout<<safety[ii][jj]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}
vector<vector<int>> allDistances(int i, int j, int n){
        // int dirx[6] = {-1,-1,-1,0,0,1,1,1};
        // int diry[6] = {-1,0,1,-1,1,-1,0,1};
        
        vector<vector<int>> ret;
        for(int d =0;d<4;d++){
            int xi = i+dirx[d];
            int yj = j+diry[d];
            if(xi>=0 && yj>=0 && xi<n && yj<n ){
                vector<int> g(2);
                g[0] = xi;
                g[1] = yj;
                ret.push_back(g);
            }
        }
        return ret;
    }
    void bfs(int n, vector<vector<int>> &grid, vector<vector<int>> &dist){
        queue<vector<int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                // cout<<"i:"<<i<<" j:"<<j<<endl;
                if(grid[i][j]==1){
                    vector<int> x(3); 
                    x[0]= i;
                    x[1]= j;
                    x[2]= 0;
                    dist[i][j] = 0;
                    q.push(x);
                    visited[i][j] = true;
                }
            }
        }
        while(!q.empty()){
            vector<int> y = q.front();
            q.pop();
            // cout<<" #i:"<<y[0]<<" j:"<<y[1]<<" Dist:"<<y[2]<<endl;
            vector<vector<int>> z = allDistances(y[0], y[1], n);
            for(int t=0;t<z.size();t++){
                if(!visited[z[t][0]][z[t][1]] && dist[z[t][0]][z[t][1]]>y[2]+1){
                    // cout<<" ! i:"<<z[t][0]<<" j:"<<z[t][1]<<endl;
                    visited[z[t][0]][z[t][1]] = true;
                    vector<int> r(3);
                    r[0] = z[t][0];
                    r[1] = z[t][1];
                    r[2] = y[2]+1;
                    // cout<<" @i:"<<r[0]<<" j:"<<r[1]<<" Dist:"<<r[2]<<endl;
                    dist[r[0]][r[1]] = r[2];
                    q.push(r);
                }
            }
        }
    }

void printPQ(priority_queue<array<int, 3>> pq){
    cout<<"Printing priority_queue ..."<<endl;
    cout<<"{"<<endl;
    while(!pq.empty()){
        auto [sf, i, j] = pq.top(); pq.pop();
        cout<<"(dist:"<<sf<<" ,i:"<<i<<" ,j:"<<j<<") ";
    }
    cout<<"}"<<endl;
    cout<<"----------------------------"<<endl;
}
int maximumSafenessFactor(vector<vector<int>>& grid) {
    int n = grid.size();
    // vector<vector<int>> dist(n, vector<int>(n, INT_MAX/2));
    vector<vector<int>> g(n, vector<int>(n, INT_MAX/2));
    bfs(n, grid, g);
    priority_queue<array<int, 3>> pq;
    pq.push({g[0][0], 0, 0});
    while (pq.top()[1] < n - 1 || pq.top()[2] < n - 1) {
        printPQ(pq);
        auto [sf, i, j] = pq.top();
        pq.pop();
        for (int d = 0; d < 4; ++d) {
            int x = i + dirx[d], y = j + diry[d];
            if (min(x, y) >= 0 && max(x, y) < n && g[x][y] > 0) {
                pq.push({min(sf, g[x][y]), x, y});
                g[x][y] *= -1; 
            }
        }
    }
    return 0;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> A(n, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>A[i][j];
        }
    }

    int ans = maximumSafenessFactor(A);

    return 0;
}