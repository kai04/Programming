//https://leetcode.com/problems/palindrome-partitioning/submissions/w
static vector<vector<string>> results;
class Solution {
public:
    void updateResults(string s, vector<string> &str1){
        string temp="";
        for(int i = 0;i<str1.size();i++){
            temp = temp + str1[i];
        }
        /*for(auto it:str1)
            cout<<it<<" ";
        cout<<endl;*/
        if(temp==s){
            results.push_back(str1);
        }
    }
    void solveUtils(int i,int j,vector<vector<bool>> &isPalindrome,string &s,vector<string> temp){
        //base case
        if(i>=j){
            updateResults(s,temp);
        }
        for(int k=i;k<=j;k++){
            if(isPalindrome[i][k]){
                string sub="";
                    sub = s.substr(i,k-i+1);
                //choose
                vector<string> temp1 = temp;                
                temp1.push_back(sub);
                solveUtils(k+1,j,isPalindrome,s,temp1);
                //unchoose
            }
            
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.length();
        results.resize(0);
        vector<vector<bool>> isPalindrome(n,vector<bool>(n,false));
        //base case
        for(int i=0;i<n;i++){
            isPalindrome[i][i] = true;
            
        }
        
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1])
                isPalindrome[i-1][i] = true;
            
        }
        
        for(int l=2;l<=n;l++){
            for(int i=0;i<n;i++){
                int j =  i+l-1;
                if(j<n){
                    if(s[i]==s[j]){
                        isPalindrome[i][j] = isPalindrome[i][j] || isPalindrome[i+1][j-1];
                    }
                }
            }    
        }
        vector<string> ans;
        solveUtils(0,n-1,isPalindrome,s,ans);
        return results;
        
    }
};
