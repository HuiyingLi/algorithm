#include<iostream>
#include<vector>
#include<stack>
#include"treenode.h"
//there is no test case for this problem
using namespace std;
class Solution {
public:
	TreeNode *p;
	TreeNode *q;
	TreeNode* ans;
	bool found;
	bool dfs(TreeNode* node){
		int ansof=0;
		if(found) return true;
		if(node==NULL) 
			return false;

		if(!found&&dfs(node->left))
			ansof++;
		if(!found&&dfs(node->right))
			ansof++;
		if(node==p||node==q)
			ansof++;
		if(ansof==2){
			if(!found){
				found=true;
				ans=node;
			}	
		}
		if(ansof>0)
			return true;
		return false;
	}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		this->p=p;
		this->q=q;
		this->found=false;
		this->ans=NULL;
		dfs(root);
		return ans;
    }

};int main(){
	TreeNode* n1=new TreeNode(1);
	TreeNode* n2=new TreeNode(2);
	TreeNode* n3=new TreeNode(3);
	TreeNode* n4=new TreeNode(4);
	TreeNode* n5=new TreeNode(5);
	TreeNode* n6=new TreeNode(6);
	TreeNode* n7=new TreeNode(7);
	TreeNode* n8=new TreeNode(8);
	TreeNode* n0=new TreeNode(0);
	n3->left=n5;
/*	n3->right=n1;
	n5->left=n6;
	n5->right=n2;
	n1->left=n0;
	n1->right=n8;
	n2->left=n7;
	n2->right=n4;
*/	Solution s;
	TreeNode* a=s.lowestCommonAncestor(n3, n8,n3);
	if(a!=NULL)
	cout<<a->val<<endl;
	else
	cout<<"NULL"<<endl;
	return 0;}
