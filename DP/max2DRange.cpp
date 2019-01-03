#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<vector<int> > mat(n,vector<int> (n));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>mat[i][j];
		}
	}
	cout<<"here1"<<endl;
	vector<vector<int> > mat1(n,vector<int> (n));
	mat1[0][0]=mat[0][0];
	/*for(int i=1;i<n;i++)
		mat1[i][0]=mat1[i-1][0]+mat[i][0];
	for(int i=1;i<n;i++)
		mat1[0][i]=mat1[0][i-1]+mat[0][i];*/
	cout<<"here2"<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i>0)
				mat[i][j]+=mat[i-1][j];
			if(j>0)
				mat[i][j]+=mat[i][j-1];
			if(i>0 && j>0)
				mat[i][j]-=mat[i-1][j-1];
			// mat1[i][j]=(mat1[i-1][j]+mat1[i][j-1])+mat[i][j];
			// cout<<" mat1[i-1][j]:"<<mat1[i-1][j]<<" mat1[i][j-1]:"<<mat1[i][j-1]<<" mat[i][j]:"<<mat[i][j]<<endl;
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}

	cout<<"here3"<<endl;
	int ans =INT_MIN;
	int ansi,ansj,ansk,ansl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
		//(i,j) starting vertex
			for(int k=i;k<n;k++){
				for(int l=j;l<n;l++){
					//diagonal ending vertex (k,l)
					int temp;
					if(i>0 && j>0)
						temp = mat[k][l]-(mat[i-1][l]+mat[k][j-1])+mat[i-1][j-1];
					else if(i==0 && j==0)
						temp=mat[k][l];
					else if(i==0 && j>0)
						temp=mat[k][l]-(mat[k][j-1]);
					else if(j==0 && i>0)
						temp = mat[k][l]-(mat[i-1][l]);
					if(temp>=ans){
						ans=max(ans,temp);
						ansi=i;
						ansj=j;
						ansk=k;
						ansl=l;	
					}

					
				}
			}
		}
	}
	cout<<ans<<endl;
	cout<<"i:"<<ansi<<" j:"<<ansj<<" k:"<<ansk<<" l:"<<ansl<<endl;

	return 0;
}