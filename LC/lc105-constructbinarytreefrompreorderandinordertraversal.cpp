#include<vector>
#include<iostream>
#include "treenode.h"
using namespace std;
class Solution {
public:
	
	vector<int> pre;
	vector<int> in;
	TreeNode* build(int prel, int prer, int inl, int inr){
		if(prel==prer-1){
			return new TreeNode(pre[prel]);
		}
		if(prel>=prer)
			return NULL;
		TreeNode* root=new TreeNode(pre[prel]);
		int j;
		for(j=0;j+inl<inr;j++){
			if(in[j+inl]==pre[prel])
				break;
		}
		root->left=build(prel+1,prel+1+j,inl,inl+j);
		root->right=build(prel+j+1,prer,inl+j+1,inr);
		return root;
	}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		this->pre=preorder;
		this->in=inorder;
		return build(0,preorder.size(),0,preorder.size());
    }
};
int main(){
	Solution s;
	int arr[6]={1,2,4,5,3,6};
	int arr2[6]={4,2,5,1,3,6};
	vector<int>v1(arr,arr+6);
	vector<int>v2(arr2,arr2+6);
	
	s.buildTree(v1,v2);
	return 0;}
