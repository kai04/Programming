#include<bits/stdc++.h>
using namespace std;
/*
[0,1,2,3,4,5,3,2,1,0]
 0 1 2 3 4 5 6 7 8 9
ret: 1 8
*/

int find_pivot(){

	
}

int binary_search(int l,int h,int x,vector<int> &a){
	int mid = l + ((h-l)/2);
	if(l>h){
		return -1;
	}
	if(a[mid]==x){
		return mid;
	}
	else if(a[mid]>x){
		return binary_search(l,mid-1,x,a);
	}
	else{
		return binary_search(mid+1,h,x,a);	
	}
}

int main(){
	return 0;
}