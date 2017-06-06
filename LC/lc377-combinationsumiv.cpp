class Solution {
public:

    int tgt;
    vector<int> n;
    unordered_map<int,int> dp;
    int search(int sum){
//        cout<<"sum"<<sum<<endl;
        if(sum<0)
            return 0;
        if(sum==0)
            return 1;
        int ans=0;
        if(dp.find(sum)!=dp.end())
            return dp[sum];
        for(int i=0;i<n.size();i++){
            ans+=search(sum-n[i]);
        }
        dp[sum]=ans;
//        cout<<"put:"<<sum<<","<<ans<<endl;
        return ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        tgt=target;
        n=nums;
        dp.clear();
//        cout<<"exe";
        return search(target);
    }
};
