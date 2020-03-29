//https://www.interviewbit.com/problems/maximum-absolute-difference/
int Solution::maxArr(vector<int> &A) {
    int n = A.size();
    int max_add = INT_MIN,max_sub = INT_MIN;
    int min_add = INT_MAX,min_sub = INT_MAX;
    for(int i=1;i<=n;i++){
        max_add = max(max_add,A[i-1]+i);
        max_sub = max(max_sub,A[i-1]-i);
        min_add = min(min_add,A[i-1]+i);
        min_sub = min(min_sub,A[i-1]-i);
    }
    int ans = 0 ;
    // cout<<"max_add:"<<max_add<<" max_sub:"<<max_sub<<" min_add:"<<min_add<<" min_sub:"<<min_sub<<endl;
    ans =max(ans,abs(max_add-min_add));
    ans =max(ans,abs(max_sub-min_sub));
    return ans;
}

