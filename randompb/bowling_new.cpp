#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin>>s;
    int n = s.length();
    for(int i=0;i<n;i++){
		if(s[i]=='X'){
			s.insert(i+1,"0");
		}else if(s[i]=='-'){
			s[i] = '0';
		}
		
	}
	n = s.length();
	vector<int> frame_score(10,0);
	vector<int> spare_score(10,0);
	vector<int> strike_score(10,0);
	for(int i=0;i<n;i++){
		if(i%2==1){
			if(s[i-1]=='X' || s[i]=='/'){
				frame_score[i/2] = 10;
			}else{
				frame_score[i/2] = (s[i-1] - '0')+(s[i] - '0');
			}
		}
	}
	//spare score calculation
	for(int i=0;i<n;i++){
		if(i%2==1){
			if(s[i]=='/'){
				if(s[i+1]=='X'){
					spare_score[i/2] = 10;
				}
				else{
					spare_score[i/2] = (s[i+1] - '0');
				}
			}
		}
	}
	
	//strike score calculation
	for(int i=0;i<n;i++){
		if(i%2==0){
			if(s[i]=='X'){
				if(s[i+2]=='X'){
					if(s[i+4]=='X'){
						strike_score[i/2] = 20;
					}
					else{
						strike_score[i/2] = 10 + (s[i+4] - '0');
					}
				}
				else{
					strike_score[i/2] = frame_score[(i/2)+1];
				}
			}
		}
	}
	
	vector<int> score(10,0);
	for(int i=0;i<10;i++){
		score[i] = frame_score[i] + spare_score[i] + strike_score[i];
		cout<<"Frame no:"<<i<<" Has Score:"<<score[i]<<endl;
	}
	
	
}
