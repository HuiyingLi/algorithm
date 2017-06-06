#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

class Solution {
public:
	int n,k;
	vector<vector<int> >res;
	vector<int> ans;
	int vis[100];
	void dfs(int sum, int d){
		if(ans.size()==k){
			if(sum==n){
				res.push_back(ans);
			}
			return;
		}
		for(int i=d; i<=9;i++){
			if(vis[i])
				continue;
			if(sum+i<=n){
				vis[i]=1;
				ans.push_back(i);
				dfs(sum+i,i+1);
				vis[i]=0;
				ans.pop_back();
			}else{
				break;
			}
		}
	}
	vector<vector<int> > combinationSum3(int k, int n) {
		this->k=k;
		this->n=n;
		ans.clear();
		res.clear();
		memset(vis,0,sizeof(vis));
		dfs(0,1);
		return res;
    }
};

int main(){
	Solution s;
	s.combinationSum3(2,18);
	return 0;}
