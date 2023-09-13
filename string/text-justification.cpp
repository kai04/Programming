//https://leetcode.com/problems/text-justification/submissions/
class Solution {
public:
    void check(int wordCnt, int wordLength, int j, vector<string>& words, int maxWidth, vector<int> &chk){
        int tot = wordLength + words[j].length() + wordCnt-1;
        if(tot<=maxWidth){
            chk[0] = 1;
            chk[1] = wordLength + words[j].length();
        } else {
            chk[0] = 0;
            chk[1] = wordLength;
        }
        
    }

    void addSpaces(string &s, int l){
        for(int i=0;i<l;i++){
            s = s + " ";
        }
    }
    void justifyText(int i, int j, vector<string>& words, int maxWidth, int wordLen, vector<string> &ans){
        int wordCnt = j-i+1;
        int n = words.size();
        int spaceLen = maxWidth - (wordLen);
        int x =0, y=0; 
        vector<int> spaceArr;
        if(wordCnt>1){
            if(j!=n-1){
                x = spaceLen/(wordCnt-1);
                y = spaceLen%(wordCnt-1);
                spaceArr.resize(wordCnt,x);
                spaceArr[spaceArr.size()-1] = 0;
            } else {
                x=1;
                y=0;
                spaceArr.resize(wordCnt,x);
                int l = spaceLen - (wordCnt-1);
                spaceArr[spaceArr.size()-1] = l;
            }
            
        } else{
            if(j!=n-1){
                spaceArr.resize(1,spaceLen);
            } else{
                spaceArr.resize(1,spaceLen);
            }
            
        }
         
        
        int ix=0;
        while(y>0){
            spaceArr[ix]++;
            y--;
            ix++;
        }
        string ret = "";
        for(int p=i,t=0;p<=j && t<spaceArr.size();p++,t++){
            ret = ret + words[p];
            addSpaces(ret, spaceArr[t]);
        }
        ans.push_back(ret);
    }

    void rec(int i, vector<string>& words, int maxWidth, vector<string> &ans){
        int n = words.size();
        if(i>=n){
            return;
        }
        int wordLen = 0;
        int j = i;
        
        vector<int> chk(2);
        while(j<n){
            int wordCnt = j-i+1;
            check(wordCnt, wordLen, j, words, maxWidth, chk);
            if(chk[0]==1){
                wordLen = chk[1];
                j++;
            } else{
                break;
            }
        }
        justifyText(i,j-1,words,maxWidth,wordLen,ans);
        rec(j,words, maxWidth,ans);
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        rec(0,words,maxWidth,ans);
        return ans;
    }
};