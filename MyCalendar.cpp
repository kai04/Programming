//https://leetcode.com/problems/my-calendar-i/
class MyCalendar {
public:
    struct Interval{
        int start;
        int end;
        Interval(int s, int e){
            start = s;
            end = e;
        }
    };
    vector<Interval> v;
    MyCalendar() {
        
    }
    

    bool isOverlap(Interval *i1, Interval *i2){
        bool c1 = (i2->start >= i1->start && i2->start < i1->end);
        bool c2 = (i2->end > i1->start && i2->end <= i1->end); 
        bool c3 = (i1->start > i2->start && i1->start < i2->end);
        bool c4 = (i1->end > i2->start && i1->end < i2->end);
        if( c1||c2)
            return true;
        if( c3 || c4)
            return true;
        return false;
    }
    bool book(int start, int end) {
        bool ans;
        if(v.size()==0){
            v.push_back(Interval(start,end));
            ans = true;
        } else{
            Interval *temp = new Interval(start,end);
            for(int i = 0;i<v.size();i++){
                if(isOverlap(temp,&v[i])){
                    ans = false;
                    return ans;
                }
            }
            v.push_back(Interval(start,end));
            ans = true;
        }
        return ans;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
