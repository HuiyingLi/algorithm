#include<vector>
#include<iostream>
#include<sstream>
using namespace std;
int ind=0;
int ll=0;
int rr=0;
vector<int> res;
class Node{
	public:
	int pos;
	int val;
	Node* left;
	Node* right;
	Node():pos(0),left(NULL),right(NULL){}
	void print(){
		cout << "val:"<<val<<"pos:"<<pos;
		if(left!=NULL) cout<<" left:"<<left->val;
		if(right!=NULL) cout<<" right:"<<right->val;
		cout<<endl;
	}
};

Node* build(int* in, int size, int offset){
	Node* node=new Node();
	if(in[ind]==-1){
		ind++;
		return NULL;
	}
	node->val=in[ind];
	node->pos=offset;

	ind++;
	if(ind<size)
		node->left=build(in, size, offset-1);
	if(ind<size)
		node->right=build(in, size, offset+1);
	if(offset<ll)
		ll=offset;
	if(offset>rr)
		rr=offset;
	return node;
}

void dfs(Node* tree){
//	tree->print();
	res[tree->pos-ll]+=tree->val;
	if(tree->left!=NULL)
		dfs(tree->left);
	if(tree->right!=NULL)
		dfs(tree->right);	
}
int main(){
	int in[10000];
	string line;
	int C=0;
	while(getline(cin,line)){
		stringstream ss(line);
		int x,n;
		n=0;
		while(ss>>x) in[n++]=x;
		if(n==1&&in[0]==-1)
		{
			break;
		}
		C++;
		ind=0;
		ll=0;
		rr=0;
		Node* tree=build(in, n, 0);
		vector<int> nres(rr-ll+1);
		res=nres;
//		for(vector<int>::const_iterator iter=res.begin();iter!=res.end(); iter++){
//			cout<<"ele"<<*iter<<endl;
//		}
		dfs(tree);
		cout<<"Case "<<C<<":"<<endl<<res[0];
		int i;
		for(i=1; i<res.size(); i++)
			cout<<" "<<res[i];
//		for(vector<int>::const_iterator iter=res.begin();iter!=res.end(); iter++){
//			cout<<*iter<<" ";
//		}
		cout<<endl<<endl;
	}
}
