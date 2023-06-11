//https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
class Solution {
public:
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> p;
        if(k==1 && n>0){
            return matrix[0][0];
        }
        p.push({matrix[0][0],{0,0}});
        int i,j;
        int ans;
        while(k>0 && !p.empty()){
            i = p.top().second.first;
            j = p.top().second.second;
            ans = p.top().first;
            p.pop();
            if(i+1<n && matrix[i+1][j] !=INT_MAX){
                p.push({matrix[i+1][j],{i+1,j}});
                matrix[i+1][j] =INT_MAX;
            }
            if(j+1< n&& matrix[i][j+1] !=INT_MAX){
                p.push({matrix[i][j+1],{i,j+1}});
                matrix[i][j+1] =INT_MAX;
            }
            k--;
            // cout<<"k:"<<k<<" curr:"<<ans<<endl;
        }
        return ans;
        }
};
