#include<iostream>
#include<string>
#include<sstream>
#include<set>

using namespace std;

int mymin=10000000;
set<int> leaves;

template <typename T>
class Binode{
    public:
    bool have_value;
    T val;
    Binode *left, *right;

    Binode():have_value(false),left(NULL),right(NULL){}
	void print(){
		cout<<"have_value:"<<have_value<<" value:"<<val;
		if(left!=NULL){cout<<" left:" <<left->val;}
		if(right!=NULL){cout<<" right:" <<right->val;}
		cout<<endl;
	}
};

Binode<int>* build(int* in, int* post, int in_l, int in_r, int p_l, int p_r){
	if(in_l>in_r)
		return NULL;
	Binode<int> *root=new Binode<int>();
	int rootnode=post[p_r];
	root->have_value=true;
	root->val=rootnode;
	int root_ind=-1;
	int i;
	for(i=in_l;i<=in_r;i++){
		if(in[i]==rootnode){
			root_ind=i;
			break;
		}
	}
	int inL1=in_l;
	int inR1=root_ind-1;
	int inL2=root_ind+1;
	int inR2=in_r;
		
	int pL1=p_l;
	int pR1=p_l+inR1-inL1;
	int pL2=p_l+inR1-inL1+1;
	int pR2=p_r-1;

	Binode<int>* lchild=build(in, post, inL1, inR1, pL1, pR1);
	Binode<int>* rchild=build(in, post, inL2, inR2, pL2, pR2);
  	root->left= lchild;
	root->right= rchild;

	return root;
}

void dfs(Binode<int>* root, int sum){
	sum+=root->val;
	if(root->left!=NULL){
		dfs(root->left, sum);
	}
	if(root->right!=NULL){
		dfs(root->right,sum);
	}
	if(root->left==NULL && root->right==NULL){
		if(sum<mymin){
			leaves.clear();
			leaves.insert(root->val);
			mymin=sum;
		}else if(sum==mymin){
			leaves.insert(root->val);
		}
	}
}

int main(){
	const int MAXL=10000;
   	string line;
	int in[MAXL];
	int post[MAXL];
	int i=0;
	while(getline(cin, line)){
		if(i!=0&&i%2==1){
			stringstream ss(line);
			int x,n;
			n=0;
			while(ss>>x) post[n++]=x;
			Binode<int>* tree=build(in,post,0,n-1,0,n-1);
			dfs(tree, 0);
			cout<<*leaves.begin()<<endl;
			mymin=10000000;
			leaves.clear();
		}else{
			stringstream ss(line);
			int x,n;
			n=0;
			while(ss>>x) in[n++]=x;
		}
		i++;
	}
	
    return 0;	
}
