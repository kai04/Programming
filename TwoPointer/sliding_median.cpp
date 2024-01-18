//https://cses.fi/problemset/task/1076
#include <bits/stdc++.h>
using namespace std;
typedef int ll;

ll leftSetSum = 0, rightSetSum=0;

void add(set<pair<int,int>> &leftSet, 
	set<pair<int,int>> &rightSet, int i, vector<int> &A){

	// cout<<"f0:"<<endl;
	int old_median = (leftSet.rbegin()->first);
	if(A[i]<=old_median){
		leftSet.insert({A[i], i});
		leftSetSum +=A[i];
	} else{
		rightSet.insert({A[i], i});
		rightSetSum +=A[i];
	}
}

void remove(set<pair<int,int>> &leftSet, 
	set<pair<int,int>> &rightSet, int i, vector<int> &A){

	// cout<<"f1:"<<endl;
	auto it1 = leftSet.find({A[i],i});
	if(it1!=leftSet.end()){
		leftSet.erase(it1);
		leftSetSum -=A[i];
	}
	auto it2 = rightSet.find({A[i],i});
	if(it2!=rightSet.end()){
		rightSet.erase(it2);
		rightSetSum -=A[i];
	}
}

void printSets(set<pair<int,int>> leftSet, set<pair<int,int>> rightSet){
	cout<<"Printing left set...."<<endl;
	for(auto it1:leftSet){
		cout<<"("<<it1.first<<","<<it1.second<<") ";
	}
	cout<<endl<<"--------------------------"<<endl;
	cout<<"Printing right set...."<<endl;
	for(auto it1:rightSet){
		cout<<"("<<it1.first<<","<<it1.second<<") ";
	}
	cout<<endl<<"--------------------------"<<endl;
}
void fix(set<pair<int,int>> &leftSet, 
	set<pair<int,int>> &rightSet, int k){
	int x1,x2,cnt1=0,cnt2=0;
	int lsize = leftSet.size();
	int rsize = rightSet.size();
	
	
	if(k%2==0){
		x1 = k/2;
		x2 = k/2;
	} else{
		x1 = k/2+1;
		x2 = k/2;
	}
	// cout<<"f2:"<<" lsize:"<<lsize<<" rsize:"<<rsize<<" x1:"<<x1<<" x2:"<<x2<<endl;
	if(x1==lsize && x2==rsize) return;
	
	if(lsize==rsize){
		// always (lsize+rsize = k) so for even window nothing to be done and for 
		// odd window this case is not possible
		return; 
	} else if(lsize>rsize){
		// when window size is odd/even remove elements from leftset and insert into right set 
		// till size of lsize =x1
		while(lsize>0 && lsize>x1){
			// cout<<"f20:"<<" lsize:"<<lsize<<" rsize:"<<rsize<<" x1:"<<x1<<" x2:"<<x2<<endl;
			pair<int,int> p1 = *(leftSet.rbegin());
			leftSet.erase(p1);
			leftSetSum -= p1.first;
			rightSet.insert(p1);
			rightSetSum += p1.first;
			rsize = rightSet.size();
			lsize = leftSet.size();
		}  
	} else{
		// when window size is odd/even remove elements from rightset and insert into left set 
		// till size of rsize =x2
		while(rsize>0 && rsize>x2){
			// cout<<"f21:"<<" lsize:"<<lsize<<" rsize:"<<rsize<<" x1:"<<x1<<" x2:"<<x2<<endl;
			pair<int,int> p1 = *(rightSet.begin());
			rightSet.erase(p1);
			rightSetSum -= p1.first;
			leftSet.insert(p1);
			leftSetSum += p1.first;
			lsize = leftSet.size();
			rsize = rightSet.size();
		}
	}
	// cout<<"*************************"<<endl;
}

vector<int> sliding_median(vector<int> &A, int k){
	int n = A.size();
	vector<pair<int,int>> temp;
	vector<int> median;
	set<pair<int,int>> leftSet, rightSet;
	int i=0,j=0,x1,x2;
	if(k%2==0){
		x1 = k/2;
		x2 = k/2;
	} else{
		x1 = k/2+1;
		x2 = k/2;
	}
	while(j<n){
		int window_size = j-i+1;
		// cout<<"i:"<<i<<" j:"<<j<<" window_size:"<<window_size<<endl;
		if(j>=k){
			add(leftSet, rightSet, j, A);
			remove(leftSet, rightSet, i, A);
			fix(leftSet, rightSet, k);
			i++;
		} else if(j==k-1){
			temp.push_back({A[j],j});
			sort(temp.begin(), temp.end());
			for(int t=0;t<x1;t++){
				leftSet.insert(temp[t]);
			}
			for(int t=x1;t<temp.size();t++){
				rightSet.insert(temp[t]);
			}
		} else{
			temp.push_back({A[j],j});
		}

		if(window_size>=k){
			median.push_back(leftSet.rbegin()->first);
			// cout<<"i:"<<i<<" j:"<<j<<" window_size:"<<window_size<<" median:"<<median[median.size()-1]<<endl;
			// printSets(leftSet, rightSet);
			// cout<<"============================"<<endl;
			
		}

		j++;
	}
	return median;
}
int main()
{
	int n,k;
	cin>>n>>k;
	vector<int> A(n);
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	vector<int> med = sliding_median(A, k);
	for(int x:med){
		cout<<x<<" ";
	}
	cout<<endl;

	return 0;
}