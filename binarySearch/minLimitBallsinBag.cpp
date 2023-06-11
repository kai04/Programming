//https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/
typedef long long ll;
class Solution {
public:
    ll check(vector<int>& a, ll target){
        auto it = upper_bound(a.begin(),a.end(),target);
        ll i = it - a.begin();
        ll j = a.size()-1;
        ll t = 0;
        while(j>=0 && j>=i){
            ll p = ceil(((double)a[j]/target));
            t += p-1;
            // cout<<"i:"<<i<<" j:"<<j<<" t:"<<t<<" p:"<<p<<endl;
            j--;
        }
        return t;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        
        ll sum = 0;
        for(auto &x:nums)
            sum+=x;
        ll n = nums.size();
        ll tot = n+maxOperations;
        
        sort(nums.begin(),nums.end());
        ll l = 1;
        ll r = sum;
        //cout<<check(nums,5)<<endl;
         // for(int i =0;i<=20;i++){
         //     ll q = 499999980+i;
         //     ll a1 = check(nums,q);
         //     cout<<"Sum:"<<q<<" operation:"<<a1<<endl;
         // }
        
        while(l<r){
            ll m = l + (r-l)/2;
            ll t = check(nums,m);
            //cout<<"l:"<<l<<" r:"<<r<<" m:"<<m<<" t:"<<t<<endl;
            if(t>maxOperations){
                l = m+1;
            } else {
                r = m;
            }
        }
           
        return r;
    }
};