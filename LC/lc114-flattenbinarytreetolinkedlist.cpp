#include<iostream>
#include "treenode.h"

using namespace std;

class Solution {
public:
	TreeNode* t;
	void dfs(TreeNode* n){
		if(n==NULL) return;
		t=n;
		if(n->left!=NULL){
			if(n->right!=NULL){
				TreeNode* tmp=n->right;
				n->right=n->left;
				n->left=NULL;
				dfs(n->right);
				t->right=tmp;
				dfs(t->right);
			}else{
			    //cout<<"exe";
				n->right=n->left;
				//cout<<n->right->val;
				n->left=NULL;
				dfs(n->right);
			}
		}else{
			dfs(n->right);	
		}
	}
    void flatten(TreeNode* root) {
        dfs(root);
    }
};
int main(){return 0;}
