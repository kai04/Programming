//https://leetcode.com/problems/find-all-anagrams-in-a-string/submissions/
class Solution {
public:
    bool checkAnagram(map<char,int> &scnt,map<char,int> &pcnt){
        if(scnt.size()!=pcnt.size())
            return false;
        for(auto it:pcnt){
            char c = it.first;
            if(scnt[c]!=pcnt[c])
                return false;
        }
        return true;
    }
    void printMap(map<char,int> &m){
        for(auto it:m)
            cout<<it.first<<" -> "<<it.second<<endl;
        cout<<"------------------------"<<endl;
    }
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int m = p.length();
        map<char,int> pcnt;
        map<char,int> scnt;
        for(int i=0;i<m;i++){
            pcnt[p[i]]++;
            scnt[s[i]]++;
        }
        vector<int> res;
        int j = m-1;
        while(j<n){
            int i = j-m+1;
            /*cout<<"i:"<<i<<" j:"<<j<<endl;
            cout<<"Print S count..."<<endl;
            printMap(scnt);
            cout<<"Print P count..."<<endl;
            printMap(pcnt);
            cout<<"============================="<<endl;*/
            if(checkAnagram(scnt,pcnt)){
                res.push_back(i);
            }
            scnt[s[i]]--;
            if(scnt[s[i]]==0){
                scnt.erase(s[i]);
            }
            j++;
            scnt[s[j]]++;
        }
        return res;
    }
};
