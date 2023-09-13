//https://leetcode.com/problems/median-of-two-sorted-arrays/description/?envType=list&envId=et1nvip3
class Solution {
public:
    void swap(vector<int> &x,vector<int> &y){
        vector<int> temp = x;
        x = y;
        y = temp;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(n>m){
            swap(nums1, nums2);
            n = nums1.size();
            m = nums2.size();
        }
        int sz = n+m;
        

        /*
            A = [1 3 4 7 10 12]
            B = [2 3 6 15]
            C = [1 2 3 3 4 6 7 10 12 15]

            l1 = [1 3 4] r1 = [7 10 12]
            l2 = [2 3] r2 = [6 15]

            l1 = [1 3] r1 = [4 7 10 12]
            l2 = [2 3 6] r2 = [15]

            l1 = [1 3 4 7] r1 = [10 12]
            l2 = [2] r2 = [3 6 15]

            A = [1 3 4 7 10]
            B = [2 3 6 15]
            C = [1 2 3 3 4 6 7 10 15]

            l1 = [1 3 4] r1 = [7 10]
            l2 = [2] r2 = [3 6 15]

            l1 = [1 3] r1 = [4 7 10]
            l2 = [2 3] r2 = [6 15]

            l1 = [1] r1 = [3 4 7 10]
            l2 = [2 3 6] r2 = [15]

        */
        double med;
        // for(auto it1:nums1){
        //     cout<<it1<<" ";
        // }
        // cout<<endl;
        // for(auto it2:nums2){
        //     cout<<it2<<" ";
        // }
        // cout<<endl;
        int low = 0,high = min(n, (sz/2)+1);
        if(m==0){
            if(sz%2==0){
                med = (double)(nums1[sz/2] + nums1[(sz/2)-1])/2.0;
            } else{
                med = (double) nums1[sz/2];
            }
            return med;
        } else if(n==0){
            if(sz%2==0){
                med = (double)(nums2[sz/2] + nums2[(sz/2)-1])/2.0;
            } else{
                med = (double) nums2[sz/2];
            }
            return med;
        }
        while(low<=high){
            int mid = low+(high-low)/2;
    
            int cut1 = mid;
            int cut2 = max(0,min(((sz+1)/2) - cut1,m));
            // cout<<"size:"<<sz<<" low:"<<low<<" high:"<<high<<" mid:"<<mid<<" cut1:"<<cut1<<" cut2:"<<cut2<<endl;
            int left1 = (cut1==0 ? INT_MIN : nums1[cut1-1]);
            int left2 = (cut2==0 ? INT_MIN : nums2[cut2-1]);

            int right1 = (cut1>=n ? INT_MAX : nums1[cut1]);
            int right2 = (cut2>=m ? INT_MAX : nums2[cut2]);
            // cout<<"left1:"<<left1<<" right1:"<< right1<<" left2:"<<left2<<" right2:"<<right2<<endl;
            // cout<<"-----------------------------"<<endl;

            //base case
            if(left1<=right2 && left2<=right1){
                if(sz%2==0){
                    med = (max(left1,left2) + min(right1, right2))/2.0;
                    return med;
                    
                } else{
                    med = (double)max(left1, left2);
                    return med;
                }
                break;
            } else if(left1> right2){
                high = mid -1; 
            } else {
                low = mid + 1;
            }
        }
        return 0.0;
    }
};