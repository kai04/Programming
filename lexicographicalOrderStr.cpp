//https://leetcode.com/contest/weekly-contest-114/problems/verifying-an-alien-dictionary/

map<char,int> morder;
static bool comp(string s1,string s2){
        bool flag=true;
        int n=s1.length();
        int m=s2.length();
        int i=0;
        int j=0;
        while(i<n && j<m){
            if(s1[i]!=s2[j]){
                // cout<<"s1:"<<s1<<" s2:"<<s2<<" i:"<<i<<" j:"<<j<<" s1[i]:"<<s1[i]<<" s2[j]"<<s2[j]<<" morder[s1[i]]:"<<morder[s1[i]]<<" morder[s2[j]]:"<<morder[s2[j]]<<endl;
                if(morder[s1[i]]>morder[s2[j]]){
                    // cout<<"morder[s1[i]]:"<<morder[s1[i]]<<" morder[s2[j]]:"<<morder[s2[j]]<<endl;
                    // flag=false;
                    // break;
                    return false;
                }
                else{
                    return true;
                }
                // cout<<"----------------------------------------"<<endl;
            }
            i++;
            j++;
        }
        if(flag && i==n){
            return true;
        }
        if(flag && j==m){
            return false;
        }
        return flag;
    }
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        //map<char,int> morder;
        for(int i=0;i<order.length();i++){
            morder[order[i]]=i;
        }
        vector<string> words_copy;
        for(int i=0;i<words.size();i++){
            words_copy.push_back(words[i]);
        }
        
        sort(words_copy.begin(),words_copy.end(),comp);
        /*for(auto it:words_copy)
            cout<<it<<" ";
        cout<<endl;*/
        bool res=true;
        for(int i=0;i<words.size();i++){
            if(words[i]!=words_copy[i]){
                res=false;
                break;
            }
        }
        return res;
    }
};
