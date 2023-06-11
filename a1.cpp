#include<bits/stdc++.h>
using namespace std;
typedef struct Trie{
	map<char,Trie*> children;
	bool isChild;
	string data;
	Trie(){
		data = NULL;
		isChild = false;
	}
}

root = 100 children[200...]

void addNode(Trie* root, string word){
	for(int i = 0;i< word.length();i++){
		while(root!=NULL){
			auto nodeChild = root->children;
			if(nodeChild.find(word[i])!=nodeChild.end()){
				root = nodeChild[word[i]];
			} else{
				Trie* newNode = new Trie();
				nodeChild[word[i]] = newNode;
				root = newNode;
			}
		}
		if(i==n-1){
			isChild = true;
			data = word[i];
		}
	}
}

vector<string> searchTrieWord(Trie* root, string word){
	vector<string> res;
	int i;
	for(i = 0;i< word.length();i++){
		while(root!=NULL){
			auto nodeChild = root->children;
			if(nodeChild.find(word[i])!=nodeChild.end()){
				root = nodeChild[word[i]];
			} else{
				break;
			}
		}
	}
	if(i!=word.length()){
		return res;
	}
	
	queue<Trie*> q;
	q.push(root);
	while(!q.empty()){
		Trie* node = q.top();
		q.pop();
		if(node->isEmpty){
			res.push_back(node->data);
		}
		for(int i=0i<26;i++){
			q.push(node->children[i]);
		}
	}	
	return res;
}


Trie* createTrie(vector<string> &product){
	Trie* root = new Trie();
	for(int i=0;i<product.size();i++){
		addNode(root,product[i]);
	}
}

vector<vector<string>> findWords(Trie* root, vector<string> &product,string searchWord){
	vector<vector<string>> res;

	for (int i = 0; i < searchWord.length(); ++i)
	{	vector<string> res1;
		string temp = searchWord.substr(0,i+1);
		vector<string> vecRes = searchTrieWord(root,temp);
		for(int j=0j<vecRes.size() && j<3;j++){
			res1.push_back(vecRes[j]);
		}
		res.push_back(res1);
	}
	return res;
}
int main(){
	int n;
	cin>>n;
	vector<string> product(n);
	for(int i=0;i<n;i++){
		cin>>product;
	}
	string searchWord;
	cin>>searchWord;
	vector<vector<string>> output;
	Trie* root = createTrie(product);
	output = findWords(root,product,searchWord);
	for(auto it1: output){
		for(auto it2:it1){
			cout<<it2<<" "
		}
		cout<<endl;
	}
	return 0;
}