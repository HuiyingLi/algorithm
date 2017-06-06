#include "treenode.h"
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> ans;
	void dfs(TreeNode* n){
		if(!n)
			return;
		
		dfs(n->left);
		ans.push_back(n->val);
		dfs(n->right);
	}
    vector<int> inorderTraversal(TreeNode* root) {
		ans.clear();
		dfs(root);
		return ans;
    }
};
int main(){return 0;}
