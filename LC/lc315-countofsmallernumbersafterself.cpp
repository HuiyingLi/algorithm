#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> cnt;
    void merge(vector<pair<int,int> > l, vector<pair<int,int> > r, vector<pair<int,int> >& ans){
        int i=0, j=0, k=0;
        while(i<l.size()||j<r.size()){
            if(i>=l.size()){
                ans[k]=r[j];
                k++,j++;
                continue;
            }
            if(j>=r.size()){
                ans[k]=l[i];
                k++,cnt[l[i].second]+=j, i++;
                continue;
            }
            if(l[i].first<=r[j].first){
                ans[k]=l[i];
                k++, cnt[l[i].second]+=j, i++;
            }else{
                ans[k]=r[j];
                k++,j++;
            }
        }
    }
    void mergesort(vector<pair<int,int> >& in){
        if(in.size()<2) return;
        int m=(in.size()+1)/2;
        vector<pair<int,int> > left(in.begin(),in.begin()+m);
        vector<pair<int,int> > right(in.begin()+m,in.end());
        mergesort(left);
        mergesort(right);
        merge(left, right, in);
    }
    vector<int> countSmaller(vector<int>& nums) {
        cnt=vector<int>(nums.size(),0);
        vector<pair<int,int> >in;
        for(int i=0;i<nums.size();i++)
            in.push_back(pair<int,int>(nums[i],i));
        mergesort(in);
        return cnt;
    }
};

int main(){
	int arr[4]={5,2,6,1};
	vector<int> v(arr,arr+4);
	Solution s;
	s.countSmaller(v);
	return 0;
}
