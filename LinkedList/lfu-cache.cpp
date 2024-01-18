//https://leetcode.com/problems/lfu-cache/submissions/
struct List_Node{
    int key,count,value; 
    List_Node* prev, *next;
    List_Node(){
        key = -1;
        value = -1;
        count=0;
        prev = NULL;
        next = NULL;
    }
    List_Node(int k, int v){
        key = k;
        value = v;
        count = 1;
        prev = NULL;
        next = NULL;
    }
};
class LFUCache {
public:
    unordered_map<int,List_Node*> m;
    unordered_map<int, List_Node*> v;
    int capacity, min_ix;
    LFUCache(int cap) {
        capacity = cap;
        min_ix = 0;
    }

    void printListNode(List_Node* curr){
        cout<<"Printing list node....."<<endl;
        while(curr!=NULL){
            cout<<"curr address:"<<curr<<" curr:"<<curr->key<<" count:"<<curr->count<<endl;
            if(curr->prev!=NULL){
                cout<<"prev address:"<<curr->prev<<" prev:"<<(curr->prev)->key<<endl;
            } else{
                cout<<"prev address:NULL"<<endl;
            }
            if(curr->next!=NULL){
                cout<<"next address:"<<curr->next<<" next:"<<(curr->next)->key<<endl;
            } else{
                cout<<"next address:NULL"<<endl;
            }          
            cout<<"--------------------------------------------"<<endl;
            curr=curr->next;
        }
        cout<<"=================================="<<endl;
    }
    void printMap(unordered_map<int, List_Node*> &v){
        cout<<"printing map......"<<endl;
        for(auto it:v){
            cout<<"key:"<<it.first<<" Node address:"<<it.second<<" count:"<<it.second->count<<endl;
            // printListNode(it->second);
            // cout<<"**********************************"<<endl;
        }
        cout<<"______________________________________"<<endl;
    }
    void printWholeData(){
        cout<<"Printing whole data....."<<endl;
        for(auto it:v){
            int k = it.first;
            cout<<"key count:"<<k<<endl;
            printListNode(it.second);
            cout<<"_______________________________"<<endl;
        }
        cout<<"****************************************"<<endl;
    }
    void removeFromFront(){
        // printWholeData();
        List_Node* curr = v[min_ix];
        if(curr->next==NULL){
            m.erase(curr->key);
            v.erase(min_ix);
        } else{
            m.erase(curr->key);
            v[min_ix] = curr->next;
            (curr->next)->prev = NULL;
        }
    }

    void insertAtEnd(int ix, List_Node* l){
        auto it = v.find(ix);
        if(it==v.end()){
            v[ix] = l;
            l->next=NULL;
            l->prev=NULL;
        } else{
            List_Node* curr = v[ix];
            while(curr->next!=NULL){
                curr = curr->next;
            }
            curr->next = l;
            l->prev = curr;
            l->next=NULL;
        }
    }

    void adjust(List_Node* curr, int old_ix, int new_ix){
        int cnt = curr->count;
        List_Node* prev_node = curr->prev;
        List_Node* next_node = curr->next;
        if(prev_node!=NULL){
            prev_node->next = next_node;
        } else{
            v[old_ix] = next_node;
            if(next_node==NULL){
                v.erase(old_ix);
                if(old_ix==min_ix){
                    min_ix = new_ix;
                }
            }
        }

        if(next_node!=NULL){
            next_node->prev = prev_node;
        }
        insertAtEnd(new_ix, curr);
    }

    int get(int key) {
        auto it=m.find(key);
        if(it!=m.end()){
            List_Node* t = it->second;
            int cnt = t->count;
            int val = t->value;
            adjust(t,cnt, cnt+1);
            t->count = cnt+1;
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto it=m.find(key);
        if(it!=m.end()){
            // key present
            List_Node* t = it->second;
            int cnt = t->count;
            t->value = value;
            adjust(t,cnt, cnt+1);
            t->count = cnt+1;
        } else{
            // key absent
            int sz = m.size();
            if(sz<capacity){
                //capicity is available -> No replacement
                List_Node *t = new List_Node(key,value);
                insertAtEnd(1,t);
                min_ix = 1;
                m[key] = t;
            }else{
                //capicity is unavailable -> replacement
                removeFromFront();
                List_Node *t = new List_Node(key,value);
                insertAtEnd(1,t);
                min_ix = 1;
                m[key] = t;
            }
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */