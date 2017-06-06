#include<iostream>
#include<vector>
#include<string.h>
#include<queue>
#include<utility>
using namespace std;

class Solution {
public:
	int vis[10000];
	vector<int> G[10000];
	vector<int> G2[10000];
	vector<int> ans;
	bool bfs(queue<int> q, int N){
		int cnt=0;
		while(!q.empty()){
			int c=q.front();
			q.pop();
			cnt++;
			ans.push_back(c);
			for(int i=0;i<G[c].size();i++){
				bool sat=true;
				for(int j=0;j<G2[G[c][i]].size();j++){
					int dep=G2[G[c][i]][j];
					if(!vis[dep]&&!vis[G[c][i]]){
						sat=false;
						break;
					}
				}
				if(sat){
					q.push(G[c][i]);
					vis[G[c][i]]=1;
				}
			}
		}
		if(cnt!=N)
			return false;
		return true;
	}
    vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) {
		ans.clear();
		memset(vis, 0, sizeof(vis));
		for(int i=0;i<numCourses; i++){
			G[i].clear();
			G2[i].clear();
		}
		for(int i=0; i<prerequisites.size(); i++){
			pair<int,int> p=prerequisites[i];
			G[p.second].push_back(p.first);
			G2[p.first].push_back(p.second);
		}
		queue<int> q;
		for(int i=0; i<numCourses; i++){
			if(!G2[i].size()){
				q.push(i);
				vis[i]=1;
			}	
		}
		if(!bfs(q, numCourses))
			ans.clear();
		return ans;
    }
};
int main(){
	return 0;
}
