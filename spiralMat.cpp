//https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix/0
#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
void spiral(int startrow,int startcol,int endrow,int endcol,vector<vector<int>> &mat){
    if(startrow>endrow ||(startcol>endcol))
        return;
    if(startrow==endrow){
        for(int i=startcol;i<=endcol;i++){
            std::cout<<mat[startrow][i]<<" ";
            ans.push_back(mat[startrow][i]);
        }
        return;
    }

    if(startcol==endcol){
        for(int i=startrow;i<=endrow;i++){
            std::cout<<mat[i][startcol]<<" ";
            ans.push_back(mat[startrow][i]);
        }
        return;
    }
    // left top to right top
    for(int i=startcol;i<endcol;i++){
        std::cout<<mat[startrow][i]<<" ";
        ans.push_back(mat[startrow][i]);
    }
    // right top to bottom right
    for(int i=startrow;i<endrow;i++){
        std::cout<<mat[i][endcol]<<" ";
        ans.push_back(mat[i][endcol]);
    }
    // bottom right to bottom left
    for(int i=endcol;i>startcol;i--){
        std::cout<<mat[endrow][i]<<" ";
        ans.push_back(mat[endrow][i]);
    }
    // bottom left to top left
    for(int i=endrow;i>startrow;i--){
        std::cout<<mat[i][startcol]<<" ";
        ans.push_back(mat[i][startcol]);
    }
    spiral(startrow+1,startcol+1,endrow-1,endcol-1,mat);
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    vector<vector<int>> mat(n,vector<int>(m));
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            cin>>mat[i][j];
	        }
	    }
	    spiral(0,0,n-1,m-1,mat);
        std::cout<<endl;
	}

	return 0;
}