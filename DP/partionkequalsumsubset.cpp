//https://leetcode.com/problems/partition-to-k-equal-sum-subsets/
#include<bits/stdc++.h>
using namespace std;
bool canPartition(int start, vector<int> a, vector<bool> seen, int k, int sum, int target) {
        if (k == 1) return true;
        if (sum == target)
            return canPartition(0, a, seen, k - 1, 0, target);
        for (int i = start; i < a.size(); i++)
            if (!seen[i]) {
                seen[i] = true;
                if (canPartition(i + 1, a, seen, k, sum + a[i], target))
                    return true;
                seen[i] = false;
            }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum =0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%k!=0){
            return false;
        }
n        int target = sum/k;
        vector<bool> visited(n,false);
        bool ans = canPartition(0,nums,visited,k,0,target);
        return ans;
    }
int main(){
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	bool res = canPartitionKSubsets(a,k);
	cout<<"OUTPUT:"<<res<<endl;
	return 0;
}
