//https://leetcode.com/problems/lexicographically-smallest-equivalent-string/
class Solution {
public:
    int parent[26];
    int rank[26];
    void make_set(int v){
        parent[v] = v;
        rank[v] = 0;
    }

    int find_set(int u){
        if(u==parent[u])
            return u;
        return parent[u] = find_set(parent[u]);        
    }

    void union_set(int u, int v){
        int p_u = find_set(u);
        int p_v = find_set(v);
        if(p_u<p_v){
            parent[p_v] = p_u;
        } else if(p_v<p_u) {
            parent[p_u] = p_v;
        } else{
            parent[p_v] = p_u;
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        for(char c: s1){
            int c1 = c-'a';
            make_set(c1);
        }

        for(char c: s2){
            int c2 = c-'a';
            make_set(c2);
        }

        for(char c: baseStr){
            int c3 = c-'a';
            make_set(c3);
        }
        int n = s1.length();
        for(int i=0;i<n;i++){
            int t1= s1[i] - 'a';
            int t2= s2[i] - 'a';
            union_set(t1, t2);
        }
        
        int m = baseStr.length();
        string ans="";
        for(char c: baseStr){
            int x = c -'a';
            int y = find_set(x);
            ans += ('a'+y);
        }
        return ans;
    }
};