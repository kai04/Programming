// C++ implementation of De-queue using circular 
// array 
#include<bits/stdc++.h> 
using namespace std; 
  
// Maximum size of array or Dequeue 
#define MAX 100 
  
// A structure to represent a Deque
typedef struct Node
 {
 	string data;
 	Node* prev;
 	Node* next;
 }Node; 
 static Node* createNode(string d)
 {
 	Node* node = (Node*) malloc(sizeof(Node));
 	if(node ==NULL){
 		cout<<"Memory not allocated"<<endl;
 	}
 	

 	node->data = d;
 	node->prev = NULL;
 	node->next = NULL;
 	return node;
 };
class Deque 
{ 
    // int  arr[MAX]; 
    Node*  front; 
    Node*  back;

    // int  size; 
public : 
	Deque(){
    	front = NULL;
    	back = NULL;
    }
    // Operations on Deque: 
    void  insertfront(string key); 
    void  insertrear(string key); 
    void  deletefront(); 
    void  deleterear(); 
    bool  isFull(); 
    bool  isEmpty(); 
    string  getFront(); 
    string  getRear();
    void printDeque(); 
}; 
  
// Checks whether Deque is full or not. 
bool Deque::isFull() 
{ 
     return false;
} 
  
// Checks whether Deque is empty or not. 
bool Deque::isEmpty () 
{ 
	if(this->front == NULL && this->back==NULL){
		return true;
	}
	return false; 
} 
  
// Inserts an element at front 
void Deque::insertfront(string key) 
{  	if(this->front == NULL && this->back==NULL){
  		Node* node = createNode(key);
  		this->front= node;
  		this->back= node;
  	}
  	else{
  		Node* node = createNode(key);
  		node->next =  this->front;
  		(this->front)->prev = node;
  		(this->front) = node;
  	}
} 
  
// function to inset element at rear end 
// of Deque. 
void Deque ::insertrear(string key) 
{ 
  	if(this->front == NULL && this->back==NULL){
  		Node* node = createNode(key);
  		this->front= node;
  		this->back= node;
  	}
  	else{
  		Node* node = createNode(key);
  		node->prev =  this->back;
  		(this->back)->next = node;
  		(this->back) = node;
  	} 
} 
  
// Deletes element at front end of Deque 
void Deque ::deletefront() 
{ 
	if(this->isEmpty()){
		cout<<"Cannot delete from empty queue"<<endl;
	}
	else if(this->front == this->back){
		// free(this->front);
		this->front=NULL;
		this->back=NULL;
	}
	else{
		Node* nextNode = (this->front)->next;
		// free(this->front);
		this->front = nextNode;
		nextNode->prev = NULL;		
	}
   
} 
  
// Delete element at rear end of Deque 
void Deque::deleterear() 
{ 
 if(this->isEmpty()){
		cout<<"Cannot delete from empty queue"<<endl;
	}
	else if(this->front == this->back){
		free(this->front);
		this->front=NULL;
		this->back=NULL;
	}
	else{
		Node* prevNode = (this->back)->prev;
		// free(this->back);
		this->back = prevNode;
		prevNode->next = NULL;		
	}
} 
  
// Returns front element of Deque 
string Deque::getFront() 
{ 
 	if(isEmpty()){
 		cout<<"Empty Deque return NULL"<<endl;
 		return NULL;
 	}
 	else{
 		return ((this->front)->data);
 	}
} 
  
// function return rear element of Deque 
string Deque::getRear() 
{ 
  	if(isEmpty()){
 		cout<<"Empty Deque return NULL"<<endl;
 		return NULL;
 	}
 	else{
 		return ((this->back)->data);
 	}
} 
 
 void Deque::printDeque() 
{ 
	cout<<"printing De-queue ..."<<endl;
	cout<<"--------------------------------------"<<endl;
  	Node* curr = this->front;
  	while(curr!=NULL){
  		cout<<curr->data<<" ";
  		curr = curr->next;
  	}
  	cout<<endl;
  	cout<<"--------------------------------------"<<endl;
} 
// Driver program to test above function 
int main() 
{ 
    // Deque dq(5);
    Deque dq; 
    cout << "Insert element at rear end  : 5 \n"; 
    dq.insertrear("5"); 
  
    cout << "insert element at rear end : 10 \n"; 
    dq.insertrear("10"); 
  	// dq.printDeque();
    cout << "get rear element " << " "<< dq.getRear() << endl; 
  
    dq.deleterear(); 
    cout << "After delete rear element new rear"<< " become " << dq.getRear() << endl; 
  
    cout << "inserting element at front end \n"; 
    dq.printDeque();
 	dq.insertfront("15"); 
 	dq.printDeque();

  
    cout << "get front element " << " " << dq.getFront() << endl; 
  
    dq.deletefront(); 
  
    cout << "After delete front element new "<< "front become " << dq.getFront() << endl; 
    return 0; 
} 
