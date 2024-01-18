//https://cses.fi/problemset/task/1077
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;

ll leftSetSum = 0, rightSetSum=0;

void add(set<pair<ll,ll>> &leftSet, 
	set<pair<ll,ll>> &rightSet, ll i, vector<ll> &A){

	ll old_median = (leftSet.rbegin()->first);
	if(A[i]<=old_median){
		leftSet.insert({A[i], i});
		leftSetSum +=A[i];
	} else{
		rightSet.insert({A[i], i});
		rightSetSum +=A[i];
	}
}

void remove(set<pair<ll,ll>> &leftSet, 
	set<pair<ll,ll>> &rightSet, ll i, vector<ll> &A){

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

void prllSets(set<pair<ll,ll>> leftSet, set<pair<ll,ll>> rightSet){
	cout<<"Prlling left set...."<<endl;
	for(auto it1:leftSet){
		cout<<"("<<it1.first<<","<<it1.second<<") ";
	}
	cout<<endl<<"--------------------------"<<endl;
	cout<<"Prlling right set...."<<endl;
	for(auto it1:rightSet){
		cout<<"("<<it1.first<<","<<it1.second<<") ";
	}
	cout<<endl<<"--------------------------"<<endl;
}
void fix(set<pair<ll,ll>> &leftSet, 
	set<pair<ll,ll>> &rightSet, ll k){
	ll x1,x2,cnt1=0,cnt2=0;
	ll lsize = leftSet.size();
	ll rsize = rightSet.size();
	
	
	if(k%2==0){
		x1 = k/2;
		x2 = k/2;
	} else{
		x1 = k/2+1;
		x2 = k/2;
	}
	if(x1==lsize && x2==rsize) return;
	
	if(lsize==rsize){
		// always (lsize+rsize = k) so for even window nothing to be done and for 
		// odd window this case is not possible
		return; 
	} else if(lsize>rsize){
		// when window size is odd/even remove elements from leftset and insert llo right set 
		// till size of lsize =x1
		while(lsize>0 && lsize>x1){
			// cout<<"f20:"<<" lsize:"<<lsize<<" rsize:"<<rsize<<" x1:"<<x1<<" x2:"<<x2<<endl;
			pair<ll,ll> p1 = *(leftSet.rbegin());
			leftSet.erase(p1);
			leftSetSum -= p1.first;
			rightSet.insert(p1);
			rightSetSum += p1.first;
			rsize = rightSet.size();
			lsize = leftSet.size();
		}  
	} else{
		// when window size is odd/even remove elements from rightset and insert llo left set 
		// till size of rsize =x2
		while(rsize>0 && rsize>x2){
			// cout<<"f21:"<<" lsize:"<<lsize<<" rsize:"<<rsize<<" x1:"<<x1<<" x2:"<<x2<<endl;
			pair<ll,ll> p1 = *(rightSet.begin());
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

vector<ll> sliding_median(vector<ll> &A, ll k){
	ll n = A.size();
	vector<pair<ll,ll>> temp;
	vector<ll> costs;
	set<pair<ll,ll>> leftSet, rightSet;
	ll i=0,j=0,x1,x2;
	if(k%2==0){
		x1 = k/2;
		x2 = k/2;
	} else{
		x1 = k/2+1;
		x2 = k/2;
	}
	while(j<n){
		ll window_size = j-i+1;
		if(j>=k){
			add(leftSet, rightSet, j, A);
			remove(leftSet, rightSet, i, A);
			fix(leftSet, rightSet, k);
			i++;
		} else if(j==k-1){
			temp.push_back({A[j],j});
			sort(temp.begin(), temp.end());
			for(ll t=0;t<x1;t++){
				leftSet.insert(temp[t]);
				leftSetSum += temp[t].first; 
			}
			for(ll t=x1;t<temp.size();t++){
				rightSet.insert(temp[t]);
				rightSetSum += temp[t].first;
			}
		} else{
			temp.push_back({A[j],j});
		}

		if(window_size>=k){
			ll median = leftSet.rbegin()->first;
			ll lsize = leftSet.size();
			ll rsize = rightSet.size();
			ll cost = ((lsize*median)-leftSetSum) + (rightSetSum-(rsize*median));
			costs.push_back(cost);
			// cout<<"i:"<<i<<" j:"<<j<<" window_size:"<<window_size<<" median:"<<median<<" cost:"<<cost<<" leftSetSum:"<<leftSetSum<<" rightSetSum:"<<rightSetSum<<endl;
			// prllSets(leftSet, rightSet);
			// cout<<"============================"<<endl;
			
		}

		j++;
	}
	return costs;
}
int main()
{
	ll n,k;
	cin>>n>>k;
	vector<ll> A(n);
	for(ll i=0;i<n;i++){
		cin>>A[i];
	}
	vector<ll> med = sliding_median(A, k);
	for(ll x:med){
		cout<<x<<" ";
	}
	cout<<endl;

	return 0;
}