#include<iostream>
#include"treenode.h"
#include<vector>
#include<string.h>
using namespace std;
class Solution {
public:
	vector<TreeNode*> res;
	int vis[1000];
	TreeNode* root;
	int N;
	void dfs(TreeNode* n, int l, int r, int k){
//		if(k==N){
//			res.push_back(root);
//			return;
//		}
//        cout<<n->val;
		for(int i=l;i<n->val;i++){
			if(!vis[i]){
				vis[i]=1;
				n->left=new TreeNode(i);
				dfs(n->left,l,n->val, k+1);
			//	delete n->left;
			//	n->left=NULL;
				vis[i]=0;
			}
		}
		for(int i=n->val+1;i<r;i++){
			if(!vis[i]){
				vis[i]=1;
				n->right=new TreeNode(i);
				dfs(n->right,n->val+1,r,k+1);
			//	delete n->right;
			//	n->right=NULL;
				vis[i]=0;
			}
		}
		res.push_back(root);
	}
    vector<TreeNode*> generateTrees(int n) {
		res.clear();
		memset(vis,0,sizeof(vis));
		N=n;
		for(int i=1;i<n+1;i++){
			root=new TreeNode(i);
			dfs(root,1,n+1,1);
			//delete root;
		//	root=NULL;
		}
		return res;
    }

};
int main(){
	Solution s;
	s.generateTrees(3);
	
return 0;}
