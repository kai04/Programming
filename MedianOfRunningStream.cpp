//Find median of running stream
//https://www.geeksforgeeks.org/median-of-stream-of-running-integers-using-stl/
//https://www.hackerrank.com/challenges/find-the-running-median/problem

#include <bits/stdc++.h>
#include<iomanip>
using namespace std;
void showpq(priority_queue <int> gq)
{
    priority_queue <int> g = gq;
    while (!g.empty())
    {
        cout << g.top()<<" ";
        g.pop();
    }
    cout <<endl;
}


void showpqi(priority_queue<int,vector<int>,greater<int>> gq)
{
    priority_queue<int,vector<int>,greater<int>> g = gq;
    while (!g.empty())
    {
        cout << g.top()<<" ";
        g.pop();
    }
    cout <<endl;
}
double findMedian(priority_queue<int> maxHeap,priority_queue<int,vector<int>,greater<int>> minHeap){
    if(maxHeap.size()==minHeap.size()){
        return (((double)maxHeap.top()+(double)minHeap.top())/2);
    }
    else if(maxHeap.size()>minHeap.size()){
        return (maxHeap.top());
    }
    else{
        return (minHeap.top());
    }
}

void myInsert(priority_queue<int> &maxHeap,priority_queue<int,vector<int>,greater<int>> &minHeap,int x,double median){
    if(maxHeap.size()==0 || minHeap.size()==0){
        if(minHeap.size()==0)
            minHeap.push(x);
        else{
            maxHeap.push(x);
        }
    }
    else if(maxHeap.size()>minHeap.size()){
        if(x<median){
            int y = maxHeap.top();
            maxHeap.pop();
            minHeap.push(y);
            maxHeap.push(x);
        }
        else{
            minHeap.push(x);
        }
    }
    else if(maxHeap.size()<minHeap.size()){
        if(x>median){
            int y = minHeap.top();
            minHeap.pop();
            maxHeap.push(y);
            minHeap.push(x);
        }
        else{
            maxHeap.push(x);
        }
    }
    //maxHeap.size()==minHeap.size()
    else{
        //curr element is greater than median than insert in minHeap otherwise maxHeap   
        if(x>median){
            minHeap.push(x);
        }
        else{
            maxHeap.push(x);
        }
    }
}
vector<double> runningMedian(vector<int> a) {
    /*
     * Write your code here.
     */
    int n=a.size();
    vector<double> res;
    double median;
    //maxHeap
    priority_queue<int> maxHeap;
    //minHeap
    priority_queue<int,vector<int>,greater<int>> minHeap;
    for(int i=0;i<n;i++){
        if(i==0){
            if(n>1){
                if(a[0]<a[1]){
                    maxHeap.push(a[i]);
                }
                else{
                    minHeap.push(a[i]);
                }
            }
            
            median=a[i];
            res.push_back(median);
            //myInsert(maxHeap,minHeap,a[i],median);
            
        }
        else if(i==1){
            median=((double)a[0]+(double)a[1])/2;
            res.push_back(median);
            myInsert(maxHeap,minHeap,a[i],median);
        }
        else{
           myInsert(maxHeap,minHeap,a[i],median);
            // cout<<"i:"<<i<<" prev median:"<<median<<endl;
            // cout<<"printing maxHeap...."<<endl;
            // showpq(maxHeap);
            // cout<<"-----------------------------------"<<endl;
            // cout<<"printing minHeap...."<<endl;
            // showpqi(minHeap);
            // cout<<"-----------------------------------"<<endl;
           median=findMedian(maxHeap,minHeap);  
            // cout<<"new median:"<<median<<endl;
            // cout<<"==================================================="<<endl;
            
            res.push_back(median);
        }

    }
    return res;

}
int main() {
    int n;
    cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    vector<double> res=runningMedian(a);
    // cout<<std::fixed;
    // cout<<std::setprecision(1);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<endl;
    }
	//code
	return 0;
}
