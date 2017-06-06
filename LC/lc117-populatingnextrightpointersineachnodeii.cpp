#include<iostream>
#include<vector>
using namespace std;
struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    vector<TreeLinkNode*> v;
    void dfs(TreeLinkNode* r, int d){
        if(r==NULL)
            return;
        if(d>=v.size()){
            v.push_back(r);
        }else{
            v[d]->next=r;
            v[d]=r;
        }
        dfs(r->left,d+1);
        dfs(r->right,d+1);
    }
    void connect(TreeLinkNode *root) {
		if(root==NULL) return;
		dfs(root,0);
    }
};
int main(){
	TreeLinkNode* t1=new TreeLinkNode(0);
	TreeLinkNode* t2=new TreeLinkNode(1);
	TreeLinkNode* t3=new TreeLinkNode(2);
	TreeLinkNode* t4=new TreeLinkNode(3);
	TreeLinkNode* t5=new TreeLinkNode(4);
	TreeLinkNode* t6=new TreeLinkNode(5);
	t1->left=t2;
	t2->right=t3;
	t1->right=t4;
	t4->left=t5;
	t4->right=t6;
	Solution s;
	s.connect(t1);

return 0;}
