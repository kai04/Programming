#include <bits/stdc++.h>
using namespace std;
vector<int> seg(0);
vector<pair<int,int>> nbound(0);
 void NumArray(vector<int> nums) {
        int n = nums.size();
        int k = log(n)/log(2);
        int size= 2*(pow(2,k+1));
        
     //cout<<"n:"<<n<<" k:"<<k<<" size:"<<size<<endl;
        seg.resize(size,0);
            int r=0;
        for(int i=(size/2);i<(size/2)+n;i++){
            seg[i]=nums[r];
            r++;
        }
        for(int i=(size/2)-1;i>0;i--){
        int left = 2*i;
        int right = 2*i+1;
        seg[i]=(seg[left]+seg[right]);
        }
        //for(auto it:seg){
        //    cout<<it<<" ";
        //}
        //cout<<endl;
        int height = log(size)/log(2);
        for(int indx=1;indx<size;indx++){
            int level = (log(indx)/log(2))+1;
            int nodes = pow(2,level-1);
            int p = indx%nodes;
            int range=pow(2,height-level);
            pair<int,int> pr=make_pair((p*range+1),(p+1)*range);
            //nbound[indx]=p;
            nbound.push_back(pr);
        }
     /*int v=1;
     for(auto it:nbound){
            cout<<"v:"<<v<<" ->  ( "<<it.first<<" , "<<it.second<<" )"<<endl;
         v++;
        }*/
    }
    int val(int root,int v){
       return 0;
    }
    void update(int i, int val) {
        
    }
    
    int sumRange(int i, int j) {
        return 0;
        
    }

int main(){
    int q;
    cin >> q;
    vector<int> nums(q);
    for(int a0 = 0; a0 < q; a0++){
        cin >> nums[a0];
    }
    NumArray(nums);
   
    return 0;
}

