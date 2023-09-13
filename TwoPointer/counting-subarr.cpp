//https://www.interviewbit.com/problems/counting-subarrays/
int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int cnt=0;
    int i =0;
    int j=0;
    int s = A[0];
    while(i<n && j<n){
        if(s<B){
           j++;
           cnt+=max(0,j-i);
           s+=A[j]; 
        }
        if(s>=B){
           s-=A[i];
           i++; 
        }
    }
    
    return cnt;
}
