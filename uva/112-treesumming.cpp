#include<iostream>
#include<sstream>
#include<set>
#include<ctype.h>
#include<stdlib.h>
using namespace std;

class Node{
	public:
	int val;
	Node* left;
	Node* right;
	bool builtleft;
	bool builtright;
	Node():val(0),left(NULL),right(NULL),builtleft(false),builtright(false){}
};

int ind;
set<int> res;

Node* build(string expr,int size, int sum){
	if(expr.at(ind)=='('){
		ind++;
		if(ind<size)
			return build(expr, size, sum);
		else 
			return NULL;
	}else if(expr.at(ind)==')'){
		ind++;
		return NULL;
	}else{
		int s,e;
		s=ind;
		while(expr.at(ind)<='9'&&expr.at(ind)>='0'||expr.at(ind)=='-')ind++;//group the integer
		e=ind;
		int val=atoi(expr.substr(s,e-s).c_str());
		Node* node=new Node();
		node->val=val;
		sum+=node->val;
		if(ind<size){
			if(!node->builtleft){
				node->left=build(expr,size,sum);
				node->builtleft=true;
			}
		}
		if(ind<size){
			if(!node->builtright){
				node->right=build(expr,size,sum);
				node->builtright=true;
			}
		}
		while(expr.at(ind)!=')')ind++;//one node ends, eat the tailing )
		ind++;
		if(node->builtleft &&node->left==NULL&& node->builtright && node->right==NULL)
			res.insert(sum);
		return node;
	}
}

string preproc(string in){
	string l;
	int i;
	for(i=0;i<in.length();i++){
		if(in.at(i)!=' '&&in.at(i)!='\n')
			l+=in[i];
	}
	return l;
}
int main(){
	string line, in;
	int prevtarget;
	bool tset=false;
	getline(cin,line);
	do{
		int target;
		stringstream ss(line.substr(0,line.find(' ')));
		if(!tset){
			ss>>target;
			prevtarget=target;
			tset=true;
			in.append(line.substr(line.find(' '),line.length()-line.find(' ')));
			continue;
		}else if(ss>>target){//new case start
			//handle prev case first
			in=preproc(in);
			res.clear();
			ind=0;
			Node* tree=build(in,in.length(),0);
			if(res.find(prevtarget)!=res.end()) cout<<"yes"<<endl;
			else cout<<"no"<<endl;
			//handle the current case
			prevtarget=target;
			in="";
			in.append(line.substr(line.find(' '),line.length()-line.find(' ')));
		}else{//multiline input
			in.append(line);
		}
	}while(getline(cin,line));
	in=preproc(in);
	res.clear();
	ind=0;
	Node* tree=build(in,in.length(),0);
	if(res.find(prevtarget)!=res.end())cout<<"yes"<<endl;
	else cout<<"no"<<endl;
}
