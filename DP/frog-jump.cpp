//https://leetcode.com/problems/frog-jump/
const int mod = 1e16 + 1;
class Solution {
public:
    bool myfunction(vector<int>& stones){
        int n = stones.size();
        map<int,set<int>> m;
        m[0].insert(1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int jump = stones[i]-stones[j];
                if(m[j].find(jump)!=m[j].end()){
                    m[i].insert(jump);
                    m[i].insert(jump-1);
                    m[i].insert(jump+1);
                }
            }
        }
        if(m[n-1].empty()){
            return false;
        }
        return true;
    }
    bool canCross(vector<int>& stones) {
        return myfunction(stones);
    }
};