#include<iostream>
#include<fstream>
#include<vector>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int target;
	bool dfs(TreeNode* node, int sum){
		sum+=node->val;
		if(!node->left&& !node->right){
			if(sum==target)
				return true;
		}
		if(node->left!=NULL){
			if(dfs(node->left, sum))
				return true;
		}
		if(node->right!=NULL){
			if( dfs(node->right, sum))
				return true;
		}
		return false;	
	}
    bool hasPathSum(TreeNode* root, int sum) {
		if(root==NULL)
			return false;
		target=sum;
		return dfs(root, 0);
    }
};

int main(){
	return 0;
}
