#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
		int i=0;
		int j=i+nums[i];
		while(i<nums.size()&&i<=j){
			if(i+nums[i]>j)
				j=i+nums[i];
			i++;
		}
		if(j!=nums.size()-1)
			return false;
		return true;
    }
};
int main(){
	int arr[5]={3,2,1,0,4};
	vector<int> v(arr,arr+5);
	Solution s;
	cout<<s.canJump(v);
	return 0;}
