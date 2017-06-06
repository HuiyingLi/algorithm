#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
		int l=0, r=nums.size();
		int m;
		while(l<r){
			m=l+(r-l)/2;
			if(nums[m]<target){
				l=m+1;
			}else if(nums[m]==target){
				return m;
			}else{
				r=m;
			}
		}
		return l;	
    }
};
int main(){
	
	return 0;}
