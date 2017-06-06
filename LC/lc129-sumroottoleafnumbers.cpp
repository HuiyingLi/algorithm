#include<iostream>
#include<string.h>
#include<math.h>
#include<vector>
using namespace std;
struct TreeNode{
	public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode():val(0),left(NULL),right(NULL){}
};

class Solution {
public:
	vector<int> path;
	int sum;
	void dfs(TreeNode* node){
		if(!node->left&& !node->right){//is leaf
			int k=path.size();
			int num=0,c=1;
			for(int i=k-1;i>=0;i--){
				num+=path[i]*c;
				c*=10;
			}
			sum+=num;
			return;
		}
		if(node->left!=NULL){
			path.push_back(node->left->val);
			dfs(node->left);
			path.pop_back();
		}
		if(node->right!=NULL){
			path.push_back(node->right->val);
			dfs(node->right);
			path.pop_back();
		}
	}

    int sumNumbers(TreeNode* root) {
		if(!root)
			return 0;
		sum=0;
		path.clear();
		path.push_back(root->val);
		dfs(root);
		return sum;
    }
};

int main(){return 0;}
