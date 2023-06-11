/*
https://leetcode.com/problems/max-points-on-a-line/description/
*/
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        /*
        n2-n-2p=0
        ans= (1(+/-)underoot(1+8p))/2 
        (p,q) (r,s)
        m = (s-q)/(r-p)
        y=mx+c
        q = mp+c
        s = mr+c
        c = q-mp = s-mr
        c= (qr-pq-sp+qp)/(r-p) = (qr-sp)/(r-p)
        c = sr-ps+qr-sr=qr-ps/(r-p)
        */
        map<pair<float,float>,int> m;
        map<int,int> r;
        int n  = points.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(points[j][0]!=points[i][0]){
                    float slope = (float)(points[j][1]-points[i][1])/(points[j][0]-points[i][0]);
                    float constant = (float)((points[i][1]*points[j][0])-(points[i][0]*points[j][1]))/(points[j][0]-points[i][0]);
                    m[make_pair(slope,constant)]++;
                } else{
                    r[points[j][0]]++;
                }
                  
            }
        }
        int ans = 0,cand=0;
        for(auto x:m){
            cand = max(cand,x.second);
            // cout<<"["<<(x.first).first<<", "<<(x.first).second<<"] -> "<<x.second<<endl;
        }
        // cout<<"Cand:"<<cand<<endl;
        for(auto x:r){
            // cout<<"["<<(x.first)<<"] -> "<<x.second<<endl;
            cand = max(cand,x.second);
        }
        float v1 = (float)(1+sqrt(1+8*cand))/2;
        float v2 = (float)(1-sqrt(1+8*cand))/2; 
        return max(v1,v2);
    }
};