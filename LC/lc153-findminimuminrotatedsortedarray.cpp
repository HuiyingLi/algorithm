#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
	int findMin(vector<int> & nums){
		if(nums.size()==1)
			return nums[0];
		int l=0, r=nums.size()-1;
		while(l+1!=r){
			if(nums[l]>nums[r]){
				int mid=l+(r-l)/2;
				if(nums[mid]>nums[l]){
					l=mid;
				}else{
					r=mid;
				}
			}
		}
		if(nums[l]>nums[r])
		return nums[r];
		else
			return num[0];
	}
};
int main(){return 0;}
