//https://www.interviewbit.com/problems/first-missing-integer/
int Solution::firstMissingPositive(vector<int> &A) {
    int n = A.size();
    int i = 0, j = n-1;
    while(i<n && j>=0 && i<j){
        while(i< n && A[i]>0){
            i++;
        }
        while(A[j]<=0){
            j--;
        }
        //swap
        if(i<j){
            int temp  = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    int new_n = n;
    for(int i=0;i<n;i++){
        if(A[i]<=0){
            new_n = i;
            break;
        }
    }
    
   /* 
   cout<<"BEFORE:"<<endl;
   for(auto it: A)
        cout<<it<<" ";
    cout<<endl<<"------------------------------"<<endl;
    cout<<"NEW N:"<<new_n<<endl;
    */
    
    if(new_n==0)
        return 1;
    
    for(int i=0;i<new_n;i++){
        // cout<<"i:"<<i<<" A[i]:"<<abs(A[i])<<" A[abs(A[i])-1]:"<<A[abs(A[i])-1]<<endl;
        if(abs(A[i])<=n && A[abs(A[i])-1] > 0){
            A[abs(A[i])-1] = -1*A[abs(A[i])-1];
        }
    }
    int ans = -1;
    for(int i=0;i<n;i++){
        if(A[i]>0){
            ans = i;
            break;
        }
    }
    /*cout<<"AFTER:"<<endl;
    for(auto it: A)
        cout<<it<<" ";
    cout<<endl<<"------------------------------"<<endl;*/
    if(ans==-1){
        return n+1;
    }
    return ans+1;
}
