#include <bits/stdc++.h> 
using namespace std; 
  
int n; 

struct record
{
    string id;
    string port;
    string ip;
};
 vector<string> split(string s,char delimeter){
    istringstream is(s);
    vector<string> res;
    string token;
    while(getline(is,token,delimeter)){
        res.push_back(token);
    }
    return res;

 }
  
// Driver code 
int main() 
{ 
    ifstream ifs("log.txt");
    string content( (std::istreambuf_iterator<char>(ifs) ),
                       (std::istreambuf_iterator<char>()    ) );
    vector<string> lines;
    lines = split(content,'\n');
    vector<vector<string>> words_line;
    for(int i=0;i<lines.size();i++){
        words_line.push_back(split(lines[i],' '));
        cout<<"IP address:"<<words_line[i][2]<<endl;
    }
  
    return 0; 
}