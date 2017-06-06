#include<vector>
#include<iostream>

using namespace std;
struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        //cout<<"*****";
        int l=0, r=intervals.size();
        if(r==0){
            intervals.push_back(newInterval);
            return intervals;
        }
        int ts=newInterval.start, te=newInterval.end;
        int mid;
        while(l<r){
            mid=l+(r-l)/2;
            if(intervals[mid].start<ts)
                l=mid+1;
            else if(intervals[mid].start>=ts)
                r=mid;
        }
        int dels=-1;
        if(l==0) dels=l;
        if(l>0){
            if(intervals[l-1].end>=ts)
                dels=l-1;
            else
                dels=l;
        }
        l=0,r=intervals.size();
        while(l<r){
            mid=l+(r-l)/2;
            //cout<<"l:"<<l<<" r:"<<r<<" m:"<<mid<<endl;
            if(intervals[mid].end<te)
                l=mid+1;
            else if(intervals[mid].end>=te)
                r=mid;
            
        }
        //cout<<l<<endl;
        int dele=-1;
        if(intervals[l].start<=te)
            dele=l;
        else
            dele=l-1;
        //cout<<dels<<" "<<dele<<endl;
        if(dels>dele){
            intervals.insert(intervals.begin()+dels,newInterval);
            return intervals;
        }
        vector<Interval> ans;
        Interval ni(ts, te);
        for(int i=0;i<=intervals.size();i++){
            if(i<intervals.size()&&(i<dels||i>dele)){
                ans.push_back(intervals[i]);
            }
            if(i==dels){
                if(i<intervals.size())
                    ni.start=min(intervals[i].start,ts);
            }
            if(i==dele){
                if(i<intervals.size())
                    ni.end=max(intervals[i].end,te);
                ans.push_back(ni);
            }
        }
        //if(dele==intervals.size()){
        //    ni.end=te;
        //    ans.push_back(ni);
        //}
        return ans;
    }
};
int main(){
	Interval i1(1,3);
	Interval i2(6,9);
	Interval i3(2,5);
	vector<Interval> v;
	v.push_back(i1);
	v.push_back(i2);
	Solution s;
	s.insert(v, i3);
	
}
