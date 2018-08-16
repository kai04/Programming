
//https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/
#include<bits/stdc++.h>
class Solution {
public:
    void myprint(vector<int> vec){
        for(auto it:vec)
            cout<<it<<" ";
        cout<<endl<<"================================="<<endl;
    }
    vector<vector<int>> partition(vector<int> arr,int k){
        vector<int> c;
        vector<int> d;
        for(int i=0;i<arr.size();i++){
            if(arr[i]&(1<<(k))){
                c.push_back(arr[i]);
            }
            else{
                d.push_back(arr[i]);
            }
        }
        vector<vector<int>> ret;
        ret.push_back(d);
        ret.push_back(c);
        return ret;
    }
    
    int getMaxXor(vector<int> set0,vector<int> set1,int k){
        if(k<0 ||set0.size()==0 ||set1.size()==0){
            return 0;
        } 
        vector<vector<int>> set0list=partition(set0,k);
        vector<vector<int>> set1list=partition(set1,k);
        vector<int> set0list0=set0list[0];
        vector<int> set0list1=set0list[1];
        vector<int> set1list0=set1list[0];
        vector<int> set1list1=set1list[1];
        // cout<<"for value of k:"<<k<<endl;
        // cout<<"set0list0 printing ...."<<endl;
        // myprint(set0list0);
        // cout<<"set0list1 printing ...."<<endl;
        // myprint(set0list1);
        // cout<<"set1list0 printing ...."<<endl;
        // myprint(set1list0);
        // cout<<"set1list1 printing ...."<<endl;
        // myprint(set1list1);
        // cout<<"---------------------------------"<<endl;
        if((set0list0.size()==0 && set1list0.size()==0) || (set0list1.size()==0 && set1list1.size()==0)){
            return (getMaxXor(set0,set1,k-1));
        }
        else{
            return (pow(2,k)+max((getMaxXor(set0list1,set1list0,k-1)),(getMaxXor(set0list0,set1list1,k-1))));
        }
        
    }
    
    
    int findMaximumXOR(vector<int>& nums) {
        if(nums.size()==0 ||nums.size()==1){
            return 0;
        }
        if(nums.size()==2){
            return (nums[0]^nums[1]);
        }
        
        int k,j;
        int ans=0;
        vector<int> set0;
        vector<int> set1;
         for (k = 30; k >= 0; k--) {
            for (j = 0; j < nums.size(); j++) {
                if ((nums.at(j) & (1<<k)) == 0)
                    set0.push_back(nums.at(j));
                else
                    set1.push_back(nums.at(j));
            }
            
            if (set0.size() != 0 && set1.size() != 0) {
                ans = pow(2, k);
                break;
            }
            else {
                set0.clear();
                set1.clear();
            }
        }
        
            if(k==-1)
                return 0;
        
        // cout<<"k:"<<k<<endl;
        // cout<<"set0 printing ...."<<endl;
        // myprint(set0);
        // cout<<"set1 printing ...."<<endl;
        // myprint(set1);
        ans+=getMaxXor(set0,set1,k-1);
        return ans;
    }
};
