#include<bits/stdc++.h>

using namespace std;
 struct node
 {
     int data;
     Node* left, *right;
}; 


queue<node*> q1;
void levelOrder(node * root) {
q1.push(root);
    while(!q1.empty()){
        int x = (q1.front())->data;
        // cout<<x<<" ";
        string rec="p"+to_string(x)+" [label=\""+to_string(x)+"\"];";
        cout<<rec<<endl;
        if((q1.front())->left!=NULL)
            q1.push((q1.front())->left);
        if((q1.front())->right!=NULL)
            q1.push((q1.front())->right);
        q1.pop();
    } 
}


queue<node*> q2;
void levelOrder_new(node * root) {
q2.push(root);
    while(!q2.empty()){
        int x = (q2.front())->data;
        string rec;
        // cout<<x<<" ";
        // string rec=string(x)+" [label=\""+string(x)+"\"];"
        // cout<<rec<<endl;
        if((q2.front())->left!=NULL){
            rec="p"+to_string((q2.front())->data)+"->p"+to_string(((q2.front())->left)->data);
            cout<<rec<<endl;
            rec="";
            q2.push((q2.front())->left);
        }
            
        if((q2.front())->right!=NULL){
            rec="p"+to_string((q2.front())->data)+"->p"+to_string(((q2.front())->right)->data);
            cout<<rec<<endl;
            rec="";
            q2.push((q2.front())->right);
        }
            
        q2.pop();
    } 
}
void generateDot(node * root){
	// ofstream outfile;
	// outfile.open("visualTree.dot");

	cout << "digraph M{" << endl;
    levelOrder(root);
    cout<<endl;
    levelOrder_new(root);
    
	cout << "}" << endl;

}

int main(){

	generateDot(root);
	return 0;
}