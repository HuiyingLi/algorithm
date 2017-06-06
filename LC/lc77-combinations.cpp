#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<int> >ans;
	vector<int> comb;
	int vis[1000];
	int n,k;
	void dfs(int d){
		if(d>k){
			for(int i=0;i<comb.size();i++)
				cout<<comb[i]<<" ";
			cout<<endl;
			ans.push_back(comb);
			return;
		}
		int low=0;
		if(comb.size()>0)
			low=comb[comb.size()-1];	
		for(int i=1;i<=n;i++){
			if(!vis[i]&&i>low){
				comb.push_back(i);
				vis[i]=1;
				dfs(d+1);
				comb.pop_back();
				vis[i]=0;
			}
		}
	}
    vector<vector<int> > combine(int n, int k) {
		memset(vis,0,sizeof(vis));
		ans.clear();
		comb.clear();
		this->n=n;
		this->k=k;
		dfs(1);
		return ans;
    }
};
int main(){
	Solution s;
	s.combine(4,0);
	return 0;}
