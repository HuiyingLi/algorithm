#include<iostream>
#include"treenode.h"
#include<stack>
#include<stdlib.h>
using namespace std;

class Codec{
public:
	string dfs(TreeNode* root){
		string s="";
		if(root==NULL)
			return s;
		s+=to_string(root->val);
		if(root->left==NULL&&root->right==NULL){
			return s+"#";
		}
		s+="(";
		if(root->left!=NULL){
			s+=dfs(root->left);
		}else{
			s+="$";
		}
		if(root->right!=NULL){
			s+=dfs(root->right);
		}else{
			s+="$";
		}
		return s+")";
	}
	string serialize(TreeNode* root){
		return dfs(root);
	}
	TreeNode* deserialize(string s){	
		if(s.length()==0)
			return NULL;
		stack<TreeNode*> stk;
		TreeNode* t;
		TreeNode* root;
		int val;
		int i=0;
		while(i<s.length()){
			if((s[i]>='0'&&s[i]<='9')||s[i]=='-'){
				int b=i;
				while((s[i]>='0'&&s[i]<='9')||s[i]=='-')
					i++;
				val=atoi(s.substr(b,i-b).c_str());
				t=new TreeNode(val);
			}else if(s[i]=='$'){
				if(!stk.empty()){
					TreeNode* p=stk.top();
					if(p->left==NULL){
						p->left=p;
					}
				}
				i++;
			}else if(s[i]=='('){
				stk.push(t);
				i++;
			}else if(s[i]==')'){
				TreeNode* c=stk.top();
				stk.pop();
				if(stk.empty()){
					root=c;
					break;	
				}
				TreeNode* p=stk.top();
				if(p->left!=NULL){
					p->right=c;
					if(p->left==p)
						p->left=NULL;
				}else{
					p->left=c;
				}
				i++;
			}else if(s[i]=='#'){
				if(!stk.empty()){
					TreeNode* p=stk.top();
					if(p->left!=NULL){
						p->right=t;
						if(p->left==p)
							p->left=NULL;
					}else{
						p->left=t;
					}
					i++;
				}else{
					root=t;
					break;
				}
			}
		}
		return root;
	}

};
int main(){
	Codec s;

	TreeNode* t;
	t=s.deserialize("3(4(1#$)5($6#))");
	cout<<s.serialize(t)<<endl;
	t=s.deserialize("1(2#3(4(6#$)5($7#)))");
	cout<<s.serialize(t)<<endl;
//	t=s.deserialize("5(2(4#)6(7#))");
//	cout<<s.serialize(t)<<endl;
	return 0;}
