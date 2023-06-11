#include <bits/stdc++.h>
using namespace std;

class TreeAncestor
{
public:
    vector<vector<int>> ancestor;
    TreeAncestor(int n, vector<int> &parent)
    {
        int R = ceil(log(n) / log(2));
        ancestor.resize(n, vector<int>(R + 1, -1));
        for (int i = 0; i < n; i++)
        {
            ancestor[i][0] = parent[i];
        }

        for (int j = 1; j <= R; j++)
        {
            for (int i = 0; i < n; i++)
            {
                int lift = ancestor[i][j - 1];
                if(lift>=0 && lift<n)
                    ancestor[i][j] = ancestor[lift][j - 1];
            }
        }
    }

    int getKthAncestor(int node, int k)
    {
        int n = ancestor.size();
        if (node >= n || ancestor[node].size()< k)
        {
            return -1;
        }
        return ancestor[node][k-1];
    }
};

int main()
{
    int n,node,k;
    cin>>n;
    vector<int> parent(n);
    for(int i=0;i<n;i++){
        cin>>parent[i];
    }
    cin>>node>>k;
    TreeAncestor* obj = new TreeAncestor(n, parent);
    for(int i =0;i<obj->ancestor.size();i++){
        for(int j = 0; j< obj->ancestor[i].size();j++){
            cout<<obj->ancestor[i][j]<<" ";
        }
        cout<<endl;
    }
    int param_1 = obj->getKthAncestor(node,k);
    cout<<param_1<<endl;
    return 0;
}