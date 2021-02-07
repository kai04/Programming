//https://www.interviewbit.com/problems/flip/

vector<int> Solution::flip(string A) {
    int n = A.length();
    vector<int> cnt_1(n+1,0);
    vector<int> cnt_0(n+1,0);
    for(int i=1;i<=n;i++){
        if(A[i-1]=='1'){
            cnt_1[i] = cnt_1[i-1]+1;
            cnt_0[i] = cnt_0[i-1];
        }
        if(A[i-1]=='0'){
            cnt_0[i] = cnt_0[i-1]+1;
            cnt_1[i] = cnt_1[i-1];
        }
    }
  
    vector<int> ans_pair(2);
    int i=0,j=1;
    int diff = 0;
    while(i<=j && j<=n && i<=n){
        int count1s = cnt_1[j] - cnt_1[i];
        int count0s = cnt_0[j] - cnt_0[i];
        int curr_diff = (count0s - count1s);
        if(curr_diff<0){
            while(i<j && curr_diff<0){
                count1s = cnt_1[j] - cnt_1[i];
                count0s = cnt_0[j] - cnt_0[i];
                curr_diff = (count0s - count1s);
                i++;
            }
        }
        // cout<<"i:"<<i<<" j:"<<j<<" curr diff:"<<curr_diff<<" diff:"<<diff<<endl;
        if(curr_diff>diff){
            diff = curr_diff;
            ans_pair[0] = i+1;
            ans_pair[1] = j;
            
        }
        j++;
    }
    if(ans_pair[0]==0 && ans_pair[0]==0){
        vector<int> null_vec;
        return null_vec;
    }
    return ans_pair;
}

