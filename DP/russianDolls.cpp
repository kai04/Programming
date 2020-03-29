//https://leetcode.com/problems/russian-doll-envelopes/submissions/
static void print(vector<pair<int,int>> &a){
	for(int i=0;i<a.size();i++){
		cout<<"("<<a[i].first<<","<<a[i].second<<") ";
		// cout<<"("<<a[i].second<<","<<a[i].first<<") ";
	}
	cout<<endl<<"----------------------------------------"<<endl;
}
static bool mysort(pair<int,int> p1,pair<int,int> p2){
	if(p1.first<p2.first){
		return true;
	}
	return false;
}
static int lengthOfLIS(vector<int>& nums,vector<pair<int,int>> &a) {
        int n =  nums.size();
        if(n==0)
            return 0;
        vector<int> lis(n,1);
        lis[0]=1;
        int max1 = 1;
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[j]<nums[i] && a[j].first<a[i].first)
                    lis[i] = max(lis[i],lis[j]+1);
                else
                    lis[i] = max(lis[i],1);
                max1 = max(max1,lis[i]);
            }
        }
        return max1;
    }
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        vector<pair<int,int>> a(n);
        for(int i=0;i<n;i++){
			// int l,w;
			// cin>>l>>w;
			a[i] = make_pair(envelopes[i][0],envelopes[i][1]);
		}
        // print(a);
        sort(a.begin(),a.end(),mysort);
        // print(a);
        vector<int> b(n);
		for(int j=0;j<n;j++){
			b[j] = a[j].second;
		}
        int lis  = lengthOfLIS(b,a);
        return lis;
    }
};
