#include<bits/stdc++.h>
using namespace std;

typedef struct Queue{
	int *array;
	int capacity;
	int size;
	int front;
	int rear;
};

Queue* createQue(int c){
	Queue *que = new Queue();
	que->capacity = c;
	que->size=0;
	que->front=0;
	que->rear=c;
	que->array = new int [que->capacity];
	cout<<"Queue created successfully"<<endl;
	return que;
}

bool isFull(Queue *que){
	if(que->size==que->capacity)
		return true;
	return false;
}

bool isEmpty(Queue *que){
	if(que->size==0)
		return true;
	return false;
}

void enque(Queue *que,int v){
	if(isFull(que)){
		cout<<"queue is full"<<endl;
		return;
	}

	que->rear =((que->rear)+1)%(que->capacity);
	(que->array)[que->rear]=v;
	 que->size = (que->size)+1;
	 cout<<"Inserted successfully"<<endl;
}

int mydeque(Queue *que){
	if(isEmpty(que)){
		cout<<"queue is empty"<<endl;
		return -1;
	}
	que->front =((que->front)+1)%(que->capacity);
	int v = (que->array)[que->front];
	 que->size = (que->size)-1;
	 return v;
}
int main(){
	int n,q,r;
	cin>>n>>q>>r;
	Queue *que=createQue(n);
	for(int i=0;i<q;i++){
		int p;
		cin>>p;
		enque(que,p);
	}

	for(int i=0;i<r;i++){
		int p;
		cin>>p;
		int y=mydeque(que);
		if(y!=-1)
		cout<<"poped element:"<<y<<endl;
	}

	return 0;
}