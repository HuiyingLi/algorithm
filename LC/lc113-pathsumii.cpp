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
	vector<int> path;
	vector<vector<int> >ans;
	int target;
	void dfs(TreeNode* node, int sum){
		sum+=node->val;
		if(!node->left&& !node->right){
			if(sum==target){
				ans.push_back(path);
			}
			return;
		}
		if(node->left!=NULL){
			path.push_back(node->left->val);
			dfs(node->left, sum);
			path.pop_back();
		}
		if(node->right!=NULL){
			path.push_back(node->right->val);
			dfs(node->right, sum);
			path.pop_back();
		}
			
	}
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
		if(root==NULL)
			return ans;
		target=sum;
		path.clear();
		ans.clear();
		path.push_back(root->val);
		dfs(root, 0);
		return ans;
    }
};

int main(){
	return 0;
}
