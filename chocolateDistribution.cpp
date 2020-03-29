//https://www.interviewbit.com/problems/chocolate-distribution/

int Solution::solve(vector<int> &A, int B) {
    int ans  = INT_MAX;
    if(A.size()==0 ||B==0)
        return 0;
    sort(A.begin(),A.end());
    for(int i=0;i<A.size();i++){
        int j = i+B-1;
        int sum = 0;
        if(j<A.size()){
            int diff = A[j] - A[i];
            ans  = min(ans,diff);
        }
    }
    return ans;
}

