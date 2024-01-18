//https://leetcode.com/problems/fizz-buzz-multithreaded/submissions/
class FizzBuzz {
private:
    int n;
    

public:
    int i;
    std::condition_variable cv;
    std::mutex m;
    FizzBuzz(int n) {
        this->n = n;
        i = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while(true){
            unique_lock<mutex> ul(m);
            // cv.wait(ul, [this]{
            //     // cout<<"FIZZ i:"<<x<<endl;
            //     if((this->i)<=(this->n) && i%3==0 && i%5!=0){
            //         return true;
            //     } 
            //     return false;
            // });
            while (i <= n && (i % 5 == 0 || i % 3 != 0))
                cv.wait(ul);
            if(i>(this->n)){
                ul.unlock();
                return;
            }
            printFizz();
            i++;
            ul.unlock();
            cv.notify_all();
        }
        return;
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while(true){
            unique_lock<mutex> ul(m);
            // cv.wait(ul, [this]{
            //     // int x = (this->i);
            //     // cout<<"buzz i:"<<x<<endl;
            //     if((this->i)<=(this->n) && i%3!=0 && i%5==0){
            //         return true;
            //     } 
            //     return false;
            // });
            while (i <= n && (i % 5 != 0 || i % 3 == 0))
                cv.wait(ul);
            if(i>(this->n)){
                ul.unlock();
                return;
            }
            printBuzz();
            i = i + 1;
            ul.unlock();
            cv.notify_all();
        }
        // ul.unlock();
        return;
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz) {
        while(true){
            unique_lock<mutex> ul(m);
            // cv.wait(ul, [this]{
            //     // int x = (this->i);
            //     // cout<<"FIZZ BUZZ i:"<<x<<endl;
            //     if((this->i)<=(this->n) && i%3==0 && i%5==0){
            //         return true;
            //     } 
            //     return false;
            // });
            while (i <= n && (i % 5 != 0 || i % 3 != 0))
                cv.wait(ul);
            if(i>(this->n)){
                ul.unlock();
                return;
            }
            printFizzBuzz();
            i = i + 1;
            ul.unlock();
            cv.notify_all();
        }
        // ul.unlock();
        return;      
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while((this->i)<=(this->n)){
            unique_lock<mutex> ul(m);
            // cv.wait(ul, [this]{
            //     int x = (this->i);
            //     // cout<<"NUMBER i:"<<x<<endl;
            //     if((this->i)<=(this->n) && x%3!=0 && x%5!=0){
            //         return true;
            //     } 
            //     return false;
            // });
            while (i <= n && (i % 5 == 0 || i % 3 == 0))
                cv.wait(ul);
            if((this->i)>(this->n)){
                ul.unlock();
                return;
            }
            printNumber((this->i));
            (this->i) = (this->i) + 1;
            ul.unlock();
            cv.notify_all();
        }
        // ul.unlock();
        return;      
    }
};