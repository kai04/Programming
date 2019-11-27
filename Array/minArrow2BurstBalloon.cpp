//https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/submissions/
bool comp(vector<int> p1,vector<int> p2){
    if(p1[0]<=p2[0])
        return true;
    return false;
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if(n<2){
            return n;
        }
        sort(points.begin(),points.end(),comp);
        int seen_length = points[0][1];
        int count=1;
        for(int i=0;i<n;i++){
            int start  = points[i][0];
            int end  = points[i][1];
            /*if(seen_length==-1){
                seen_length = end;
            }*/
            if(seen_length<start){
                count++;
                seen_length = end;
            }
            else if(seen_length>=start){
                if(end<=seen_length){
                    seen_length = end;
                }
                
            }
            //cout<<"start:"<<start<<" end:"<<end<<" seen len:"<<seen_length<<" count:"<<count<<endl;
        }
        return count;
    }
};
