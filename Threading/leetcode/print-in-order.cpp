//https://leetcode.com/problems/print-in-order/submissions/
class Foo {
public:
    std::mutex m;
    int turn;
    std::condition_variable cv;
    Foo() {
        turn =1;
    }

    void first(function<void()> printFirst) {
        std::unique_lock<std::mutex> ul(this->m);
        this->cv.wait(ul, [this] {
            // cout<<"FIRST turn:"<<(this->turn)<<endl;
            if((this->turn) ==1){
                (this->turn) =2;
                return true;
            }
            return false;
        });
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        ul.unlock();
        this->cv.notify_all();
    }

    void second(function<void()> printSecond) {
        std::unique_lock<std::mutex> ul(this->m);
        
        this->cv.wait(ul, [this] {
            // cout<<"SECOND turn:"<<(this->turn)<<endl;
            if((this->turn) ==2){
                (this->turn) =3;
                return true;
            }
            return false;
        });
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        ul.unlock();
        this->cv.notify_all();
    }

    void third(function<void()> printThird) {
        std::unique_lock<std::mutex> ul(this->m);
        
        this->cv.wait(ul, [this] {
            // cout<<"THIRD turn:"<<(this->turn)<<endl;
            if((this->turn) ==3){
                (this->turn) =1;
                return true;
            }
            return false;
        });
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        ul.unlock();
        this->cv.notify_all();
    }
};