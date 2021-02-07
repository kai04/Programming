//https://leetcode.com/problems/find-duplicate-file-in-system/
static void get_data(string s,string &fname,string &content){
    int pos = s.find('(');
    fname = s.substr(0,pos);
    string temp = s.substr(pos+1);
    content = temp.substr(0,temp.find(')'));
}
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        int n = paths.size();
        vector<vector<string>> res;
        unordered_map<string,vector<string>> m;
        for(int i=0;i<n;i++){
            string dir;
            string file;
            stringstream ss(paths[i]);
            ss>>dir;
            // cout<<"DIR:"<<dir<<endl;
            while(ss>>file){
                // cout<<"FILES:"<<file<<endl;
                string fname,content;
                get_data(file,fname,content);
                // cout<<"Fname:"<<fname<<" Content:"<<content<<endl;
                m[content].push_back((dir+"/"+fname));
            }
            
            // cout<<"---------------"<<endl;
            
        }
        for(auto it:m){
                if(it.second.size()>1){
                    /* cout<<"Content:"<<it.first<<endl;
                    for(auto it1:it.second){
                        cout<<it1<<" ";
                    }
                    cout<<endl<<"=========================="<<endl;
                    */
                    res.push_back(it.second);
                }
            }
        return res;
    }
};