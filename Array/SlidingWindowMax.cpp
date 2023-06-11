//https://leetcode.com/problems/sliding-window-maximum/description/
class Solution {
public:
    static void printDeque(deque<pair<int,int>> d){
        cout<<"Printing Deque..."<<endl;
        cout<<"[ ";
        while(!d.empty()){
            cout<<"("<<d.front().first<<","<<d.front().second<<") ";
            d.pop_front();
        }
        cout<<"]";
        cout<<endl<<"----------------------------------------"<<endl;
    }
    void insertAtRightPos(deque<pair<int,int>> &v, vector<int> a, int k, vector<int> &ans){
        // cases:
        //case1: last/first element is outside window length than pop elements until first and last 
        //      element are inside window
        //case2: if target element is greater than last element of deque(max element) than
        //       start removing element from last till target is clear deque and insert target
        // case3: first element is smaller than target than start removing element from front till
        //         first element is  smaller and then insert target at first
        //case 4: target element is smaller than first element than insert target at front

        int n = a.size();
        // sort(a.begin(),a.begin()+k);
        vector<pair<int,int>> temp;

        for(int i=0;i<k;i++){
            temp.push_back(make_pair(a[i],i));
        }
        sort(temp.begin(),temp.end());
        for(int i=0;i<k;i++){
            v.push_back(make_pair(temp[i].first,temp[i].second));
        }
        ans.push_back(v.back().first);
        for(int i=1;i<n;i++){
            int j = i+k-1;
            if(j<n){
                int t = a[j];
                // cout<<"Before insert....| i:"<<i<<" j:"<<j<<endl;
                // printDeque(v);
                // cout<<"H1@ i:"<<i<<" j:"<<j<<endl;
                while(!v.empty() && (v.back().second<i || v.back().second>j)) v.pop_back();
                while(!v.empty() && (v.front().second>j ||v.front().second<i)) v.pop_front();
                // cout<<"H2@ i:"<<i<<" j:"<<j<<endl;
                
                if(v.empty()){
                    // cout<<"H3@ i:"<<i<<" j:"<<j<<endl;
                    v.push_front(make_pair(t,j));
                } else if(v.back().second<i || v.back().second>j||t>=v.back().first){
                    // cout<<"H4@ i:"<<i<<" j:"<<j<<endl;
                    while(!v.empty() && (v.back().second<i || v.back().second>j||t>=v.back().first)){
                        // cout<<"H5@ i:"<<i<<" j:"<<j<<endl;
                        v.pop_back();
                    }
                    v.push_back(make_pair(t,j));
                } else if(v.front().second<i || v.front().second>j||t>=v.front().first){
                    // cout<<"H6@ i:"<<i<<" j:"<<j<<endl;
                    while(!v.empty() && (v.front().second<i || v.front().second>j||t>=v.front().first)){
                        // cout<<"H7@ i:"<<i<<" j:"<<j<<endl;
                        v.pop_front();
                    }
                    v.push_front(make_pair(t,j));
                } else if(t<v.front().first){
                    // cout<<"H8@ i:"<<i<<" j:"<<j<<endl;
                    v.push_front(make_pair(t,j));
                } else{
                    // cout<<"H9@ i:"<<i<<" j:"<<j<<endl;
                    cout<<"Something went wrong"<<endl;
                }
                // cout<<"After insert....| i:"<<i<<" j:"<<j<<endl;
                // printDeque(v);
                // cout<<"=============================="<<endl;
                // cout<<"H10@ i:"<<i<<" j:"<<j<<endl;
                ans.push_back(v.back().first);
            }
        }

    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int>> d;
        vector<int> ans;
        insertAtRightPos(d,nums,k,ans);
        return ans;
    }
};