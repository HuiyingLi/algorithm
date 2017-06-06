#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
class Solution {
public:
	vector<vector<int> >perm;
	vector<int> num;
	vector<int> pm;
	int vis[10000];
    void dfs(){
		bool more=false;
		for(int i=0;i<num.size();i++){
			if(!vis[i]){
				more=true;
				vis[i]=1;
				pm.push_back(num[i]);
				dfs();
				vis[i]=0;
				pm.pop_back();
			}
		}
		if(!more)
			perm.push_back(pm);
	}
	vector<vector<int> > permute(vector<int>& nums) {
		memset(vis,0,sizeof(vis));
		this->num=nums;
		dfs();
		return perm;
    }
};
int main(){
	Solution s;
	vector<int> in;
	in.push_back(1);
	in.push_back(2);
	in.push_back(3);
	s.permute(in);
	return 0;}
