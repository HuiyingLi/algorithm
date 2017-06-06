#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
		if(nums.size()<=1)
			return;
		int r=nums.size()-1;
		while(r>0&&nums[r-1]>=nums[r])
			r--;
		r--;
		if(r<0){
			sort(nums.begin(),nums.end());
			return;
		}	
		int i=r+1;
		while(i<nums.size()&&nums[i]>nums[r])
			i++;
		i--;
		int tmp=nums[i];
		nums[i]=nums[r];
		nums[r]=tmp;
		sort(nums.begin()+r+1,nums.end());
    }
};
int main(){
	int arr[5]={5,4,3,2,1};
	vector<int> v(arr, arr+5);
	Solution s;
	s.nextPermutation(v);
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<" ";
	cout<<endl;
	return 0;
}
