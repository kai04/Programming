//https://leetcode.com/problems/next-greater-element-i/description/
class Solution {
public:
    void printStack(stack<pair<int,int>> s){
        cout<<"Printing stack ...."<<endl;
        while(!s.empty()){
            pair<int,int> p = s.top();
            cout<<p.first<<" ";
            s.pop();
        }
        cout<<endl<<"---------------------------"<<endl;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        int n = nums2.size();
        for(int i=0;i<nums2.size();i++){
            m[nums2[i]] = i;
        }
        vector<int> nge(n,-1);
        stack<pair<int,int>> s;
        for(int i=0;i<nums2.size();i++){
            if(s.empty()){
                s.push(make_pair(nums2[i],i));
            } else{
                pair<int,int> t = s.top();
                if(t.first>nums2[i]){
                    s.push(make_pair(nums2[i],i));                    
                } else {
                    while(!s.empty() && s.top().first<nums2[i]){
                        nge[s.top().second] = i;
                        s.pop();
                    }
                    s.push(make_pair(nums2[i],i));
                }
            }
            // cout<<"Element:"<<nums2[i]<<" Index:"<<i<<endl;
            // printStack(s);
        }
        // for(auto p:nge){
        //     if(p!=-1)
        //         cout<<nums2[p]<<" ";
        //     else
        //         cout<<-1<<" ";
        // }   
        // cout<<endl;
        vector<int> ret(nums1.size(),-1);
        for(int i=0;i<nums1.size();i++){
            if(nge[m[nums1[i]]] !=-1)
            ret[i] = nums2[nge[m[nums1[i]]]];
        }
        return ret;
    }
};