//https://www.interviewbit.com/problems/subarrays-with-distinct-integers/
int subArrWithAtmostK(vector<int> &A, int k){
    int n = A.size();
    int i=0,j=0;
    unordered_map<int,int> m;
    int res = 0;
    while(j<n){
        m[A[j]]++;
        if(m.size()<=k){
            int cnt = j-i+1;
            res += cnt;
            j++;    
        } else{
            while(i<=j && m.size()>k){
                m[A[i]]--;
                if(m[A[i]]==0){
                    m.erase(A[i]);
                }
                i++;
            }
            int cnt = j-i+1;
            res += cnt;
            j++;
        }
        
    }    
    return res;
}

int Solution::solve(vector<int> &A, int B) {
    int d1 = subArrWithAtmostK(A,B);
    int d2 = subArrWithAtmostK(A,B-1);
    return (d1-d2);
}
