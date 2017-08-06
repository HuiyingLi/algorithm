class Solution {
public:
    unordered_set<int> us;
    int vis[20010];
    int ans = 0;
    int arrayNesting(vector<int>& nums) {
        ans = 0;
        memset(vis, 0, sizeof(vis));
        for(int i=0; i < nums.size(); i++){
            if(vis[i]==1)
                continue;
            int k = i;
            int len=0;
            do{
                vis[k]=1;
                k = nums[k];
                len++;
            }while(k != i);
            if(len > ans)
                ans = len;
        }
        return ans;
    }
};
