//https://leetcode.com/problems/n-queens-ii/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isSafe(int row, int col, vector<vector<bool>> &board, int n){
    int x = row;
    int y = col;
    // check row
    while(y >= 0){
        if(board[x][y])
            return false;
        y--;
    }
    x = row;
    y = col;
    // check diagonal
    while(x >= 0 && y >= 0){
        if(board[x][y])
            return false;
        y--;
        x--;
    }
    x = row;
    y = col;
    // check diagonal
    while(x < n && y >= 0){
        if(board[x][y])
            return false;
        y--;
        x++;
    }
    return true;
}

void printBoard(vector<vector<bool>> &x,int n){
    cout<<"Printing board ....."<<endl<<"---------------------------"<<endl;
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            cout<<x[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"---------------------------"<<endl;
}


int helper(int col,vector<vector<bool>> &board, int n){
    //base case
    int cnt = 0;
    if(col==n){
        return 1;
    }
    for(int row =0;row<n;row++){
        if(!board[row][col] && isSafe(row,col,board,n)){
            //choose
            board[row][col] = true;
            cnt += helper(col+1,board,n);
            //unchoose
            board[row][col] = false;
        }
    }
    return cnt;
}

int totalNQueens(int n) {
    vector<vector<bool>> board(n,vector<bool>(n,false));
    int abc = helper(0,board,n);
    return abc;
}

int main(){
    int n;
    cin>>n;
    int result =  totalNQueens(n);
    cout<<"RES:"<<result<<endl;
}