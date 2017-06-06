#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
		if(nums.size()==0) return 0;
		if(nums.size()==1) return nums[0];
		int pvt;
		vector<int> gt;
		vector<int> lt;
		while(gt.size()!=k-1){
			pvt=nums[0];
			for(int i=1;i<nums.size();i++){
				if(nums[i]>=pvt)
					gt.push_back(nums[i]);
				else
					lt.push_back(nums[i]);
			}
			if(gt.size()>k-1){
				nums=gt;
			}else if(gt.size()<k-1){
				nums=lt;
				k-=(gt.size()+1);
			}
			gt.clear();
			lt.clear();	
		}
		return pvt;
    }
};
int main(){
	int arr[10]={3,6,8,0,-7,7,3,1,-1,0};
	vector<int> v(arr, arr+10);
	Solution s;
	cout<<s.findKthLargest(v, 4);
	return 0;}
