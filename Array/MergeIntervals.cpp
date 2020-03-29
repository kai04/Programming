/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */


class Solution {
public:
   
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),[](Interval a, Interval b){return a.start < b.start;});
        int n = intervals.size();
        vector<Interval> result;
        if(n==0)
            return result;
      
        int i=0;
       /* for(vector<Interval>::iterator it = intervals.begin();it != intervals.end();it++){
            cout<<"("<<it->start<<","<<it->end<<")"<<endl;
        }*/
        result.push_back(intervals[0]);
        for(i=1;i<n;i++){
            if(result.back().end<intervals[i].start){
                result.push_back(intervals[i]);
            }
            else{
                result.back().end = max(result.back().end,intervals[i].end);
            }
        }
        return result;
        }
};
