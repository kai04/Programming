/*Program generate spiral grid of natural number of n*n dimension for any n
*/

#include<bits/stdc++.h>

using namespace std;

void printM(vector<vector<int>> A){
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[i].size();j++){
            cout<<A[i][j]<<" ";   
        }
        cout<<endl;
    }


}
bool check(int x,int y,int n){
    if(x>=0 && y>=0 && x<n && y<n){
        return true;
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> a(n,vector<int>(n,0));

//L,R,U,D
    int xdir[4]={0,0,-1,1};
    int ydir[4]={-1,1,0,0};

    int start_r=0;
    int end_r=n-1;
    int start_c=0;
    int end_c=n-1;

    int x=0,y=0;
    int i=1;
    char dir='R';
    while(i<=(n*n)){
//cout<<"i:"<<i<<" n:"<<n<<" start_r:"<<start_r<<" end_r:"<<end_r<<" start_c:"<<start_c<<" end_c:"<<end_c<<" dir:"<<dir<<" x:"<<x<<" y:"<<y<<endl;
        if(dir=='R'){
            x=start_r;
            y=start_c;

            while(y<=end_c){

                if(check(x,y,n))
                {
                    a[x][y]=i;
//      cout<<" ->"<<" x:"<<x<<" y:"<<y<<endl;
                }
                x+=xdir[1];
                y+=ydir[1];


                i++;
            }

            start_r++;
            dir='D';
        }
        else if(dir=='L'){
            x=end_r;
            y=end_c;

            while(y>=start_c){
                if(check(x,y,n))
                {
                    a[x][y]=i;
//  cout<<" ->"<<" x:"<<x<<" y:"<<y<<endl;
                }
                x+=xdir[0];
                y+=ydir[0];


                i++;
            }

            end_r--;
            dir='U';
        }
        else if(dir=='U'){
            x=end_r;
            y=start_c;

            while(x>=start_r){

                if(check(x,y,n))
                {
                    a[x][y]=i;
//        cout<<" ->"<<" x:"<<x<<" y:"<<y<<endl;
                }
                x+=xdir[2];
                y+=ydir[2];


                i++;
            }


            start_c++;
            dir='R';
        }
        else{
            x=start_r;
            y=end_c;

            while(x<=end_r){

                if(check(x,y,n))
                {
                    a[x][y]=i;
//        cout<<" ->"<<" x:"<<x<<" y:"<<y<<endl;
                }
                x+=xdir[3];
                y+=ydir[3];


                i++;
            }

            end_c--;
            dir='L';
        }

    }
    printM(a);

    return 0;
}
