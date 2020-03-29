//https://www.interviewbit.com/problems/regular-expression-match/
int Solution::isMatch(const string A, const string B) {
    
    int n=A.length();
    int m=B.length();
    string pat = "";
    
    for(int j=1;j<m;j++){
            
    }
    vector<vector<bool>> T(n+1,vector<bool>(m+1,false));
    //base case 
    T[0][0] = true;
    for(int j=1;j<=m;j++){
        if(B[j-1]=='*'){
            if(j==1)
                T[0][j] = true;
            else{
                if(B[j-2]=='*'){
                    T[0][j] = T[0][j-1];
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(A[i-1]==B[j-1] || B[j-1]=='?'){
                T[i][j] = T[i-1][j-1];
            }
            else if(B[j-1]=='*'){
                T[i][j] = T[i-1][j-1] || T[i][j-1] || T[i-1][j];
            }
            else{
                T[i][j] = false;
            }
            
        }
    }
    
    /*for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<T[i][j]<<" ";    
        }
        cout<<endl;
    }*/
    if(T[n][m])
        return 1;
    return 0;
}

