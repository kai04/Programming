//https://leetcode.com/problems/find-peak-element/
class Solution {
public:
    int findPeakElement(vector<int>& a) {
        int n = a.size();
        int l = 0;
        int r = n-1;
        int ret = -1;
        if(n==1)
            return 0;
        while(l<r){
            int m = l + (r-l)/2;
            // cout<<"l:"<<l<<" r:"<<r<<" m:"<<m<<endl;
            if(m==0||m==n-1)
            {
                break;
            }
            if(a[m]>a[m-1] && a[m]>a[m+1]){
                ret = m;
                break;
            } else if(a[m-1]>a[m]){
                r = m;
            } else if(a[m+1]>a[m]){
                l = m+1;
            }
        }
        if(a[0]>a[1])
        {
            ret = 0;
        }
        
        if(a[n-1]>a[n-2])
        {
            ret = n-1;
        }
        return ret;
    }
};