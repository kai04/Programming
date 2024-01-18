class ZeroEvenOdd {
private:
    int n;
    int turn;
    std::mutex m;
    std::condition_variable cv;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        turn =0;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for(int i=0;i<(this->n);i++){
            unique_lock<mutex> ul(this->m);
            this->cv.wait(ul, [i,this]{
                cout<<"ZERO i:"<<i<<" turn:"<<(this->turn)<<endl;
                if((this->turn)==0){
                    return true;
                } else {
                    return false;
                }
            });
            printNumber(0);
            if(i%2==0){
                this->turn =1;
            } else{
                this->turn =2;
            }
            ul.unlock();
            this->cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        for(int i=2;i<2*(this->n);i=i+2){
            unique_lock<mutex> ul(this->m);
            this->cv.wait(ul, [i,this]{
                cout<<"EVEN i:"<<i<<" turn:"<<(this->turn)<<endl;
                if((this->turn)==2){
                    return true;
                } else {
                    return false;
                }
            });
            printNumber(i);
            this->turn =0;
            ul.unlock();
            this->cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        for(int i=1;i<2*(this->n);i=i+2){
            unique_lock<mutex> ul(this->m);
            cv.wait(ul, [i,this]{
                cout<<"ODD i:"<<i<<" turn:"<<(this->turn)<<endl;
                if((this->turn)==1){
                    return true;
                } else {
                    return false;
                }
            });
            printNumber(i);
            this->turn =0;
            ul.unlock();
            this->cv.notify_all();
        }
    }
};