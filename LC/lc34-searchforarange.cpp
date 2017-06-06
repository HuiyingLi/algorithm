#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> ans;
		ans.push_back(-1);
		ans.push_back(-1);
		if(ans.size()==0)
			return ans;
		int l=0, r=nums.size()-1;
		int m;
		bool flag=false;
		while(l<r){
			m=l+(r-l)/2;
			if(nums[m]>target){
				r=m;
			}else if(nums[m]==target){
				if(m==0||nums[m-1]<target){
					ans[0]=m;
					flag=true;
					break;
				}else{
					r=m;
				}
			}else if(nums[m]<target){
				l=m+1;
			}
		}
		if(!flag&&nums[l]==target)
			ans[0]=l;
		else if(!flag&&nums[l]!=target)
			return ans;
		l=0;
		r=nums.size()-1;
		flag=false;
		while(l<r){
			m=l+(r-l)/2;
			if(nums[m]>target){
				r=m;
			}else if(nums[m]==target){
				if(m==nums.size()-1||nums[m+1]>target){
					ans[1]=m;
					flag=true;				
					break;
				}else{
					l=m+1;
				}
			}else if(nums[m]<target){
				l=m+1;
			}
		}
		if(!flag&&nums[l]==target)
			ans[1]=l;
		return ans;
    }
};
int main(){
	int arr[2]={35,50};
	vector<int> in(arr, arr+2);
	Solution s;
	vector<int> ans=s.searchRange(in, 11);
	cout<<ans[0]<<" "<<ans[1]<<endl;
	return 0;
}
