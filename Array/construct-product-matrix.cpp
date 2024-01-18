//https://leetcode.com/contest/weekly-contest-367/problems/construct-product-matrix/
typedef long long ll;
const int mod = 12345;
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> pref(n, vector<int>(m,0));
        vector<vector<int>> suff(n, vector<int>(m,0));
        vector<vector<int>> ret(n, vector<int>(m,0));
        vector<int> prefRowProd(n,0);
        vector<int> suffRowProd(n,0);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(j==0){
                    pref[i][j] = grid[i][j]%mod;
                } else{
                    pref[i][j] = (pref[i][j-1]*(grid[i][j]%mod))%mod;
                }
            }
            
            for(int j=m-1;j>=0;j--){
                if(j==m-1){
                    suff[i][j] = grid[i][j]%mod;
                } else{
                    suff[i][j] = (suff[i][j+1]*(grid[i][j]%mod))%mod;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(i==0){
                prefRowProd[i] = pref[i][m-1]%mod;
            } else{
                prefRowProd[i] = (prefRowProd[i-1]*pref[i][m-1])%mod;
            }
        }
        
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                suffRowProd[i] = suff[i][0]%mod;
            } else{
                suffRowProd[i] = (suffRowProd[i+1]*suff[i][0])%mod;
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int x1 = 1,x2=1,x3=1,x4=1;
                if(i>0){
                    x1 = prefRowProd[i-1];
                }
                if(j>0){
                    x2 = pref[i][j-1];
                }
                if(j<m-1){
                    x3 = suff[i][j+1];
                }
                if(i<n-1){
                    x4 = suffRowProd[i+1];
                }
                // cout<<"i:"<<i<<" j:"<<j<<" x1:"<<x1<<" x2:"<<x2<<" x3:"<<x3<<" x4:"<<x4<<endl;
                ret[i][j] = (((((x1*x2)%mod)*x3)%mod)*x4)%mod;
            }
        }
        
        return ret;

    }
};