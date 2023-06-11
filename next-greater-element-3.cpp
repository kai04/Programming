//https://leetcode.com/problems/next-greater-element-iii/description/
class Solution {
public:
    int nextGreaterElement(int n) {
        int t = n;
        vector<int> x;
        while(t>0){
            int p = t%10;
            x.push_back(p);
            t = t /10;
        }
        reverse(x.begin(),x.end());

        int sz = x.size();
        // cout<<"Size:"<<sz<<endl;
        // 253265432 253223456 -> 25332456
        // 253232456
        int i = sz-1;
        while(i>0){
            if(x[i-1]<x[i]){
                i--;
                break;
            }
            i--;
        }

        int ix = -1;
        int ii = INT_MAX;
        for(int j=i+1;j<sz;j++){
            if(x[j]>x[i] && x[j]<ii){
                ii = x[j];
                ix = j;
            }
        }
        if(ix==-1){
            return -1;
        }
        // cout<<"Pivot IX:"<<ix<<endl;
        x[ix] = x[i];
        x[i] = ii;
        sort(x.begin()+i+1,x.end());

        int ret = 0;
        //123
        // 1*10^2 + 0 = 100 -> 2*10^1+100=120 -> 3*10*0 + 120 = 123
        for(int j=0;j<sz;j++){
            int long p = x[j]* pow(10, (sz-1-j)) + ret;
            if(p>INT_MAX){
                return -1;
            }
            ret = (int) p;
        }

        return ret;
    }
};