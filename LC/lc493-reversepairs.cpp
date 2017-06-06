#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int total;
    void merge(vector<long> l, vector<long> r, vector<long>& ans){
        int i=0, j=0, k=0;
        while(i<l.size()||j<r.size()){
            if(i>=l.size()){
                ans[k]=r[j];
                k++,j++;
                continue;
            }
            if(j>=r.size()){
                ans[k]=l[i];
                k++, i++;
                continue;
            }
            if(l[i]<=r[j]){
                ans[k]=l[i];
                k++, i++;
            }else{
                ans[k]=r[j];
                k++,j++;
            }
        }
        i=0, j=0, k=0;
        while(i<l.size()||j<r.size()){
            if(i>=l.size()){
                break;
            }
            if(j>=r.size()){
                //total+=j*(l.size()-i-1);
                break;
            }
            if(l[i]<=2*r[j]){
                i++;
            }else{
                total+=l.size()-i,j++;
            }
        }
        
    }
    void mergesort(vector<long>& in){
        if(in.size()<2) return;
        int m=(in.size()+1)/2;
        vector<long> left(in.begin(),in.begin()+m);
        vector<long> right(in.begin()+m,in.end());
        mergesort(left);
        mergesort(right);
        merge(left, right, in);
    }
    int reversePairs(vector<int>& nums) {
        
        //cout<<LONG_MAX<<endl; return 0;
        total=0;
        
        vector<long> v(nums.begin(),nums.end());
        mergesort(v);
        return total;
    }
};

int main(){
	int arr[5]={5,1,3,10,1};
	vector<int> v(arr,arr+5);
	Solution s;
	cout<<s.reversePairs(v)<<endl;
	return 0;
}
