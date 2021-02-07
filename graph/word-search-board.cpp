//https://www.interviewbit.com/problems/word-search-board/
static vector<pair<int,int>> get_pairs(int i,int j,char c,vector<string> &s){
    int n = s.size();
    int m = s[0].size();
    vector<pair<int,int>> ret;
    int dirx[4] = {0,0,-1,1};
    int diry[4] = {-1,1,0,0};
    for(int d = 0;d<4;d++){
        int ix = i + dirx[d];
        int iy = j + diry[d];
        if(ix>=0 && ix<n && iy>=0 && iy<m){
            if(s[ix][iy]==c)
                ret.push_back(make_pair(ix,iy));
        }
    }
    return ret;
}
static bool search(int i,int j,int k,string &s,vector<string> &A){
    if(k==s.length())
        return true;
    bool res = false;
    // cout<<"i:"<<i<<" j:"<<j<<" k:"<<k<<" Target:"<<s[k]<<endl;
    vector<pair<int,int>> p = get_pairs(i,j,s[k],A);
    for(int r=0;r<p.size();r++){
        res = res || search(p[r].first,p[r].second,k+1,s,A);
    }
    return res;
}
int Solution::exist(vector<string> &A, string B) {
    map<char,vector<pair<int,int>>> m;
    int n = A.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<A[i].length();j++){
            m[A[i][j]].push_back(make_pair(i,j));
        }
    }
    vector<pair<int,int>> start = m[B[0]];
    bool ret = false;
    for(int q=0;q<start.size();q++){
        ret =  ret || search(start[q].first,start[q].second,1,B,A);
        // cout<<"DEBUG:"<<" X:"<<start[q].first<<" Y:"<<start[q].second<<endl;
    }
    return ret;
}
