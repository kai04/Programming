 //https://leetcode.com/problems/sudoku-solver/
 #include <bits/stdc++.h>
 using namespace std;

 bool check(int i, int j,vector<vector<char>>& board,int x){
        for(int t=0;t<9;t++){
            if(board[i][t]==('0'+x) && t!=j){
                return false;
            }
            if(board[t][j]==('0'+x) && t!=i){
                return false;
            }
        }
        int x1 = (i/3)*3;
        int y1 = (j/3)*3;
        for(int x2 = x1;x2<x1+3;x2++){
            for(int y2 = y1;y2<y1+3;y2++){
                if(board[x2][y2]==('0'+x))
                    return false;
            }
        }
        return true;
    }

    void printBoard(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j =0;j<9;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"------------------------------"<<endl;
    }
    
    bool helper(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j =0;j<9;j++){
                if(board[i][j]=='.')
                {
                    for(int k =1;k<=9;k++){
                      if(check(i,j,board,k)){
                          //choose
                          board[i][j] = '0'+k;
                          //recurse
                          if(helper(board)){
                            return true;
                          } else{
                            //unchoose
                          board[i][j] = '.';
                          }
                      }  
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }

    int main(){
        vector<vector<char>> a(9,vector<char>(9));
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cin>>a[i][j];
            }
        }
        solveSudoku(a);
        printBoard(a);
        return 0;
    }