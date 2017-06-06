#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {

public:
    vector<string> summaryRanges(vector<int>& nums) {
		vector<string> ans;
		if(nums.size()==0)return ans;
		int l=nums[0];
		if(nums.size()==1){
			ans.push_back(to_string(l));
			return ans;
		}
		for(int i=1;i<nums.size();i++){
			if(nums[i]==nums[i-1]+1)
				continue;
			else{
				int r=nums[i-1];
				if(l==r){
					ans.push_back(to_string(l));
				}else{
					ans.push_back(to_string(l)+"->"+to_string(r));
				}
				l=nums[i];
			}
		}
		int r=nums[nums.size()-1];
		if(l==r){
			ans.push_back(to_string(l));
		}else{
			ans.push_back(to_string(l)+"->"+to_string(r));
		}
		return ans;
    }
};
int main(){
	vector<int> in;
	
	return 0;}
