#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
		
		int len=INT_MAX;
		int start=0;
		int sum=0;
		for(int i=0;i<nums.size();i++){
			sum+=nums[i];
			if(sum>=s){
				int j=start;
				while(sum-nums[start]>=s){
					sum-=nums[start];
					start++;
				}
				if(i-start+1<len)
					len=i-start+1;
			}
		}
		if(len==INT_MAX)
			return 0;
		return len;
    }
};
int main(){
	
	return 0;
}
