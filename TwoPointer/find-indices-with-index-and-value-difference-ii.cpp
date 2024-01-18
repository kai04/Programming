//https://leetcode.com/contest/weekly-contest-367/problems/find-indices-with-index-and-value-difference-ii/
class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int n = nums.size();
        vector<int> ret(2,-1);
        vector<int> maxa(n,INT_MIN);
        vector<int> mina(n,INT_MAX);
        maxa[0] = 0;
        mina[0] = 0;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[maxa[i-1]]){
                maxa[i] = i;
            } else{
                maxa[i] = maxa[i-1];
            }
            
             if(nums[i]<nums[mina[i-1]]){
                mina[i] = i;
            } else{
                mina[i] = mina[i-1];
            }
            // cout<<"i:"<<i<<" maxa[i]:"<<maxa[i]<<" mina[i]:"<<mina[i]<<endl;
        }
        
        for(int j=0;j<n;j++){
            int p = j-indexDifference;
            if(p>=0){
                int q = maxa[p];
                int r = mina[p];
                if(abs(nums[q]-nums[j])>=valueDifference){
                    ret[0] = q;
                    ret[1] = j;
                }
                if(abs(nums[r]-nums[j])>=valueDifference){
                    ret[0] = r;
                    ret[1] = j;
                }
                // cout<<"j:"<<j<<" p:"<<p<<" q:"<<q<<" r:"<<r<<" ret:("<<ret[0]<<","<<ret[1]<<")"<<endl;
            }
        }
        return ret;
    }
};