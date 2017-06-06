#include<iostream>
#include<vector>
#include<stdlib.h>
#include<string>
#include"treenode.h"
#include<stack>
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
		}
		if(root->right!=NULL){
			s+=dfs(root->right);
		}
		return s+")";
	}
/** Will cause stack overflow during recursive calls on leetcode.
	vector<TreeNode*> dfs2(string s){
		vector<TreeNode*> res;
		int i=0;
		while(i<s.length()){
			if((s[i]>='0'&&s[i]<='9')||s[i]=='-'){
				int b=i;
				while((s[i]>='0'&&s[i]<='9')||s[i]=='-')
					i++;
				int val=atoi(s.substr(b,i).c_str());
				TreeNode* t=new TreeNode(val);
				res.push_back(t);
			}else if(s[i]=='('){
				i++;
				vector<TreeNode*> tl=dfs2(s.substr(i,s.length()-i));
				TreeNode* r=res[res.size()-1];
				for(int j=0;j<tl.size()-1;j++){
					if(tl[j]->val<r->val){
						r->left=tl[j];
					}else{
						r->right=tl[j];
					}
				}
				i+=tl[tl.size()-1]->val+1;
			}else if(s[i]==')'){
				TreeNode* t=new TreeNode(i);
				res.push_back(t);
				return res;
			}else{
				i++;
			}
		}
		return res;
	}
**/
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
				if(c->val<=p->val)
					p->left=c;
				else
					p->right=c;
				i++;
			}else if(s[i]=='#'){
				if(!stk.empty()){
					TreeNode* p=stk.top();
					if(t->val<=p->val)
						p->left=t;
					else
						p->right=t;
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
	t=s.deserialize("0(-50(-100(-110#)-22(-30#-15#))50(25(12#)))");
	cout<<s.serialize(t)<<endl;
	t=s.deserialize("8(5(3#6#)10(13#))");
	cout<<s.serialize(t)<<endl;
	t=s.deserialize("5(2(4#)6(7#))");
	cout<<s.serialize(t)<<endl;
return 0;
}
