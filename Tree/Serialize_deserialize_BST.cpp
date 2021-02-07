//https://leetcode.com/problems/serialize-and-deserialize-bst/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

static vector<string> split(const string& s, char delimiter)
{
   vector<string> tokens;
   string token;
   istringstream tokenStream(s);
   while (getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token);
   }
   return tokens;
}
class Codec {
public:
    
    // Encodes a tree to a single string.
    void level_order(TreeNode* root,vector<string> &ret){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            string curr = std::to_string(temp->val);
            string leftChild("N");
            string rightChild("N");
            if(temp->left!=NULL){
                leftChild = std::to_string((temp->left)->val);
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                rightChild = std::to_string((temp->right)->val);
                q.push(temp->right);
            }
            ret.push_back(curr);
            ret.push_back(leftChild);
            ret.push_back(rightChild);
            q.pop();
        }
    }
    string serialize(TreeNode* root) {
        if(root==NULL)
            return "";
        vector<string> ret;
        level_order(root,ret);
        string ans = "";
        for(int i=0;i<ret.size();i++){
            if(i==0){
                ans = ans + ret[i];
            }
            else{
                ans = ans + string(",");
                ans = ans + ret[i];
            }
        }
        // cout<<"Serialize string:"<<ans<<endl;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length()==0)
            return NULL;
        vector<string> d = split(data,',');
        TreeNode *root;
        unordered_map<int,TreeNode*> m;
        for(int i=0;i<d.size();i=i+3){
            if(i==0){
                TreeNode *lchild=NULL;
                TreeNode *rchild=NULL;
                stringstream ss1(d[i]);
                int x1;
                ss1>>x1;
                root = new TreeNode(x1);
                if(d[i+1]!="N"){
                    // cerr<<"h1"<<endl;
                    stringstream ss2(d[i+1]);
                    int x2;
                    ss2>>x2;
                    lchild = new TreeNode(x2);
                    m[x2] = lchild;
                }
                if(d[i+2]!="N"){
                    stringstream ss3(d[i+2]);
                    int x3;
                    ss3>>x3;
                    rchild = new TreeNode(x3);
                    m[x3] = rchild;
                }
                
                root->left = lchild;
                root->right = rchild;
            }
            else{
                TreeNode *lchild=NULL;
                TreeNode *rchild=NULL;
                stringstream ss1(d[i]);
                int x1;
                ss1>>x1;
                TreeNode *root1 = m[x1];
                if(d[i+1]!="N"){
                    stringstream ss2(d[i+1]);
                    int x2;
                    ss2>>x2;
                    lchild = new TreeNode(x2);
                    m[x2] = lchild;
                }
                if(d[i+2]!="N"){
                    stringstream ss3(d[i+2]);
                    int x3;
                    ss3>>x3;
                    rchild = new TreeNode(x3);
                    m[x3] = rchild;
                }
                root1->left = lchild;
                root1->right = rchild;
            }
            
            
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;