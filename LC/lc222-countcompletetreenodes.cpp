#include<iostream>
#include<math.h>
using namespace std;

struct TreeNode {
 int val;
 TreeNode *left;
 TreeNode *right;
 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution{
public:
	int depth;
	int k; 
	bool dfs(TreeNode* node, int d){
		if(d==depth-2){
			if(node->left!=NULL)
				k++;
			else
				return false;
			if(node->right!=NULL)
				k++;
			else
				return false;
			return true;
		}
		if(node->left!=NULL){
			if(!dfs(node->left, d+1))
				return false;
		}
		if(node->right!=NULL){
			if(!dfs(node->right,d+1))
				return false;
		}
		return true;
	}
	int countNodes(TreeNode* root){
	    if(!root)
			return 0;
		TreeNode *node=root;
		while(node!=NULL){
			node=node->left;
			depth++;
		}
		if(depth==1)
		    return 1;
//		cout<<"depth:"<<depth<<endl;
		k=0;
		dfs(root,0);
		
//		cout<<"k:"<<k<<endl;
		return pow(2,depth-1)-1+k;
	}
};

int main(){return 0;}
