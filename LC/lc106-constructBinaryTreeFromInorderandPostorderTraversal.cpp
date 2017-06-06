#include<iostream>
#include<vector>
#include"treenode.h"
using namespace std;
class Solution {
public:
	vector<int> post;
	vector<int> in;
 	TreeNode* build(int postl, int postr, int inl, int inr){
		if(postl==postr-1){
			return new TreeNode(post[postl]);
		}
		if(postl>=postr)
			return NULL;
		TreeNode* root=new TreeNode(post[postr-1]);
		int j;
		for(j=0;j+inl<inr;j++){
			if(in[j+inl]==post[postr-1])
				break;
		}
		root->left=build(postl,postl+j,inl,inl+j);
		root->right=build(postl+j,postr-1,inl+j+1,inr);
		return root;
	}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		this->post=postorder;
		this->in=inorder;
		return build(0,postorder.size(),0,postorder.size());
    }
};
int main(){
int arr[8]={3,2,7,8,6,5,4,1};
	int arr2[8]={2,3,1,5,7,6,8,4};
	vector<int>v1(arr,arr+8);
	vector<int>v2(arr2,arr2+8);
Solution s;
s.buildTree(v2,v1);
return 0;}
