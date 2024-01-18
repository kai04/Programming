#include<bits/stdc++.h>

#include<semaphore.h>



using namespace std;
int turn;
sem_t mutex_a;
sem_t mutex_b;
sem_t mutex_c; 

void printA(){
    for(int i=0;i<10;i++){
        sem_wait(&mutex_a);
        cout<<"A";
        sem_post(&mutex_b);
    }
}

void printB(){
    for(int i=0;i<10;i++){
        sem_wait(&mutex_b);
        cout<<"B";
        sem_post(&mutex_c);
    }
}

void printC(){
    for(int i=0;i<10;i++){
        sem_wait(&mutex_c);
        cout<<"C";
        sem_post(&mutex_a);
    }
}

int main(){
    turn = 0;
    int value;
    sem_init(&mutex_a, 0, 1);
    sem_init(&mutex_b, 0, 0);
    sem_init(&mutex_c, 0, 0);
    // sem_getvalue(&mutex_a, &value);
    std::thread t1(printA);
    std::thread t2(printB);
    std::thread t3(printC);

    t1.join();
    t2.join();
    t3.join();
    cout<<endl;

    return 0;
}