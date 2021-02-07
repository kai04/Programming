
//https://www.interviewbit.com/problems/maximum-unsorted-subarray/
vector<int> Solution::subUnsort(vector<int> &A) {
    int n = A.size();
    bool flag = false;
    int lpos = 0,rpos=n-1;
    for(int i=0;i<n-1;i++){
        if(A[i]>A[i+1]){
            lpos = i;
            flag = true;
            break;
        }
    }
    
    for(int i=n-1;i>0;i--){
        if(A[i]<A[i-1]){
            rpos = i;
            flag = true;
            break;
        }
    }
    
    // cout<<"XXXX_LPOS:"<<lpos<<" RPOS:"<<rpos<<endl;
    int y=INT_MIN,x=INT_MAX;
    for(int i=lpos;i<=rpos;i++){
        x = min(x,A[i]);
        y = max(y,A[i]);
    }
    int p=lpos,q=rpos;
    for(int i=0;i<p;i++){
        if(A[i]>x){
            lpos = i;
            flag = true;
            break;
        }
    }
    
    for(int i=n-1;i>rpos;i--){
        if(A[i]<y){
            rpos = i;
            flag = true;
            break;
        }
    }
    
    // cout<<"YYYY_LPOS:"<<lpos<<" RPOS:"<<rpos<<" X:"<<x<<" Y:"<<y<<endl;
    vector<int> res;
    lpos = min(lpos,rpos);
    rpos = max(lpos,rpos);
    if(lpos==0 && rpos==n-1 && !flag){
        res.push_back(-1);
    }
    else{
        res.push_back(lpos);
        res.push_back(rpos);
    }
    
    
    return res;
    
}
