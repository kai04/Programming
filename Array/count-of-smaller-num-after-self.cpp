//https://leetcode.com/problems/count-of-smaller-numbers-after-self/description/
typedef long long ll;
class Solution {
public:
    void printRes(int l, int r, vector<pair<int,int>> &res){
        cout<<"Printing arr from["<<l<<","<<r<<"]"<<endl;
        for(int i=l;i<=r;i++){
            cout<<"("<<res[i].first<<","<<res[i].second<<") ";
        }
        cout<<endl<<"-----------------------------"<<endl;
    }
    ll merge_sort(ll l, ll r, vector<pair<int,int>> &res, vector<pair<int,int>>& nums, vector<int> &a){
        
        //base case
        if(l==r){
            return 0;
        }
        ll m = (l+r)/2;
        ll left = merge_sort(l,m,res,nums,a);
        ll right = merge_sort(m+1,r,res,nums,a);
        ll ret = 0;
        ll i=l, j=m+1, k=l;
        // cout<<"L:"<<l<<" R:"<<r<<" i:"<<i<<" j:"<<j<<" m:"<<m<<endl;
        while(i<=m && j<=r){
            if(nums[i].first>nums[j].first){
                a[nums[i].second] += (r-j+1);
                // cout<<"i:"<<i<<" j:"<<j<<" nums[i]:"<<nums[i].first<<" nums[j]:"<<nums[j].first<<" inversion[i]:"<<a[nums[i].second]<<endl;
                ret = ret + (r-j+1);
                res[k].first = nums[i].first;
                res[k].second = nums[i].second;
                i++;
                k++;
            } else{
                // cout<<"i:"<<i<<" j:"<<j<<" nums[i]:"<<nums[i].first<<" nums[j]:"<<nums[j].first<<" No inversion"<<endl;
                res[k].first = nums[j].first;
                res[k].second = nums[j].second;
                j++;
                k++;
            }
        }
        if(i>m){
            while(j<=r){
                res[k].first = nums[j].first;
                res[k].second = nums[j].second;
                j++;
                k++;
            }
        } else{
            while(i<=m){
                res[k].first = nums[i].first;
                res[k].second = nums[i].second;
                i++;
                k++;
            }
        }
        for(int t=l;t<=r;t++){
            nums[t].first = res[t].first;
            nums[t].second = res[t].second;
        }
        // printRes(l,r,nums);
        // for(auto it:a)
        // {
        //     cout<<it<<" ";
        // }
        // cout<<endl<<"==============================="<<endl;
        return (ret+left+right);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> res(n);
        vector<int> ret(n,0);
        vector<pair<int,int>> num_t(n);
        for(int i=0;i<n;i++){
            num_t[i] = {nums[i],i};
        }
        ll x = merge_sort(0,n-1,res,num_t,ret);
        return ret;
    }
};