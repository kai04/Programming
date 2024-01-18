//https://leetcode.com/problems/print-foobar-alternately/submissions/
class FooBar {
private:
    int n;
    std::condition_variable cv;
    std::mutex m;
    int turn;
public:
    FooBar(int n) {
        this->n = n;
        turn =0;
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            std::unique_lock<mutex> ul(this->m);
            this->cv.wait(ul, [i,this]{
                // cout<<"FOO i:"<<i<<" turn:"<<(this->turn)<<endl;
                if((this->turn)==0){
                    return true;
                }
                return false;
            });
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            this->turn = (this->turn+1)%2;
            ul.unlock();
            this->cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            std::unique_lock<mutex> ul(this->m);
            this->cv.wait(ul, [i,this]{
                // cout<<"bar i:"<<i<<" turn:"<<(this->turn)<<endl;
                if((this->turn)==1){
                    return true;
                }
                return false;
            });
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            this->turn = (this->turn+1)%2;
            ul.unlock();
            this->cv.notify_all();
        }
    }
};