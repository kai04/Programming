//https://leetcode.com/contest/weekly-contest-126/problems/max-consecutive-ones-iii/
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int curr_max=0,stream_max=0;
        int i=0,j=0;
        int n = A.size();
        int k=K;
        while(i<=j && j<n){
            // cout<<"BEFORE---->>> "" i:"<<i<<" j:"<<j<<" k:"<<k<<" curr_max:"<<curr_max<<" stream_max:"<<stream_max<<endl;
            if(A[j]==1){
                curr_max++;
                j++;
            }
            else if(A[j]==0 && k>0){
                k--;
                j++;
                curr_max++;
            }
            else{
                while(i<j && k==0){
                    if(A[i]==1){
                        curr_max--;
                    }
                    else{
                        // k++;
                        i++;
                        break;
                    }
                    i++;
                }
                j++;
            }
            stream_max = max(stream_max,curr_max);
             // cout<<"AFTER----->>> "" i:"<<i<<" j:"<<j<<" k:"<<k<<" curr_max:"<<curr_max<<" stream_max:"<<stream_max<<endl;
            // cout<<"====================================================="<<endl;
        }
        return stream_max;
    }
};
