//https://leetcode.com/problems/filling-bookcase-shelves/
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int n = books.size();
        vector<int> dp(n+1,0);
        for(int i = 0;i<n;i++){
            int curr_width = books[i][0];
            int curr_height = books[i][1];
            if(i!=0)
                dp[i] = dp[i-1] + books[i][1];
            else
                dp[i] = books[i][1];
            for(int j = i-1;j>=0 && (curr_width+books[j][0])<=shelf_width;j--){
                curr_width=curr_width+books[j][0];
                curr_height = max(curr_height,books[j][1]);
                if(j>0)
                {
                    dp[i] = min(dp[i],dp[j-1]+curr_height);
                }
                else{
                    dp[i] = min(dp[i],curr_height);
                }
            }
        }
        
        /*for(auto it:dp)
            cout<<it<<" ";
        cout<<endl;*/
        return dp[n-1];
    }
};
