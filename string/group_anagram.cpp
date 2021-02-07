#include<bits/stdc++.h>
using namespace std;

 bool isAnagrams(string s1,string s2){
        if(s1.length()!=s2.length()){
            return false;
        }
        map<char,int> m1;
        map<char,int> m2;
        for(int i=0;i<s1.length();i++){
            m1[s1[i]]++;
        }
        for(int i=0;i<s2.length();i++){
            m2[s2[i]]++;
        }
        for(int i=0;i<26;i++){
            char c = 'a'+i;
            //cout<<"char:"<<c<<" m1[c]:"<<m1[c]<<" m2[c]:"<<m2[c]<<endl;
            if(m1[c]!=m2[c])
                return false;
        }
        return true;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        int cnt = 0;
        vector<int> visited(n,-1);
        map<int,vector<string>> m;
        for(int i=0;i<n;i++){
            if(visited[i]==-1){
                cnt++;
                visited[i] = i;
                m[i].push_back(strs[i]);
                for(int j=i+1;j<n;j++){
					bool flag = isAnagrams(strs[i],strs[j]);
					///cout<<"i:"<<i<<" j:"<<j<<" s1:"<<strs[i]<<" s2:"<<strs[j]<<" ISANAGRAM:"<<flag<<endl;
                    if(visited[j]==-1 && flag){	
                        visited[j] = i;
                        m[i].push_back(strs[j]);
                    }
                }
            }
        }
        vector<vector<string>> res;
		for(auto it:m){
			res.push_back(it.second);
		}
        
        return res;
    }    
    
    int main(){
		int n;
		cin>>n;
		vector<string> s(n);
		for(int i=0;i<n;i++){
			cin>>s[i];
		}
		//bool d = isAnagrams("eat","tan");
		//cout<<d<<endl;
		vector<vector<string>> res = groupAnagrams(s);
		for(int i=0;i<res.size();i++){
			for(int j=0;j<res[i].size();j++){
				cout<<res[i][j]<<" ";
			}
			cout<<endl;
		}
		return 0;
	}
