#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void swap(int i1,int i2, vector<int> &n){
        int tmp=n[i1];
        n[i1]=n[i2];
        n[i2]=tmp;
    }
    vector<int> findDuplicates(vector<int>& nums) {
        int i=0;
        int l=nums.size()-1;
		int cnt=0;
        vector<int> ans;
        while(i<nums.size()){
            if(nums[i]!=i+1&&nums[nums[i]-1]!=nums[i]){
                    swap(nums[i]-1,i, nums);
            }else
				i++;
        }
		for(int i=0;i<nums.size();i++)
			if(nums[i]!=i+1)
				ans.push_back(nums[i]);
        return ans;
    }
};

int main(){
	int a[8]={4,3,2,7,8,2,3,1};
	vector<int> in(a,a+8);
	Solution s;
	s.findDuplicates(in);
	return 0;
}
