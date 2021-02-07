//https://www.interviewbit.com/problems/add-one-to-number/
vector<int> Solution::plusOne(vector<int> &A) {
    int n = A.size();
    if(A[n-1]==9){
        int j = n-1;
        while(j>=0 && A[j]==9){
            A[j] = 0;
            j--;
        }
        
        if(j>=0)
            A[j]++;
        else{
            A.insert(A.begin(),1);
        }
    }
    else{
        A[n-1]++;
    }
    //remove leading zeros
    int k =0;
    for(int i=0;i<n;i++){
        if(A[i]==0){
            k++;
        }
        else{
            break;
        }
    }
    if(k>0)
        A.erase(A.begin(),A.begin()+k);
    return A;
}
