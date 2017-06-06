#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
		int diff=target-nums[0]-nums[1]-nums[2];
		sort(nums.begin(),nums.end());
		for(int i=0;i<nums.size()-2;i++){
			int l=i+1, r=nums.size()-1;
			while(l<r){
				int s=nums[i]+nums[l]+nums[r];
				int d=target-s;
				if(d==0)
					return target;
				if(fabs(d)<fabs(diff))
					diff=d;
				if(s<target){
					while(l<nums.size()-1&&nums[l+1]==nums[l])
						l++;
					l++;
				}else if(s>target){
					while(r>0&&nums[r-1]==nums[r])
						r--;
					r--;
				}
			}	
		}
		return target-diff;
    }
};
int main(){
	int arr[5]={85, -66, 74, 78, -37};
	vector<int> in(arr, arr+5);
	Solution s;
	cout<<s.threeSumClosest(in, 56)<<endl;
	return 0;
}
