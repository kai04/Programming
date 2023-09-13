//https://leetcode.com/problems/permutation-sequence/description/
typedef long long ll;
class Solution {
public:
    ll fact(int n){
        ll ret = 1;
        while(n!=1){
            ret =  ret * n;
            n--;
        }
        return ret;
    }
    void helper(int n, int k,vector<int> curr, vector<string> &res){
        //base case
        if(res.size()==k){
            return;
        }
        if(curr.size()==n){
            stringstream ss;
            for(int i:curr){
                ss<<i;
            }
            res.push_back(ss.str());
            return;
        }

        for(int i=1;i<=n;i++){
            if(find(curr.begin(),curr.end(),i)==curr.end()){
                curr.push_back(i);
                helper(n,k,curr,res);
                curr.pop_back();
            }
        }
    }
    void solve(vector<int> a, int k, string &ans){
        int n = a.size();
        //base case
        if(n==1){
            ans = ans+to_string(a[0]);
            return;
        } 
       
        ll x = fact(n-1);
        int y = k / x;
        int z = k % x;
        if(z != 0){
            n = y +1;
            k = z;  
        } else {
            n = y;
            k = x;
        }
        
        ans = ans + to_string(a[n-1]);
        a.erase(a.begin()+n-1);
        solve(a, k,ans);
    }

    string getPermutation(int n, int k) {
        // vector<int> curr;
        // vector<string> res;
        // helper(n,k,curr,res);
        // for(int i=0;i<res.size();i++){
        //     cout<<"i:"<<i<<" STRING:"<<res[i]<<endl;
        // }
        // return res[k-1];
        vector<int> a;
        string ans = "";
        for(int i=1;i<=n;i++){
            a.push_back(i);
        }
        solve(a,k,ans);
        return ans;

    }
};