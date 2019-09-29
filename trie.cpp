#include<bits/stdc++.h>
using namespace std;
typedef struct Trie{
	map<char,Trie*> m;
	bool isEndofWord;
	Trie(){
		isEndofWord = false;
	}
	Trie* getNextNode(char c){
		auto it = m.find(c);
		if(it!=m.end()){
			return m[c];
		}
		else{
			Trie* node = new Trie();
			m[c] = node;
			return m[c];	
		}
		return NULL;
	}
} Trie; 

bool find(string str,Trie* root){
	Trie * curr;
	curr = root;
	for(int j=0 ;j<str.length();j++){
		if((curr->m).find(str[j])!=(curr->m).end()){
			Trie *next = curr->m[str[j]];
			curr = next;
		}
		else{
			return false;
		}
	}
	if(curr->isEndofWord){
		return true;
	}
	return false;
}

int main(){
	int n;
	cin>>n;
	vector<string> s(n);
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	Trie *root = new Trie();
	for(int i=0 ;i<n;i++){
		Trie * curr;
		curr = root;
		for(int j=0 ;j<s[i].length();j++){
			Trie *next = curr->getNextNode(s[i][j]);
			if(j==s[i].length()-1){
				curr->isEndofWord = true;
			}
			curr = next;
		}
	}
	return 0;
}