#include<vector>
#include<algorithm>
using namespace std;
/*    
class Solution {  
public:  
	bool canPartition(vector<int>& nums) {  
		int sum=0;
		for(int i=0;i<nums.size();i++)
			sum+=nums[i];
		if(sum&1) return false;  
		vector<int> dp(sum/2+1, 0);
		dp[0]=1; 
		for(int i = 0; i < nums.size(); i++)  
		{  
			for(int j = sum/2; j >= nums[i]; j--)  
				dp[j] = dp[j] || dp[j-nums[i]];  
		}  
		return dp[sum/2]; 
	}  
};  
*/
class Solution {
public:
    int T;
    int vis[300];
    vector<int> n;
    bool dfs(int s, int d){
        if(d>=n.size()||s>T){
            if(s==T)
                return true;
            return false;
        }
        for(int i=d;i<n.size();i++){
            if(dfs(s,d+1))
                return true;
            if(dfs(s+n[i],d+1))
                return true;
        }
        return false;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        if(sum%2==1)
            return false;
        T=sum/2;
        sort(nums.begin(),nums.end(),greater<int>() );
        n=nums;
        return dfs(0,0);
    }
};
int main(){
	int arr[4]={1,2,5};
	Solution s;
	vector<int> v(arr,arr+3);
	s.canPartition(v);
	return 0;
}
