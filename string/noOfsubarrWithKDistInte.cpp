#include<bits/stdc++.h>
using namespace std;
 
    int subarraysWithKDistinct(vector<int>& s, int K) {
        map<int,int> count;
        int n = s.size();
        if(n<=1){
            return n;
        }
        int lo=0;
        int ans=0;
        int curr_len=0;
        for(int hi=0;hi<n;hi++){
            count[s[hi]]++;
            
            while(count.size()>K && count.size()){
                if(lo<=hi && count[s[lo]]>0)
                    count[s[lo]]--;
                
                if(count[s[lo]] ==0){
                    count.erase(s[lo]);
                }
                if(count.size()==K){
                cout<<"lo:"<<lo<<" hi:"<<hi<<endl;
                ans++;
                }
                lo++;
            }
            
            if(count.size()==K){
                cout<<"lo:"<<lo<<" hi:"<<hi<<endl;
                ans++;
            }
        }
        return ans;
    }



int main(){
    int n,k;
    cin>>n>>k;
   vector<int> a(n);
   for(int i=0;i<n;i++){
    cin>>a[i];
   }
   int ans = subarraysWithKDistinct(a,k);
   cout<<"ANS:"<<ans<<endl;
    return 0;
}