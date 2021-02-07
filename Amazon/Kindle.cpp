/*

INPUT:
2 6 7
storage
battery
hover
alexa
waterproof
solar
i wish my kindle had even more storage!
i wish the battery life on my kindle lasted 2 years.
i read in the bath and would enjoy a waterproof Kindle
Waterproof and increased battery are my top two requests
I want to take my Kindle into the shower Waterproof please!
it would be neat if my Kindle would hover on my desk when not in use
How cool would it be if my Kindle charged in the sun via solar power? 

*/

#include<bits/stdc++.h>
using namespace std;


vector<string> split(const string& s, char delimiter)
{
   vector<string> tokens;
   string token;
   istringstream tokenStream(s);
   while (getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token);
   }
   return tokens;
}

vector<string> topFeatureRequest(int topFeatures,vector<string> possibleFeatures,vector<string> featureRequest){
	int n = featureRequest.size();
	int m = possibleFeatures.size();
	unordered_map<string,int> mp;
	for(int i=0;i<m;i++){
		mp[possibleFeatures[i]] = 0;
	}
	for(int i=0;i<n;i++){
		string curr_sent = featureRequest[i]; 
		transform(curr_sent.begin(), curr_sent.end(), curr_sent.begin(), ::tolower); 
		vector<string> words = split(curr_sent,' ');
		for(int j=0;j<words.size();j++){
			string word = words[j]; 
			transform(word.begin(), word.end(), word.begin(), ::tolower);
			if(mp.find(word)!=mp.end()){
				mp[word]++;
			}
		}
	}
	vector<pair<int,string>> top;
	for(auto it:mp){
		top.push_back(make_pair(it.second,it.first));
	}
	sort(top.begin(),top.end());
	vector<string> res;
	int k = top.size();
	for(int i=0;i<topFeatures;i++){

		res.push_back(top[k-1-i].second);
	}
	return res;

}


void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}


int main(){
	c_p_c();
	int n,p,q;
	cin>>n>>p>>q;
	
	vector<string> possibleFeature;
	vector<string> fRequest;
	for(int i=0;i<p;i++){
		string x;
		cin>>x;
		possibleFeature.push_back(x);
	}

	for(int i=0;i<q;i++){
		string x;
		getline(cin, x);
		fRequest.push_back(x);
	}

	vector<string> ans = topFeatureRequest(n,possibleFeature,fRequest);
	for(auto it:ans){
		cout<<it<<" ";
	}
	cout<<endl;
	return 0;
}