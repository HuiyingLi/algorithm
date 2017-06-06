#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int vis[10000];
	vector<vector<int> > res;
	vector<int> ans;
	vector<int> cand;
	int target;
	void dfs(int sum, int d){
		if(sum==target){
			res.push_back(ans);
			return;
		}
		int prev=-1;
		for(int i=d;i<cand.size();i++){
			if(vis[i])
				continue;
			if(cand[i]==prev)
				continue;
			if(sum+cand[i]<=target){
				vis[i]=1;
				ans.push_back(cand[i]);
				dfs(sum+cand[i], i);
				ans.pop_back();
				vis[i]=0;
				prev=cand[i];
			}else{
				break;
			}
		}
	}
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(),candidates.end());
		this->cand=candidates;
		this->target=target;
		res.clear();
		ans.clear();
		dfs(0,0);
		return res;
    }
};

int main(){return 0;}
