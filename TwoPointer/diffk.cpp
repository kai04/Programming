//https://www.interviewbit.com/problems/diffk/
int Solution::diffPossible(vector<int> &A, int B) {
    int n = A.size();
    int j=0,i=1;
    while(i<n && j<n){
        if(A[i]-A[j]<B){
            i++;
        } else if(A[i]-A[j]>B){
            j++;
        } else{
            return 1;
        }
        if(j==i){
            i++;
        }
    }
    return 0;
}
