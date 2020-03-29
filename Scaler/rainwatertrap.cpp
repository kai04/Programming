/*
iven n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining. 
Input Format
The only argument given is integer array A.
Output Format
Return the total water it is able to trap after raining..
For Example
Input 1:
    A = [0,1,0,2,1,0,1,3,2,1,2,1]
Output 1:
    6
Explaination 1:

    In this case, 6 units of rain water (blue section) are being trapped.

*/
int Solution::trap(const vector<int> &A) {
    int n = A.size();
    vector<int> lmax(n,-1);
    vector<int> rmax(n,-1);
    for(int i=1;i<n;i++){
        int temp = max(lmax[i-1],A[i-1]);
        if(temp>=A[i])
            lmax[i] = temp;
    }
    
    for(int i=n-2;i>=0;i--){
        int temp = max(rmax[i+1],A[i+1]);
        if(temp>=A[i])
            rmax[i] = temp;
    }
    /*cout<<"printing lmax...."<<endl;
    for(auto it:lmax)
        cout<<it<<" ";
    cout<<endl;
    
    cout<<"printing rmax...."<<endl;
    for(auto it:rmax)
        cout<<it<<" ";
    cout<<endl;*/
    int ans = 0;
    for(int i=0;i<n;i++){
        if(lmax[i]!=-1 && rmax[i]!=-1){
            int temp = min(lmax[i],rmax[i]) - A[i];
            ans +=temp;
            // cout<<"temp:"<<temp<<" ans:"<<ans<<endl;
        }
    }
    return ans;
    
}

