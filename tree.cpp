#include<bits/stdc++.h>
using namespace std;
 struct Node
 {
     int data;
     Node* left, *right;
     
}; 

vector<Node*> child;
void preorder(Node* node){
    if(node==NULL)
        return;
    if(node->left==NULL && node->right==NULL){
        child.push_back(node);
    }
    preorder(node->left);
    preorder(node->right);
    
}
queue<Node*> q1;
void levelOrder(Node * root) {
q1.push(root);
    while(!q1.empty()){
        int x = (q1.front())->data;
        cout<<x<<" ";
        if((q1.front())->left!=NULL)
            q1.push((q1.front())->left);
        if((q1.front())->right!=NULL)
            q1.push((q1.front())->right);
        q1.pop();
    } 
}

int distance(Node* root,Node* chd){
    if(root!=NULL)
    {
        int x=0;
        if((root->data == chd->data) ||(x=distance(root->left,chd))>0 ||(x=distance(root->right,chd))>0){
            return x+1;
        }
    }
        return 0;
}
/*-------------------------------------------------------------------------*/
Node *lca(Node *root, int v1,int v2)
{

    if((root->data >= v1 && root->data <= v2)||(root->data >= v2 && root->data <= v1)){
        return root;
    }
    else if((root->data >= v1) && (root->data >= v2)){
        return lca(root->left,v1,v2);
    }
    else{
        return lca(root->right,v1,v2);
    }
   
}
Node * LCA(Node* root ,int n1 ,int n2 )
{
    if(root==NULL)
        return NULL;
    else if(root->data == n1 || root->data == n2)
        return root;
    Node* nleft = LCA(root->left,n1,n2);
    Node* nright = LCA(root->right,n1,n2);
    if(nleft!=NULL && nright!=NULL)
        return root;
    else if(nleft!=NULL)
        return nleft;
    else if(nright!=NULL)
        return nright;
    else 
        return NULL;

}

void clear( queue<Node*> &q )
{
   queue<Node*> empty;
   swap( q, empty );
}
/*-------------------------------------------------------------------------*/
/*    */
Node * insert(Node * root, int value) {
    if(root==NULL){
        //root= new node(value);
        Node * temp = new Node;
        temp->data = value;
        temp->left =  NULL;
        temp->right =  NULL;
        root = temp;
    }
    else{
        Node *curr;
        if(root->data > value){
            curr = insert(root->left,value);
            root->left = curr;
        }
        else{
            curr = insert(root->right,value);
            root->right = curr;
        }
    }


   return root;
}

/* Do level order traversal if any node found to be null then insert newnode at that position */
queue<Node*> q;
void BTreeInsertion(Node * root,int val) {
q.push(root);
    while(!q.empty()){
        //int x = (q.front())->data;
        //cout<<x<<" ";
        if((q.front())->left!=NULL)
            q.push((q.front())->left);
        else{
            Node* newnode = new Node;
            newnode->left = NULL;
            newnode->right = NULL;
            newnode->data = val;
            if(val==0)
                (q.front())->left = NULL;
            else
                (q.front())->left = newnode;
            clear(q);
            break;
            //return q.front();
        }
        if((q.front())->right!=NULL)
            q.push((q.front())->right);
        else{
            Node* newnode = new Node;
            newnode->left = NULL;
            newnode->right = NULL;
            newnode->data = val;
            if(val==0)
                (q.front())->right = NULL;
            else
                (q.front())->right = newnode;
            clear(q);
            break;
            //return q.front()
        }
        q.pop();
    } 
}
/*-------------------------------------------------------------------------*/

int diameter(Node* node)
{   int maxdist = INT_MIN;
    preorder(node);
    for(int i=0;i<child.size()-1;i++){
        for(int j=i+1;j<child.size();j++){
            Node * ancestor =  LCA(node,child[i]->data,child[j]->data);
            int n1dist = distance(node,child[i]);
            int n2dist = distance(node,child[j]);
            int n2ansc = distance(node,ancestor);
            maxdist = max(maxdist,(n1dist+n2dist-(2*n2ansc)));
        }
    }
    return maxdist;
   // Your code here
}


void printTree(Node* p, int indent)
{
    /*if(p==NULL){
        cout<<"khali he"<<endl;
        return;
    }*/
    if(p != NULL) {
        if(p->right) {
            postorder(p->right, indent+4);
        }
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        if (p->right) 
            std::cout<<" /\n" << std::setw(indent) << ' ';
            std::cout<< p->data << "\n ";
        if(p->left) {
            std::cout << std::setw(indent) << ' ' <<" \\\n";
            postorder(p->left, indent+4);
        }
    }
}

int main(){
    int n,rt;
    cin>>n;
    cin>>rt;
    Node* root = new Node;
    root->left = NULL;
    root->right = NULL;
    root->data = rt;
    for(int i=1;i<n;i++){
        int x;
        cin>>x;
        BTreeInsertion(root,x);
    }
    //levelOrder(root);
    cout<<diameter(root)<<endl;
    return 0;
}

