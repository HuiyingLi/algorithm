class Solution {
public:
    int N;
    long sum;
    int S;
    vector<int> nums;
    map<int, int> dp[22];
    int dfs(int d){
        if(d==N){
            if(sum==S)
                return 1;
            else
                return 0;
        }
        sum+=nums[d];
        int a=0, b=0;
        if(dp[d].find(sum)!=dp[d].end()){
            a=dp[d][sum];
        }else{
            a=dfs(d+1);
            dp[d][sum]=a;
            
        }
        sum-=nums[d];
        sum-=nums[d];
        if(dp[d].find(sum)!=dp[d].end()){
            b=dp[d][sum];
        }else{
            b=dfs(d+1);
            dp[d][sum]=b;
            
        }
        sum+=nums[d];
        return a+b;
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        this->S=S;
        sum=0;
        this->nums=nums;
        this->N=nums.size();
        for(int i=0;i<22;i++){
            dp[i].clear();
        }
        int ans=dfs(0);
        return ans;
    }
};
