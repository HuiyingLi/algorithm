#include<iostream>
#include<vector>
#include "treenode.h"
using namespace std;

class Solution {
public:
	vector<int> n;
	TreeNode* build(int l, int r){
		if(l==r-1){
			return new TreeNode(n[l]);
		}
		if(l==r)
			return NULL;
		int mid=l+(r-l)/2;
		TreeNode* m=new TreeNode(n[mid]);
		m->left=build(l,mid);
		m->right=build(mid+1,r);

		return m;
	}
    TreeNode* sortedArrayToBST(vector<int>& nums) {
		this->n=nums;
		return build(0,nums.size());
    }
};
int main(){return 0;}
