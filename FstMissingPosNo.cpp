//https://www.geeksforgeeks.org/find-the-smallest-positive-number-missing-from-an-unsorted-array/

#include <bits/stdc++.h>
using namespace std;

void swap(int a,int b,vector<int>& nums){
        int temp=nums[a];
        nums[a]=nums[b];
        nums[b]=temp;
    }
    int firstMissingPositive(vector<int>& nums) {
        int size1=nums.size();
        if(size1==0)
            return 1;
        //seggregate all negative values to left side
        int j=0;
        for(int i=0;i<size1;i++){
            if(nums[i]<=0){
                swap(i,j,nums);
                j++;
            }
        }
        if(j>size1-1)
            return size1;
        // cout<<"j:"<<j<<endl;
        // for(auto it:nums)
        //     cout<<it<<" ";
        // cout<<endl<<"----------------------------"<<endl;
        //marking all positive no less than size of array(Note:new size = size1-j)
        for(int val=j;val<size1;val++){
            if((abs(nums[val])-1+j)<size1 && nums[abs(nums[val])-1+j]>0){
                nums[abs(nums[val])-1+j]=-nums[abs(nums[val])-1+j];
            }
        }
        // for(auto it:nums)
        //     cout<<it<<" ";
        // cout<<endl<<"----------------------------"<<endl;
        for(int val=j;val<size1;val++){
            if(nums[val]>0){
                return (val-j+1);
            }
            
            
        }
         return size1-j+1;
    }

int main() {
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    cout<<firstMissingPositive(a)<<endl;
    }
    //code
    return 0;
}