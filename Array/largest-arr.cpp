//https://www.interviewbit.com/problems/largest-number/
static int quick_pow10(int n)
{
    static int pow10[10] = {
        1, 10, 100, 1000, 10000, 
        100000, 1000000, 10000000, 100000000, 1000000000
    };

    return pow10[n]; 
}

static bool comp(int x,int y){
    if(x==0){
        return true;
    }
    else if(x==0){
        return true;
    }
    int sz1 = floor(log10(x) + 1);
    int sz2 = floor(log10(y) + 1);
    long long pehla = x + y*quick_pow10(sz1);
    long long dusra = y + x*quick_pow10(sz2);
    // cout<<"X:"<<x<<" y:"<<y<<" sz1:"<<sz1<<" sz2:"<<sz2<<" pehla:"<<pehla<<" dusra:"<<dusra<<endl;
    if(pehla>=dusra){
        return true;
    }
    return false;
}
string Solution::largestNumber(const vector<int> &A) {
    string ans = "";
    int n = A.size();
    vector<int> a(n);
    for(int i=0;i<n;i++){
        a[i] = A[i];
    }
    sort(a.begin(),a.end(),comp);
    for(int i=n-1;i>=0;i--){
        stringstream ss;
        ss << a[i];
        ans = ans+ss.str();
    }
    int k=0;
    for(int i=0;i<ans.size()-1;i++){
        if(ans[i]=='0'){
            k++;
        }
        else{
            break;
        }
    }
    // cout<<"k:"<<k<<endl;
    ans.erase(0,k);
    return ans;
}
