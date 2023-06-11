//https://www.interviewbit.com/problems/wave-array/
vector<int> Solution::wave(vector<int> &a) {
    int n = a.size();
    sort(a.begin(),a.end());
    vector<int> ans(n);
    /*
    [a2, a1, a4 a3, a5]
    [2, 1 , 4 , 3 , 5]
        a1    a3    a5
           a2    a4
    */
    // for(int i=0;i<n;i=i+2){
    //     ans[i] = a[i];
    // }
    for(int i=1;i<n;i=i+2){
        ans[i-1] = a[i];
        ans[i] = a[i-1];
    }
    if(n%2==1)
    ans[n-1] = a[n-1];
    return ans;
}