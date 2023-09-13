//https://leetcode.com/problems/jump-game-vii/description/
class Solution {
public:
    void printQ(queue<int> q, int ix){
        cout<<"Printing Queue for Index:"<<ix<<endl;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            cout<<x<<" ";
        }
        cout<<endl<<"-------------------------"<<endl;
    }

    bool canReach(string s, int minJump, int maxJump) {
            int n = s.length();
            vector<bool> dp(n,false);
            int reaches = 0;
            if(s[0]=='0' && s[n-1]=='0'){
                dp[0] = true;
            }
            else{
                return false;
            }
            for(int i=1;i<n;i++){
                int low = i-maxJump;
                int high = i-minJump;
                if(high>=0){
                    if(dp[high]){
                        reaches++;
                    }
                }

                if(low>0){
                    if(dp[low-1]){
                        reaches--;
                    }
                }

                if(reaches>0 && s[i]=='0'){
                    dp[i] = true;
                }
            }
            return dp[n-1];  
    }

    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        queue<int> q; 
        if(s[0]=='1'){
            return false;
        }
        int farthest = 0;
        int start=0;
        q.push(0);
        while(!q.empty()){
            int i = q.front();
            q.pop();
            start = max(farthest+1,i+minJump);
            for(int j=start;j<=min(i+maxJump,n-1);j++){
                if(j==n-1 && s[j]=='0'){
                    return true;
                }
                if(s[j]=='0')
                    q.push(j);
            }
            farthest = i+maxJump;
            // printQ(q,i);
        }
        return false;        
    }
};