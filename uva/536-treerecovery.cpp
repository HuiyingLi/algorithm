#include<iostream>
#include<string>
using namespace std;

class Node{
	public:
	char val;
	Node* left;
	Node* right;
	Node():val(0),left(NULL),right(NULL){}
};
string preord;
string inord;

Node* build(int L, int R){
	if(L>R)
		return NULL;
	char root;
	int i=-1;
	for(int k=0;k<preord.length();k++){
		for(int j=L;j<=R;j++){
			if(preord[k]==inord[j]){
				root=preord[k];
				i=j;
				break;
			}
		}
		if(i!=-1)break;
	}
	Node* node=new Node();
	//find root in inord
	node->val=root;
	node->left=build(L,i-1);
	node->right=build(i+1,R);
	return node;
}

void postord(Node* tree){
	if(tree->left!=NULL)
		postord(tree->left);
	if(tree->right!=NULL)
		postord(tree->right);
	cout<<tree->val;
}
int main(){
	string line;
	while(getline(cin,line)){
		int i;
		for(i=0;i<line.length();i++){
			if(line[i]==' ') break;
		}
		preord=line.substr(0,i);
		inord=line.substr(i+1,line.length()-i-1);
		Node* tree =build(0,preord.length()-1);
		postord(tree);
		cout<<endl;
	}
}

