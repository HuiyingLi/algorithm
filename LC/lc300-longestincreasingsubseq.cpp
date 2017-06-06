#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

class Solution {

public:
	int dp[10000];
    int lengthOfLIS(vector<int>& nums) {
		int ans=0;
		int n=nums.size();
		memset(dp, 0, sizeof(dp));
		for(int i=0;i<n;i++){
			int maxl=1;
			for(int k=0;k<i;k++){
				if(nums[i]>nums[k]&&dp[k]+1>maxl)
					maxl=dp[k]+1;
			}
			dp[i]=maxl;
			if(maxl>ans)
				ans=maxl;
		}
		return ans;
    }
};
int main(){return 0;}
