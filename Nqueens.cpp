//https://www.geeksforgeeks.org/n-queen-problem-backtracking-3/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> sol;
bool isFeasible(vector<vector<int>> board,int i,int j){
    int n=board[0].size();
    for(int k=0;k<n;k++){
        if(board[k][j]==1){
            return false;
        }
        if(board[i][k]==1){
            return false;
        }
        if((i+k)<n && (j+k)<n){
            if(board[i+k][j+k]==1){
                return false;
            }   
        }
        if((i-k)>=0 && (j-k)>=0){
            if(board[i-k][j-k]==1){
                return false;
            }   
        }
        if((i-k)>=0 && (j+k)<n){
            if(board[i-k][j+k]==1){
                return false;
            }   
        }
        if((i+k)<n && (j-k)>=0){
            if(board[i+k][j-k]==1){
                return false;
            }   
        }
    }
    return true;
}
vector<int> save_sol(vector<vector<int>> board){
    int n =board[0].size();
    vector<int> mysol;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[j][i]==1){
                mysol.push_back(j+1);
            }
        }
    }
    return mysol;
}
void helper(vector<vector<int>> board,int q){
    int n =board[0].size();
    //base case means return sol
    if(q==n)
        {
            sol.push_back(save_sol(board));
            return;
        }
    //try all option for q
    
    // q denote qth col
    for(int i=0;i<n;i++){
        if(isFeasible(board,i,q)){
            board[i][q]=1;
            helper(board,q+1);
            //backrack
            board[i][q]=0;
        }
        
        // helper(board,q+1);
    }
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> board(n,vector<int> (n,0));
        sol.clear();
        helper(board,0);
        for(int i=0;i<sol.size();i++){
            cout<<"[";
            for(int j=0;j<sol[0].size();j++){
                // if(j!=sol[0].size()-1)
                    cout<<sol[i][j]<<" ";
                // else
                    // cout<<sol[i][j];
            }
            cout<<"] ";
            
        }
        if(sol.size()==0)
            cout<<-1;
        cout<<endl;
    }
    //code
    return 0;
}