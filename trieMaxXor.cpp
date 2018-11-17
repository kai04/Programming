//https://www.spoj.com/problems/TDPRIMES/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int SIZE=2;
struct trieNode
{
	trieNode* children[SIZE];
	bool isEndofWord=false;
};

trieNode* gettrieNode(){
	trieNode *mynode=new trieNode();
	for(int i=0;i<SIZE;i++){
		mynode->children[i]=NULL;
	}
	mynode->isEndofWord=false;
	return mynode;
}


void insert(string bString,trieNode *node){
	trieNode* temp=node;
	for(int i=bString.length()-1;i>=0;i--){
		if(temp->children[bString[i]]==NULL){
			temp->children[bString[i]]=(gettrieNode());
		}
		temp=temp->children[bString[i]];
	}
	temp->isEndofWord=true;
}
int query(){
	return 0;

}
int main(){
	int n;
	cin>>n;
	vector<int> a(n);
	int max_elt=INT_MIN;
	for(int i=0;i<n;i++){
		cin>>a[i];
		max_elt=max(max_elt,a[i]);
	}
	int p=ceil(log2(max_elt));

	vector<string> binaryString(n);
	for(int i=0;i<n;i++){
		string tempString=(bitset<32> (a[i])).to_string();
		binaryString[i]=tempString.substr(32-p,p);
		cout<<a[i]<<" "<<binaryString[i]<<endl;
	}
	trieNode *mytrie=new trieNode();
	for(int i=0;i<n;i++){
		insert(binaryString[i],mytrie);
	}

	return 0;

}