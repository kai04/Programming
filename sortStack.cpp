//https://www.geeksforgeeks.org/sort-a-stack-using-recursion/
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/
/* The below method sorts the stack s 
you are required to complete the below method */
void I(int k,stack<int> &s){
    if(s.empty()){
        s.push(k);
    }
    else{
        if(k<=s.top()){
            int p =s.top();
            s.pop();
            I(k,s);
            s.push(p);
        }
        else{
        s.push(k);
        }
    }
}
void f(stack<int> &s){
    if(!s.empty()){
        int k=s.top();
        s.pop();
        f(s);
        I(k,s);
    }
}
void SortedStack :: sort()
{
    f(SortedStack :: s);
        
   //Your code here
}
