class Solution {
public:
    int vis[100];
    vector<vector<int> > res;
    vector<int> ans;
    string sans;
    vector<int> nums;
    unordered_set<string> pas;
    void dfs(int d){
    //    if(d==nums.size()){
    //        if(ans.size()>1)
    //            res.push_back(ans);
    //        return;
    //    }
        for(int i=d;i<nums.size();i++){
            if(ans.size()==0||nums[i]>=ans[ans.size()-1]){
                ans.push_back(nums[i]);
                string tmp=sans;
                sans+=to_string(nums[i])+",";
                if(ans.size()>1) {
                    if(pas.find(sans)==pas.end()){
                        res.push_back(ans);
                        pas.insert(sans);
                    }
                }
                dfs(i+1);
                ans.pop_back();
                sans=tmp;
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        res.clear();
        memset(vis,0,sizeof(vis));
        this->nums=nums;
        dfs(0);
        return res;
    }
};
