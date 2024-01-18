//https://leetcode.com/problems/range-frequency-queries/
const int RANGE_SIZE=10001;
class RangeFreqQuery {
public:
    vector<vector<int>> bit;
    int n;
    void bit_update(int i, int val){
        for(;i<=n;i+=(i&-i)){
            bit[i][val]+=1;
        }
    }
    int bit_query(int i, int val){
        int ans =0;
        for(;i>0;i-=(i&-i)){
            ans+=bit[i][val];
        }
        return ans;
    }
    RangeFreqQuery(vector<int>& arr) {
        n = arr.size();
        bit.resize(n+1,vector<int>(RANGE_SIZE,0));
        for(int i=0;i<n;i++){
            bit_update(i+1,arr[i]);
        }
        // for(int i=1;i<=n;i++){
        //     cout<<"i:"<<i<<" -> [";
        //     for(int j=1;j<3;j++){
        //         cout<<bit[i][j]<<" ";
        //     }
        //     cout<<"]"<<endl;
        // }
    }
    
    int query(int left, int right, int value) {
        int p1 = bit_query(left,value);
        int p2 = bit_query(right+1,value);
        // cout<<"left:"<<left<<" right:"<<right<<" p1:"<<p1<<" p2:"<<p2<<endl;
        int ret = p2-p1;
        return ret;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */