//https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/
bool isPallindrome(string s){
    int n = s.length();
    int i =0;
    int j = n-1;
    while(i<=j){
        if(s[i]==s[j]){
            i++;
            j--;
        }
        else{
            return false;
        }
    }
    return true;
}
int LPS(string s){
    int n = s.length();
    int m = (n-1)/2;
    vector<int> lps(n,0);
    int i=0;
    int max1 = 0;
    for(int j=1;j<n;){
        if(s[i]==s[j]){
            lps[j] = i+1;
            i++;
            j++;
            //max1 = max(max1,lps[j]);
            //cout<<"j:"<<j<<" max1:"<<max1<<" lps[j]:"<<lps[j]<<endl;
        }
        else{
            if(i!=0){
                i = lps[i-1];
            }
            else{
                lps[j] = 0;
                j++;
            }
        }
    }
    for(int p=0;p<=n;p++){
        max1 =max(max1,lps[p]);
        //cout<<lps[p]<<" ";
    }
    //cout<<endl;
    
    return max1;
}

int Solution::solve(string A) {
    if(isPallindrome(A))
        return 0;
    string s1 = A;
    int m = A.length();
    reverse(A.begin(),A.end());
    s1 = s1 +"#";
    s1 = s1 + A;
    int x = LPS(s1); 
    // cout<<"X:"<<x<<" m:"<<m<<endl;
    int ans = m-x;
    return ans;
}

