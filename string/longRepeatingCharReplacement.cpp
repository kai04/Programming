//https://leetcode.com/problems/longest-repeating-character-replacement/submissions/
class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        int n = s.length();
        vector<int> m(26,0);
        int maxCharCnt = 0;
        int i = 0;
        for(int j=0;j<n;j++){
            m[s[j]-'A']++;
            maxCharCnt = max(maxCharCnt,m[s[j]-'A']);
            while(j-i+1-maxCharCnt>k){
                m[s[i]-'A']--;
                i++;
                maxCharCnt = 0;
                for(int x:m)
                    maxCharCnt = max(maxCharCnt,x);
            }
            ans = max(ans,j-i+1);
        }
        return ans;
    }
};