//https://leetcode.com/problems/binary-tree-level-order-traversal/submissions/
#include<bits/stdc++.h>
using namespace std;

struct Node
{
     int data;
     Node* left, *right;
     // Node(int x){
     //    data = x;
     //    left=NULL;
     //    right=NULL;
     // }
};

Node * insert(Node* &root, int value) {
	// cout<<"val:"<<value<<endl;
	// cout<<"root1:"<<root<<endl;
    if(root==NULL){
        //root= new node(value);
        Node * temp = new Node();
        temp->data = value;
        temp->left =  NULL;
        temp->right =  NULL;
        root = temp;
        // cout<<"root:"<<root->data<<endl;
    }
    else{
        Node *curr;
        // cout<<"root:"<<root->data<<endl;
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
vector<Node*> spiralOrder(Node* root){
	queue<pair<Node*,int>> q;
	q.push(make_pair(root,1));
	int prev_level = -1;
	stack<Node*> s;
	vector<Node*> ans;
	while(!q.empty())
	{

		Node *curr = q.front().first;
		int level = q.front().second;
		if(level%2==1){
			s.push(curr);
		}
		else{
			while(!s.empty()){
				Node* temp = s.top();
				ans.push_back(temp);
				s.pop();
			}
			ans.push_back(curr);

		}
		// if(level!=prev_level){
		// 	cout<<endl;
		// }
		if(curr->left!=NULL){
			q.push(make_pair(curr->left,level+1));
		}
		if(curr->right!=NULL){
			q.push(make_pair(curr->right,level+1));
		}
		// cout<<"("<<curr->data<<","<<level<<")";
		// cout<<curr->data<<" ";
		prev_level = level; 
		q.pop();
	}
	return ans;
}

//[(10,20,30)(20,40,50)]
void levelOrder(Node* root){
	queue<pair<Node*,int>> q;
	q.push(make_pair(root,1));
	int prev_level = -1;
	while(!q.empty())
	{

		Node *curr = q.front().first;
		int level = q.front().second;
		if(level!=prev_level){
			cout<<endl;
		}
		if(curr->left!=NULL){
			q.push(make_pair(curr->left,level+1));
		}
		if(curr->right!=NULL){
			q.push(make_pair(curr->right,level+1));
		}
		// cout<<"("<<curr->data<<","<<level<<")";
		cout<<curr->data<<" ";
		prev_level = level; 
		q.pop();
	}
}
int main(){
	int n;
	cin>>n;
	Node *root = NULL;
	// *root = NULL;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		root = insert(root,x);
	}
	// cout<<"hey"<<endl;
	// levelOrder(root);
	vector<Node*> v = spiralOrder(root);
	for(vector<Node*>::iterator it = v.begin();it!=v.end();it++){
		cout<<(*it)->data<<" ";
	}
	cout<<endl;
}