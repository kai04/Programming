// you can use includes, for example:
// #include <algorithm>

// you can write to stderr for debugging purposes, e.g.
// cerr << "this is a debug message" << endl;
void print(int max1,int k){
    for(int j=0;j<k;j++){
        cout<<"+";
    for(int i=0;i<max1;i++){
           cout<<"-";
        }
    }
    cout<<"+"<<endl;
    }
void solution(vector<int> &A, int K) {
    vector<string> nums;
    
    int max1=-1;
    for(int i=0;i<A.size();i++){
        int x = (to_string(A[i]).length());
        max1=max(max1,x);
    }
        
        for(int j=0;j<A.size();j++){
           if(j%K==0)
                {
                    print(max1,K);
                    cout<<"|";
                }
            cout<<A[j]<<"|";
                
        }
        print(max1,A.size()%K);
    // write your code in C++14 (g++ 6.2.0)
}