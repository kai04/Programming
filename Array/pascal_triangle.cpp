//https://leetcode.com/problems/pascals-triangle/description/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows==1){
            return {{1}};
        }
        vector<vector<int>> p{{1},{1, 1}};
        
        for(int i=2;i<numRows;i++){
            vector<int> q;
            q.push_back(1);
            for(int j=0;j<p[i-1].size()-1;j++){
                int r = p[i-1][j] + p[i-1][j+1];
                q.push_back(r); 
            }
            q.push_back(1);
            p.push_back(q);
        }
        return p;
    }
};