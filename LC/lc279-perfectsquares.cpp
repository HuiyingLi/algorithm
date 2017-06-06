#include<iostream>
#include<string.h>

using namespace std;

class Solution {
public:
	int ps[100000];
	int dp[100000];
	Solution(){
		//generate squares
		int s=1;
		memset(ps,0,sizeof(ps));
		while(s*s<100000){
			ps[s*s]=1;
			s++;
		}
	}
    int numSquares(int n) {
		if(ps[n])
			return 1;
		memset(dp,-1,sizeof(dp));
		for(int i=1;i<=n;i++){
			if(dp[i]!=-1)
				continue;
			if(ps[i]){
				dp[i]=1;
			}else{
				int minsq=n+1;
				for(int k=1;k*k<=i;k++){
					if(dp[i-k*k]+1<minsq)
						minsq=dp[i-k*k]+1;
				}
				dp[i]=minsq;
			}
		}
		return dp[n];
    }
};
int main(){
	Solution s;
	cout<<s.numSquares(65534)<<endl;
	return 0;
}
