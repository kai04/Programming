#include<bits/stdc++.h>
using namespace std;

int find(vector<int> &parent, int x)
{
	// If, parent of 'x' is itself 'x' then return 'x'.
	if (parent[x] == x)
	{
		return x;
	}

	// Else, again make the recursive call to find the parent.
	parent[x] = find(parent, parent[x]);

	return parent[x];
}

int minSwaps(vector<int> &arr, int n)
{
	// Vector to store the parent nodes.
	vector<int> parent(n);

	// Initially, assume all components as disconnected and so set parent[i] = i for every 'i'.
	for (int i = 0; i < n; i++)
	{
		parent[i] = i;
	}

	// HashMap that helps in mapping down two numbers in a particular pair.
	unordered_map<int, int> mp;

	// Iterate the given array/list.
	for (int i = 0; i < 2 * n; i++)
	{
		// Variable to store the vertex in which number arr[i] included.
		int num = arr[i] / 2;

		// Check if this vertex is already in the HashMap or not.
		// If not then insert it into the HashMap and map with the position as 'i'/2.
		if (mp.find(num) == mp.end())
		{
			mp[num] = i / 2;
			cout<<"NOT FOUND i:"<<i<<" arr[i]:"<<arr[i]<<" num:"<<num<<" mp[num]:"<<mp[num]<<endl;
		}
		// Else, make an edge between vertices present at 'i'/2 and "mp[num]".
		else
		{
			int v1 = find(parent, mp[num]);
			int v2 = find(parent, i / 2);
			parent[v1] = v2;
			cout<<"FOUND i:"<<i<<" arr[i]:"<<arr[i]<<" num:"<<num<<" mp[num]:"<<mp[num]<<" parent mp[num]:"<<v1<<" parent i/2:"<<v2<<endl;
		}
		cout<<"Printing map...."<<endl;
		for(auto it1:mp){
			cout<<it1.first<<" ->"<<it1.second<<endl;
		}
		cout<<"--------------------------"<<endl<<"Printing parents...."<<endl;
		for(auto it2:parent){
			cout<<it2<<" ";
		}
		cout<<endl<<"================================================="<<endl;
	}

	// Variable to store the number of connected components in the graph.
	int conCount = 0;

	// Iterate through all possible parent/root nodes of connected components.
	for (int i = 0; i < n; i++)
	{
		if (parent[i] == i)
		{
			conCount = conCount + 1;
		}
	}

	return n - conCount;
}


int main(){
	int n;
	cin>>n;
	vector<int> a(2*n);
	for(int i=0;i<2*n;i++){
		cin>>a[i];
	}
	int ans = minSwaps(a,n);
	cout<<"ANS:"<<ans<<endl;
	return 0;
}