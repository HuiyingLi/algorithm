#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

class Solution {
public:
	int dp[100000];
    int coinChange(vector<int>& coins, int amount) {
		memset(dp,-1,sizeof(dp));
		dp[0]=0;
		sort(coins.begin(),coins.end());
		for(int i=0;i<=amount;i++){
			int min=100000;
			bool f=false;
			for(int j=0;j<coins.size();j++){
				if(i-j<0){
					break;
				}
				int c=dp[i-j]+1;
				if(c==0){
					continue;
				}
				if(c<min)
					min=c;
				f=true;
			}
			if(f)
				dp[i]=min;
			else
				dp[i]=-1;
		}
		return dp[amount];
    }
};
int main(){return 0;}
