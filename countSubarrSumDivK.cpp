//https://leetcode.com/problems/subarray-sums-divisible-by-k/description/
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int n=A.size();
        vector<int> temp(n+1,0);
        vector<int> mod(K+1,0);
        // temp[0]=A[0];
        int cumSum=0;
        for(int i=0;i<n;i++){
            cumSum+=A[i];
            // temp[i]=temp[i-1]+A[i-1];
            mod[((cumSum % K) + K) % K]++;
            // cout<<"i:"<<i<<endl;
        }
        int res=0;
        for (int i = 0; i < K; i++) 
        {
            // cout<<"i:"<<i<<" hey"<<endl;
        if (mod[i] > 1) 
            res += (mod[i] * (mod[i] - 1)) / 2;
        }
        res += mod[0]; 
        return res;
    }
};