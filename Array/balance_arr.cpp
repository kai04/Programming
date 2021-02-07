//https://www.interviewbit.com/problems/balance-array/
int Solution::solve(vector<int> &A) {
    int n =  A.size();
    vector<int> evenL(n,0),evenR(n,0),oddL(n,0),oddR(n,0);
    evenL[0] = A[0];
    oddL[0] = 0;
    for(int i=1;i<n;i++){
        if(i%2==0){
            evenL[i] = evenL[i-1] + A[i];
            oddL[i] = oddL[i-1];
        }
        else{
            oddL[i] = oddL[i-1] + A[i];
            evenL[i] = evenL[i-1];
        }
    }
    if(n%2==1){
        evenR[n-1] = A[n-1];
        oddR[n-1] = 0;    
    }
    else{
        evenR[n-1] = 0;
        oddR[n-1] = A[n-1];
    }
    
    for(int i=n-2;i>=0;i--){
        if(i%2==0){
            evenR[i] = evenR[i+1] + A[i];
            oddR[i] = oddR[i+1];
        }
        else{
            oddR[i] = oddR[i+1] + A[i];
            evenR[i] = evenR[i+1];
        }
    }
    /*cout<<"EVEN L:"<<endl;
    for(auto it:evenL)
        cout<<it<<" ";
    cout<<endl<<"-----------------------------"<<endl;
    
    cout<<"ODD L:"<<endl;
    for(auto it:oddL)
        cout<<it<<" ";
    cout<<endl<<"-----------------------------"<<endl;
    
    cout<<"EVEN R:"<<endl;
    for(auto it:evenR)
        cout<<it<<" ";
    cout<<endl<<"-----------------------------"<<endl;
    
    cout<<"ODD R:"<<endl;
    for(auto it:oddR)
        cout<<it<<" ";
    cout<<endl<<"-----------------------------"<<endl;
    */
    
    int cnt = 0;
    for(int i=0;i<n;i++){
        int evenset=0,oddset = 0;
        if(i%2==0){
            evenset = evenL[i]-A[i] + oddR[i];
            oddset = oddL[i] + evenR[i]-A[i];
        }
        else{
            evenset = evenL[i] + oddR[i]-A[i];
            oddset = oddL[i] -A[i]+ evenR[i];
        }
        if(evenset==oddset){
            cnt++;
        }
        // cout<<"i:"<<i<<" A[i]:"<<A[i]<<" evenL[i]:"<<evenL[i]<<" oddL[i]:"<<oddL[i]<<" evenR[i]:"<<evenR[i]<<" oddR[i]:"<<oddR[i]<<endl;
    }
    return cnt;
}
