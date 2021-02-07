//https://leetcode.com/problems/wiggle-sort-ii/
class Solution {
public:
    void wiggleSort(vector<int>& a) {
        int n = a.size();
        sort(a.begin(),a.end());
        vector<bool> fill(n,false);
        float med = 0.0f;
        if(n%2==0){
            med = (float)(a[(n/2)] + a[(n/2)-1])/2;
        }
        else{
            med = (float) a[n/2];
        }
        int cnt = 0;
        // cout<<"MEDIAN:"<<med<<endl;
        vector<int> lmed,rmed;
        for(int i=0;i<n;i++){
            if(a[i]<med){
                lmed.push_back(a[i]);
            }
            else if(a[i]>med){
                rmed.push_back(a[i]);
            }
            else{
                cnt++;
            }
        }
        while(lmed.size()!=rmed.size()){
            if(lmed.size()<rmed.size()){
                lmed.push_back(med);
            }
            else{
                rmed.push_back(med);
            }
            cnt--;
        }
        bool flag = true;
        while(cnt>0){
            if(flag){
                lmed.push_back(med);
            }
            else{
                rmed.push_back(med);
            }
            flag = !flag;
            cnt--;
        }
        sort(lmed.begin(),lmed.end());
        sort(rmed.begin(),rmed.end());
        /*for(auto it:lmed)
            cout<<it<<" ";
        cout<<endl;
        
        for(auto it:rmed)
            cout<<it<<" ";
        cout<<endl;*/
        int i = 0;
        int p =lmed.size()-1,q=rmed.size()-1;
        while(i<n){
            if(i%2==0 && p>=0){
                a[i] = lmed[p];
                p--;
            }
            else if(i%2==1 && q>=0){
                a[i] = rmed[q];
                q--;
            }
            else{
                cout<<"ERROR"<<p<<" "<<q<<endl;
            }
            i++;
        }
        
        
    }
};
