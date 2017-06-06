#include<iostream>
#include<string>
#include<stdlib.h>
#include<sstream>
#include<vector>
#include<map>
#include<math.h>
using namespace std;
string d2s(long, int);

class Node{
	public:
	int depth;
	long weight;
	Node* left;
	Node* right;
	Node():weight(0),left(NULL),right(NULL){}
};
string line;
int p=0;
int gd=-1;
map<string, int> count;
int total;
int maxg;
Node* build(int d){
	if(p>=line.length())
		return NULL;
	if(line[p]=='['){
		Node* rod=new Node();
		rod->depth=d;
		p++;
		rod->left=build(d+1);
		rod->right=build(d+1);
		while(p<line.length()&&line[p]!=','&&line[p]!=']')p++;
		p++;
		return rod;
	}
	else if(line[p]<='9'&&line[p]>='0'){
		int s,e;
		s=e=p;
		while(e<line.length()&&line[e]<='9'&&line[e]>='0')e++;
		stringstream ss(line.substr(s,e-s));
		long w;
		ss>>w;
		//long w=atoi(line.substr(s,e-s).c_str());
		while(p<line.length()&&line[p]!=','&&line[p]!=']')p++;
		p++;
		Node *l=new Node();
		l->depth=d;
		l->weight=w;
		total++;
		if(gd==-1){
			gd=d;
		}
		
	//	double dw=w*pow(2,d-gd);
		string dw=d2s(w,d-gd);
		if(count.find(dw)==count.end()){
			count.insert(std::pair<string,int>(dw,1));
		}else{
			count.find(dw)->second++;//count.find(dw)->second+1));
		}
		//cout<<"find dw="<<dw<<" freq:"<<count.find(dw)->second<<endl;
		if(count.find(dw)->second>maxg)
			maxg=count.find(dw)->second;
		return l;
	}
}

string d2s(long w, int powx){
	if(powx>=0){
		long dw=w*pow(2,powx);
		stringstream ss;
		ss<<dw;
		string res=ss.str();
		return res;
	}
	else{
		while(powx<0&&w/2>0&&w%2==0){
			w/=2;
			powx++;
		}
		if(powx>=0){
			long dw=w*pow(2,powx);
			stringstream ss;
			ss<<dw;
			string res=ss.str();
			return res;
		}else{
			stringstream ss;
			ss<<w;
			stringstream ss1;
			ss1<<pow(2,powx*-1);
			string res=ss.str()+"/"+ss1.str();
			return res;
		}
	}
}

void print(Node *t){
	if(t->weight!=0)
		cout<<"depth:"<<t->depth<<"leaf:"<<t->weight<<endl;
	else{
		cout<<"depth:"<<t->depth;
		cout<<"left:"<<endl;
		print(t->left);
		cout<<"right"<<endl;
		print(t->right);
	}
}
int main(){
	int N;
	getline(cin,line);
	stringstream ss(line);
	ss>>N;
	for(int i=0;i<N;i++){
		getline(cin,line);
		p=0;
		Node* tree=build(0);
		cout<<total-maxg<<endl;
		maxg=0;
		total=0;
		gd=-1;
		p=0;
		count.clear();
//		print(tree);
/**
		for(int i=0;i<17;i++){
			if(leaves[i].size()!=0){
				cout<<"depth "<<i<<endl;
				for(int j=0;j<leaves[i].size();j++) cout<<leaves[i][j]<<" ";
				cout<<endl;
			}
		}
**/
	}
	return 0;
}


