#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	vector<vector<int> > res;
	vector<int> ans;
	vector<int> n;
	void dfs(int d, bool tag){
		if(d==n.size()){
			res.push_back(ans);
			return;
		}
		if(n[d]==n[d+1]&&n[d-1]!=n[d]){
			dfs(d+1,false);
			ans.push_back(n[d]);
			dfs(d+1,true);
			ans.pop_back();	
		}else if(d>0n[d]==n[d-1]){
			if(tag){
				ans.push_back(n[d]);
				dfs(d+1,true);
				ans.pop_back();	
			}else{
				dfs(d+1,false);
			}
		}else{
			dfs(d+1,false);
			ans.push_back(n[d]);
			dfs(d+1,true);
			ans.pop_back();
		}
	}
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
		res.clear();
		ans.clear();
		n=nums;
		if(n.size()==0)
			return res;
		dfs(0, true);
		return res;
    }
};
int main(){return 0;}
