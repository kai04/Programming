//https://leetcode.com/problems/next-permutation/description/
class Solution {
public:
    void nextPermutation(vector<int>& a) {
        // 12345 -> 12354 -> 12453 
        // 1258763 -> 126[8753] -> [1263578]
        //1253678
        // 132
        int n = a.size();
        
        int i=n-1;
        while(i>0 && a[i-1]>=a[i]){i--;}
        
        if(i<=0){
            sort(a.begin(), a.end());
        } else{
            sort(a.begin()+i, a.end());
            // cout<<"i:"<<i<<endl;
            // for(auto x:a)
            //     cout<<x<<" ";
            // cout<<endl<<"-------------------------"<<endl;
            // cout<<"Search:"<<a[i-1]<<endl;
            auto it = upper_bound(a.begin()+i, a.end(), a[i-1]);
            if(it!=a.end()){
                int j = it - a.begin();
                int t  = a[i-1];
                
                // cout<<"i:"<<i<<" j:"<<j<<" IT:"<<*it<<endl;
                a[i-1] = a[j];
                a[j] = t;
            } else{
                sort(a.begin(), a.end());
            }
        }
    }
};