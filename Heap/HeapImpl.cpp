#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

const int MAX_SIZE = 1<<30;
template<class T1,class T2>
class HashtableEntry{
public:
    T1 key;
    T2 value;
    HashtableEntry* next;
    HashtableEntry(T1 k,T2 v){
        key = k;
        value = v;
        next =  NULL;
    }
};
   
template<class T1,class T2>
class HashTable{
public:
    int size;
    vector<HashtableEntry<T1,T2>*> storage;
    HashTable(){
        storage.resize(MAX_SIZE, NULL);
        size = 0;
    }

    int getKeyHash(int key){
        return key%MAX_SIZE;
    }
    int getSize(){
        return size;
    }

    T2 getValue(int key){
            int hash_code = getKeyHash(key);
            HashtableEntry<T1,T2>* curr = this->storage[hash_code];
            while(curr!=NULL){
                if(curr->key==key){
                    return curr->value;
                }
                curr = curr->next;
            }
            if(typeid(this->storage[hash_code]->value)==typeid(int)){
                cout<<"key:"<<key<<" not found"<<endl;
                return T2();
            } else if(typeid(this->storage[hash_code]->value)==typeid(string)){
                cout<<"key:"<<key<<" not found"<<endl;
                return T2();
            } else{
                cout<<"Invalid value type and key not found"<<endl;
                return T2();
            }
            return T2();
    }

    void setHashEntry(int key,T2 val){
        int hash_code = getKeyHash(key);
        HashtableEntry<T1,T2>* head = this->storage[hash_code];  
        HashtableEntry<T1,T2>* curr = new HashtableEntry<T1,T2>(key,val);
        curr->next = head;
        this->storage[hash_code] = curr;
        this->size++;
    }

    void remove(int key){
        int hash_code = getKeyHash(key);
        HashtableEntry<T1,T2>* curr = this->storage[hash_code];
        HashtableEntry<T1,T2>* prev = NULL;
        while(curr!=NULL){
            if(curr->key==key){
                if(prev==NULL){
                    this->storage[hash_code] =  curr->next; 
                } else{
                    prev->next = curr->next;
                }
                this->size--;
                return ;
            }
            prev = curr;
            curr = curr->next;
        }
    }
};


int main(){
    HashTable<int,string> *m = new HashTable<int,string>();
    m->setHashEntry(4,"Saurav");
    m->setHashEntry(24,"Sau");
    m->setHashEntry(9,"Sau");
    cout<<"SIZE of hashmap:"<<m->getSize()<<endl;
    cout<<"Key:"<<24<<" found with value:"<<m->getValue(24)<<endl;
    cout<<"Key:"<<2<<" found with value:"<<m->getValue(2)<<endl;
    
    return 0;
}

