#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<int> cand;
	int target;
	vector<int> res;
	vector<vector<int> >ans;
	void dfs(int sum, int d){
		if(sum==target){
			ans.push_back(res);
			return;
		}
		for(int i=d;i<cand.size();i++){
			if(sum+cand[i]<=target){
				res.push_back(cand[i]);
				dfs(sum+cand[i], i);
				res.pop_back();
			}else{break;}
		}
	}
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(),candidates.end());
		this->cand=candidates;
		this->target=target;
		res.clear();
		ans.clear();
		dfs(0, 0);
		return ans;
    }
};
int main(){
	Solution s;
	vector<int> c;
	c.push_back(2);
	c.push_back(3);
	c.push_back(6);
	c.push_back(7);
	s.combinationSum(c,7);
	return 0;}
