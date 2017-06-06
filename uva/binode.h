#include<iostream>
using namespace std;
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
