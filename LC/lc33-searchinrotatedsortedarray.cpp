#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
	int search(vector<int>& nums, int target){
		if(nums.size()==1){
			if(nums[0]==target)
				return 0;
			return -1;
		}
		int l=0, r=nums.size()-1;
		int pvt=0;
		int mid;
		if(nums[l]>nums[r]){
			while(l+1!=r){
				int mid=l+(r-l)/2;
				if(nums[mid]>nums[l]){
					l=mid;
				}else{
					r=mid;
				}
	
			}
			pvt=r;
		}
		if(nums[0]<target){
			l=0;
			r=pvt==0?nums.size():pvt;
		}else if(nums[0]>target){
			l=pvt;
			r=nums.size();
		}else{
			return 0;
		}
		while(l<r){
			mid=l+(r-l)/2;
			if(nums[mid]==target){
				return mid;
			}
			if(nums[mid]>target){
				r=mid;
			}else{
				l=mid+1;
			}
		}
		return -1;
	}
};
int main(){
	int arr[2]={0,1};
	vector<int> v(arr, arr+2);
	Solution s;
	cout<<s.search(v,1000);
	cout<<s.search(v,5);
	cout<<s.search(v,0);
	return 0;
}
