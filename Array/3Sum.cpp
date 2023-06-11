//https://leetcode.com/problems/3sum/
class Solution {
public:
    vector<vector<int>> twoSum(vector<pair<int,int>> &m, int l, int h,int x){
        int n = m.size();
        int i = l;
        int j = h;
        //cout<<"l:"<<l<<" h:"<<h<<" search:"<<x<<endl;
        vector<vector<int>> res;
        while(i<j && i<n && j>=0){
            int sum = m[i].first + m[j].first; 
            if(sum<x){
                i++;
            } else if(sum>x){
                j--;
            } else {
                vector<int> t;
                t.push_back(m[i].first);
                t.push_back(m[j].first);
                t.push_back(-x);
                res.push_back(t);
                i++;
                j--;
            }
        }
        return res;
    }
    string createHash(vector<int> &t){
        sort(t.begin(),t.end());
        stringstream ss;
        for(int x: t){
            ss<<x;
        }
        return ss.str();     
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> m(n);
        unordered_map<string,bool> m1;
        for(int i=0;i<n;i++){
            m[i] = {nums[i],i};
        }
        
        sort(m.begin(),m.end());
        vector<vector<int>> res;
        for(int i=0;i<n-2;i++){
            if(i==0 || (i>0 && m[i].first!=m[i-1].first)){
                vector<vector<int>> temp = twoSum(m,i+1,n-1,(-1*m[i].first));
                if(temp.size()!=0){
                    for(auto it:temp){
                        string hash = createHash(it);
                        if(m1.find(hash)==m1.end()){
                            res.push_back(it);
                            m1[hash] = true;
                        }    
                    }
                }
            }
        }
        return res;
    }
};