//https://leetcode.com/problems/interval-list-intersections/
class Solution {
public:
    pair<int,int> check_intersection(int p,int q,int r,int s){
        int x = max(p,r);
        int y = min(q,s);
        pair<int,int> ret;
        if(x<=y){
            ret = make_pair(x,y);
        }
        else{
            ret = make_pair(-1,-1);
        }
        // cout<<"P:"<<p<<" Q:"<<q<<" R:"<<r<<" S:"<<s<<" X:"<<x<<" Y:"<<y<<endl;
        return ret;
    }
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size();
        int m = B.size();
        vector<vector<int>> ans;
        int i=0,j=0;
        while(i<n &&j<m){
            pair<int,int> I = check_intersection(A[i][0],A[i][1],B[j][0],B[j][1]);
            if(I.first!=-1 && I.second!=-1){
                vector<int> p(2);
                p[0] = I.first;
                p[1] = I.second;
                ans.push_back(p);
            }
            if(A[i][1]==B[j][1]){
                i++;
                j++;
            }
            else if(A[i][1]< B[j][1]){
                i++;
            }
            else if(A[i][1] > B[j][1]){
                j++;
            }
        }
        return ans;
    }
};
