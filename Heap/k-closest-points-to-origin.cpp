//https://leetcode.com/problems/k-closest-points-to-origin/submissions/
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        int n = points.size();
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<n;i++){
            int x = points[i][0];
            int y = points[i][1];
            int z = (x*x) + (y*y);
            int res = sqrt(z);
            // cout<<"X:"<<x<<" Y:"<<y<<" RES:"<<res<<" PQ size:"<<pq.size()<<endl;
            if(pq.size()<k){
                pq.push(make_pair(z,i));
            } else{
                int e = pq.top().first;
                if(z<e){
                    pq.pop();
                    pq.push(make_pair(z,i));
                }
            }
        }
        while(!pq.empty()){
            pair<int,int> p = pq.top();
            res.push_back(points[p.second]);
            pq.pop();
        }
        return res;
    }
};
