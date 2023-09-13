//https://leetcode.com/problems/sum-of-distances-in-tree/description/
class Solution {
public:
    typedef struct Node{
        vector<Node*> child;
        int val;
        
        Node(int v){
            val =v;
        }
        void addChild(Node* x){
            child.push_back(x);
        }
        
    } Node;
    
    vector<Node*> nodes;
    
    Node* LCA(Node* root, int x1, int x2){
       
        //base case
        if(root->val == x1 || root->val == x2){
            return root;
        }
        
         if((root->child).size()==0){
            return NULL;
        }
        
        vector<Node*> t;
        for(int i=0;i<(root->child).size();i++){
            Node* temp = LCA((root->child)[i], x1,x2);
            if(temp!=NULL){
                // cout<<"Calling LCA("<<(root->child)[i]->val<<")"<<" x1:"<<x1<<" x2:"<<x2<<" root:"<<root->val<<" temp:"<<temp->val<<endl;
                t.push_back(temp);
            } else{
                // cout<<"Calling LCA("<<(root->child)[i]->val<<")"<<" x1:"<<x1<<" x2:"<<x2<<" root:"<<root->val<<" NULL LCA"<<endl;
            }
                
        }
        // cout<<"x1:"<<x1<<" x2:"<<x2<<" T Size:"<<t.size()<<endl;
        if(t.size()==2){
            return root;
        } else if(t.size()==1){
            return t[0];
        } else{
            return NULL;
        }
        
    }
    
    int distance(int x1, int x2, vector<int> &d, Node* root){
        if(x1==x2){
            return 0;
        }
        
        Node* lca = LCA(root, x1,x2);
        int p;
        
        if(lca!=NULL){
            cout<<"x1:"<<x1<<" x2:"<<x2<<" LCA(x1,x2):"<<(lca->val)<<endl;
            p = (d[x1] + d[x2] - 2*d[lca->val]);
        } else {
            cout<<"x1:"<<x1<<" x2:"<<x2<<" No LCA b/w x1,x2"<<endl;
            p=0;
        }
        return p;
    }
    
    void printQ(queue<pair<Node*,int>> q){
        cout<<"Printing Queue....."<<endl<<"[";
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            cout<<"("<<(it.first)->val<<", "<<(it.second)<<") ";
        }
        cout<<"]"<<endl<<"--------------------------------"<<endl;
    }
    void calculateDist(vector<int> &d, int root){
        queue<pair<Node*,int>> q;
        q.push({nodes[root],0});
        while(!q.empty()){
            printQ(q);
            auto it = q.front();
            q.pop();
            for(int i=0;i<((it.first)->child).size();i++){
                q.push({((it.first)->child)[i], it.second+1});
                d[(((it.first)->child)[i])->val] = it.second+1;
            }
        }
    }
    void printDistance(vector<int> &d){
        cout<<"Printing distance from root..."<<endl;
        for(int i=0;i<d.size();i++){
            cout<<"dist["<<i<<"]:"<<d[i]<<endl;
        }
        cout<<"-----------------------"<<endl;
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<int> d(n);
        if(n==0)
            return ans;
        d[0] = 0;
        for(int i =0;i<n;i++){
            nodes.push_back(new Node(i));
        }
        vector<int> rootV(n,true);
        for(int i=0;i<edges.size();i++){
            if(edges[i][0]>edges[i][1]){
                nodes[edges[i][1]]->addChild(nodes[edges[i][0]]);
                rootV[edges[i][0]] = false;
            }
            else{
                nodes[edges[i][0]]->addChild(nodes[edges[i][1]]);
                rootV[edges[i][1]] = false;
            }
                
        }
        int root;
        for(int i=0;i<n;i++){
            if(rootV[i]){
                root = i;
                break;
            }
        }
        calculateDist(d, root);
        printDistance(d);
        for(int i=0;i<n;i++){
            int res = 0;
            for(int j=0;j<n;j++){
                res += distance(i,j,d, nodes[root]);
            }
            ans.push_back(res);
        }
        return ans;
    }

        void dfs1(int u, int parent, vector<vector<int>> &graph, vector<int> &count, vector<int> &res){
        count[u] = 1;
        for(int v:graph[u]){
            if(v != parent){ 
                dfs1(v,u,graph,count,res);
                count[u] +=count[v];
                res[u] += res[v] + count[v];
            }
        }
    }

    void dfs2(int u, int parent, vector<vector<int>> &graph, vector<int> &count, vector<int> &res){
        count[u] = 1;
        int n = count.size();
        for(int v:graph[u]){
            if(v != parent){ 
                res[v] = res[u] - count[v] + n - count[v];
                dfs2(v,u,graph,count,res);
            }
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> ans(n,0),res(n,0);
        vector<vector<int>> graph(n);
        vector<int> count(n,0);
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        dfs1(0, -1, graph, count, res);
        dfs2(0, -1, graph, count, res);
        // for(int i=0;i<n;i++){
        //     cout<<"i:"<<i<<" count[i]:"<<count[i]<<" res[i]:"<<res[i]<<endl;
        // }
        return res;
    }
};