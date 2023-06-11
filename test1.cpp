#include<bits/stdc++.h>

using namespace std;
vector<int> x_pos = {1,-1,0,0};
vector<int> y_pos = {0,0,1,-1};
void printQ(queue<vector<int>> q){
	cout<<"Printing Queue..."<<endl;
	cout<<"{";
	while(!q.empty()){
		vector<int> f = q.front();
		q.pop();
		cout<<"["<<f[0]<<","<<f[1]<<","<<f[2]<<"] ,";
	}
	cout<<"}\n--------------------------------\n";
}
int bfs(vector<vector<int>> &mat,queue<vector<int>> &q, int uninfected){
	int ans = 0;
	int n = mat.size();
	int m = mat[0].size();
	while(!q.empty()){
		// printQ(q);
		vector<int> frontElm = q.front();
		q.pop();
		// cout<<"["<<frontElm[0]<<","<<frontElm[1]<<","<<frontElm[2]<<"]"<<endl;
		for(int i=0;i<4;i++){
			int x_new =  frontElm[0] + x_pos[i];
			int y_new =  frontElm[1] + y_pos[i];
			if(x_new>=0 && x_new<n && y_new>=0 && y_new<m && mat[x_new][y_new]==1){
				vector<int> temp(3);
				temp[0] = x_new;
				temp[1] = y_new;
				temp[2] = frontElm[2]+1;
				// cout<<"x:"<<frontElm[0]<<" y:"<<frontElm[1]<<" x_new:"<<x_new<<" y_new:"<<y_new<<" mat[x][y]:"<<mat[x_new][y_new]<<endl;
				ans = max(ans,(frontElm[2]+1));
				mat[x_new][y_new] = 2;
				uninfected--;
				q.push(temp);
			}
		}
	}
	if(uninfected>0)
		return -1;
	return ans;
}
int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> mat(n,vector<int>(m));
	queue<vector<int>> q;
	int uninfected = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>mat[i][j];
			if(mat[i][j]==2){
				vector<int> temp(3);
				temp[0] = i;
				temp[1] = j;
				temp[2] = 0;
				q.push(temp);
			} else if(mat[i][j]==1){
				uninfected++;
			}
		}
	}
	int ans = bfs(mat,q,uninfected);
	cout<<"ANS:"<<ans<<endl;
	return 0;
}