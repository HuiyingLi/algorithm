#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int N,T;
vector<int> tree[100010];
/**
class pr{
	public:
	int id;
	int val;
	pr(int iid, int vval):id(iid),val(vval){}	
};

bool compare(const pr &p1, const pr & p2){
	return p1.val<p2.val;
}*/
int dfs(int node){
	if(tree[node].size()==0){
		return 1;
	}
	vector<int> children;
	for(int i=0;i<tree[node].size();i++){
		children.push_back(dfs(tree[node][i]));
	}
	sort(children.begin(),children.end());
	int res=0;
	for(int i=0;i<((T*tree[node].size()-1)/100+1);i++){
		res+=children[i];
	}
	return res;
}

int main(){
	scanf("%d%d",&N,&T);
	while(N!=0&&T!=0){
		for(int i=0;i<N;i++){
			int p;
			scanf("%d",&p);
			tree[p].push_back(i+1);
		}
		printf("%d\n",dfs(0));
		for(int i=0;i<N+5;i++)
			tree[i].clear();
		scanf("%d%d",&N,&T);
	}
	return 0;
}
