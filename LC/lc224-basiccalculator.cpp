#include<string>
#include<stack>
#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
public:
	bool evaluated;
	string sign;
	int n1, n2;
	bool vis1, vis2;
	bool empty(){
		if(!vis1&&!vis2&&sign=="")
			return true;
		return false;
	}
	node():n1(-1),n2(-1),sign(""),evaluated(false),vis1(false),vis2(false){}
	int eval(){
		this->evaluated=true;
		if(sign==""){
			return n1;
		}
		if(sign=="-")
			return n1-n2;
		else
			return n1+n2;
	}
};

class Solution {

public:
    int calculate(string s) {
		if(s=="") return 0;
		int i=0;
		node* current=new node();
		stack<node*> stk;	
		while(i<s.length()){
			if(s[i]>='0'&&s[i]<='9'){
				int b=i;
				while(s[i]>='0'&&s[i]<='9')
					i++;
				int v=atoi(s.substr(b,i).c_str());
				if(current->sign==""){
					current->n1=v;
					current->vis1=true;
				}else{
					current->n2=v;
					current->vis2=true;
					int ans=current->eval();
					current=new node();
		            current->n1=ans;
					current->vis1=true;
		
				}
			}else if(s[i]==' '){
			    i++;
			}else if(s[i]=='-'||s[i]=='+'){
				current->sign=s[i];
				if(!current->vis1){
					current->n1=0;
					current->vis1=true;
				}
				i++;
			}else if(s[i]=='('){
				stk.push(current);
				current=new node();
				i++;
			}else if(s[i]==')'){
				//if there is an incomplete current node e.g. (4)
				if(!current->evaluated&&!current->empty()){
					int ev=current->eval();
					current=new node();
					if(!stk.empty()&&!stk.top()->empty()){
						node* t=stk.top();
						if(t->sign==""){
							t->n1=ev;
							t->vis1=true;
						}
						else{
							t->n2=ev;
							t->vis2=true;
						}
					}else{
						current->n1=ev;
						current->vis1=true;
					}
				}
				node* t=stk.top();
				stk.pop();
				if(t->empty()){
					i++;
					continue;
				}
				int ans=t->eval();
					if(!current->vis1){
						current->n1=ans;
						current->vis1=true;
					}
					else{
						current->n2=ans;
						current->vis2=true;
					}
				i++;
			}
		}
		return current->n1;
    }
};
int main(){
//	string in="(3-(4-1))-(0-9)+(6+8)";
	string in="7-((5-6)-(6-8)+1)";
	Solution s;
	cout<<s.calculate(in);
return 0;}
