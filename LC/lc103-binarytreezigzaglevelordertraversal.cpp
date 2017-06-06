#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include "treenode.h"
using namespace std;

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
		vector<vector<int> >res;
		if(!root)
			return res;
		vector<TreeNode*> v;
		v.push_back(root);
		vector<int> ans;
		ans.push_back(root->val);
		res.push_back(ans);
		int lv=0;
		while(!v.empty()){
			vector<int> ans;
			vector<TreeNode*> tv; 
			for(int i=0; i<v.size(); i++){
				TreeNode* n=v[i];
				if(n->left!=NULL){
					tv.push_back(n->left);
					ans.push_back(n->left->val);
				}
				if(n->right!=NULL){
					tv.push_back(n->right);
					ans.push_back(n->right->val);
				}
			}
			if(tv.empty()) break;
			if(lv%2==1)
				reverse(ans.begin(),ans.end());
			res.push_back(ans);
			v=tv;
			lv++;
		}
	return res;
    }
};
int main(){return 0;}
