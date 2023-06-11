//https://leetcode.com/problems/kth-ancestor-of-a-tree-node/
class TreeAncestor {

public:
    vector<vector<int>> ancestor;
    TreeAncestor(int n, vector<int>& parent) {
        int R = ceil(log(n) / log(2));
        ancestor.resize(n, vector<int>(R + 1, -1));
        for (int i = 0; i < n; i++)
        {
            ancestor[i][0] = parent[i];
        }

        for (int j = 1; j < R; j++)
        {
            for (int i = 1; i < n; i++)
            {
                int lift = ancestor[i][j - 1];
                if(lift>=0 && lift<n)
                    ancestor[i][j] = ancestor[lift][j - 1];
            }
        }
        // for(int i=0;i<n;i++){
        //     for (int j = 0; j <= R; j++){
        //         cout<<ancestor[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
    }
    
    int getKthAncestor(int node, int k) {
        int n = ancestor.size();
        int ans=-1;
        int R = ceil(log(n) / log(2));
        for(int j=0;j<=R;j++){
            if(k & (1<<j)){
                node = ancestor[node][j];
                if(node>=0){
                    ans = node;
                } else{
                    ans =-1;
                    break;
                }
            }
        }
        return ans;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */