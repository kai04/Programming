//https://www.geeksforgeeks.org/print-nodes-distance-k-given-node-binary-tree/

/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* A binary Tree node
struct node
{
    int data;
    struct node *left, *right;
}; */


/* Recursive function to print all the nodes at distance k in the
   tree (or subtree) rooted with given root. See  */
bool searchAndPath(node* root,node* target,string &path){
    if(root==NULL){
        return false;
    }
    else if(root==target){
        return true;
    }
    if(searchAndPath(root->left,target,path)==true){
        path="L"+path;
        return true;
    }
    if(searchAndPath(root->right,target,path)==true){
        path="R"+path;
        return true;
    }
    return false;
} 
void printkdistanceNodeDown(node *root, int k)
{
    if(root==NULL || k<0){
        return;
    }
    else if(k==0){
        cout<<root->data<<" ";
    }
    else{
        printkdistanceNodeDown(root->left,k-1);
        printkdistanceNodeDown(root->right,k-1);
    }
// Your code here
}
/* Prints all nodes at distance k from a given target node.
 The k distant nodes may be upward or downward.  This function
 Returns distance of root from target node, it returns -1 if target
 node is not present in tree rooted with root. */
 void traversePath(node* root,int k,string path)
 {
     //cout<<"k:"<<k<<" root:"<<root->data<<" path:"<<path<<" p:"<<p<<endl;
     if(k<0||(path.length()==0))
        return;
        
     if(path.length()==k ||k==0){
         cout<<root->data<<" ";
     }
     if(path[0]=='L' ){
         if((k-path.length())>=0)
            printkdistanceNodeDown(root->right,(k-path.length()-1));
         path=(path.c_str())+1;
         traversePath(root->left,k,path);
     }
     if(path[0]=='R'){
         if((k-path.length())>=0)
            printkdistanceNodeDown(root->left,(k-path.length()-1));
         path=(path.c_str())+1;
         traversePath(root->right,k,path);
     }
 }
int printkdistanceNode(node* root, node* target , int k)
{
    /*cout<<"k distance nodes are:"<<endl;
    printkdistanceNodeDown(target,k);
    cout<<endl;
    string path="";
    bool b=searchAndPath(root,(target->right)->right,path);
    cout<<"path is : "<<path<<endl;*/
    printkdistanceNodeDown(target,k);
    string path="";
    bool b = searchAndPath(root,target,path);
    //cout<<"path is : "<<path<<endl;
    //cout<<endl;
    traversePath(root,k,path);
    return 0;
// Your code here
}
