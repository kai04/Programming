//https://leetcode.com/problems/palindromic-substrings/
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int ans = n;
        vector<vector<bool>> is_pal(n,vector<bool>(n,false));
        is_pal[0][0] = true;
        for(int i=1;i<n;i++){
            if(s[i-1]==s[i]){
                is_pal[i-1][i] = true;
                ans++;
            }
            is_pal[i][i] = true;
        }
        
        for(int j = 3;j<=n;j++){
            for(int i=0;i<n;i++){
                int k = i+j-1;
                if(k<n){
                    if(s[i]==s[k] && is_pal[i+1][k-1]){
                        is_pal[i][k] = true;
                        ans++;
                    }
                }
            }
        }
        
        return ans;
    }
};